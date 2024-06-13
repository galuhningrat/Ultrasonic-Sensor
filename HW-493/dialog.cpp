#include "dialog.h"
#include "ui_dialog.h"
#include <QtMath>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , r(445.0) // needle radius (pixels)
    , angleOffset(0.05) // needle angle offset (rad)
    , ui(new Ui::Dialog)
    , laserActive(false)
    , autoMode(false)
{
    ui->setupUi(this);

    // Load bg image
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    pix = QPixmap(":/src/radar.png");
    scene->addPixmap(pix);

    // Set up QSerialPort
    arduino = new QSerialPort;
    arduino_is_available = false;
    arduino_port_name = "COM9";

    // Initialize needle at 0 degrees
    QPen blackpen(Qt::black);
    QBrush graybrush(Qt::gray);
    t_up = angleOffset;
    t_lo = -angleOffset;
    triangle.append(QPointF(r * qCos(t_up) + 505, -r * qSin(t_up) + 495));
    triangle.append(QPointF(505, 495));
    triangle.append(QPointF(r * qCos(t_lo) + 505, -r * qSin(t_lo) + 495));
    needle = scene->addPolygon(triangle, blackpen, graybrush);
    needle->setOpacity(0.30);

    // Check which port the Arduino is on
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == arduino_uno_vendorID) {
                if (serialPortInfo.productIdentifier() == arduino_uno_productID) {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                    qDebug() << "Port available!";
                }
            }
        }
    }

    // Setup port if available
    if (arduino_is_available) {
        // Open and configure port
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        // Slot for updating value
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    } else {
        // Give a message
        QMessageBox::warning(this, "Port error", "Couldn't find Arduino");
    }

    autoTimer = new QTimer(this); // Initialize timer
    connect(autoTimer, &QTimer::timeout, this, &Dialog::updateServoAuto);

    laserTimer = new QTimer(this); // Initialize laser timer
    connect(laserTimer, &QTimer::timeout, this, &Dialog::handleLaserActivation);

    /* resumeTimer = new QTimer(this); // Timer to resume operations
    connect(resumeTimer, &QTimer::timeout, this, &Dialog::resumeOperation); */
}

void Dialog::readSerial() {
    // Read data from serial port
    serialData.append(arduino->readAll());

    // Check if we have a complete message (terminated by '\n')
    if (serialData.endsWith('\n')) {
        // Process the complete message
        QString dataString = QString::fromStdString(serialData.toStdString()).trimmed();
        serialData.clear();

        qDebug() << "Raw data received:" << dataString; // Debugging: Print raw data

        QStringList dataList = dataString.split(',');

        if (dataList.size() == 2) {
            bool ok1, ok2;
            float angle = dataList[0].toFloat(&ok1);
            float distance = dataList[1].toFloat(&ok2);

            if (ok1 && ok2) {
                qDebug() << "Parsed angle:" << angle;

                // Ensure distance is within 0-500 cm
                if (distance >= 0 && distance <= 500) {
                    qDebug() << "Parsed distance:" << distance;

                    // Update range label in GUI
                    QString rangeText = QString::number(distance, 'f', 2) + " cm";
                    ui->range->setText(rangeText);

                    // Update detection point only if not pausing
                    if (!laserActive) {
                        updateDetectionPoint(angle, distance);
                    }

                    // Check distance for laser activation
                    if (distance < 50 && !laserActive) { // Activate laser if distance < 50 cm
                        laserActive = true;
                        laserTimer->start(2000); // Start laser timer for 2 seconds
                        // Save current auto mode and slider state
                        previousAutoMode = autoMode;
                        previousSliderState = ui->verticalSlider->isEnabled();

                        if (autoMode) {
                            autoTimer->stop(); // Stop auto timer
                        }
                        setSliderEnabled(false); // Disable the slider
                        qDebug() << "Laser turned on"; // Debugging: Print laser on status
                        updateLaserStatus("Laser: On"); // Update GUI to show laser is on
                    }

                    // Update angle label in GUI
                    QString angleText = QString::number(angle, 'd', 0);
                    ui->angle->setText(angleText);
                } else {
                    qDebug() << "Error: Distance out of range" << distance;
                }
            } else {
                qDebug() << "Error: Incorrect data format received" << dataString;
            }
        } else {
            qDebug() << "Error: Incorrect data format received" << dataString;
        }
    }
}

void Dialog::setSliderEnabled(bool enabled) {
    ui->verticalSlider->setEnabled(enabled);
}

void Dialog::handleLaserActivation() {
    laserActive = false;
    laserTimer->stop();
    qDebug() << "Laser turned off"; // Debugging: Print laser off status
    updateLaserStatus("Laser: Off"); // Update GUI to show laser is off

    // Restore previous auto mode and slider state
    if (previousAutoMode) {
        autoTimer->start(500); // Resume auto timer
    }
    setSliderEnabled(previousSliderState); // Re-enable the slider if it was previously enabled
}

void Dialog::updateServo(QString command) {
    if (arduino->isWritable()) {
        arduino->write(command.toStdString().c_str());
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

void Dialog::updateServoAuto() {
    static int angle = 0;
    static bool increasing = true;

    if (increasing) {
        angle += 5;
        if (angle >= 180) {
            angle = 180;
            increasing = false;
        }
    } else {
        angle -= 5;
        if (angle <= 0) {
            angle = 0;
            increasing = true;
        }
    }

    updateServo(QString::number(angle) + "\n");
    ui->verticalSlider->setValue(angle); // Update slider position
}

void Dialog::updateDetectionPoint(float angle, float distance) {
    qDebug() << "Updating detection point at angle:" << angle << "distance:" << distance; // Debugging: Print detection point
    float radAngle = qDegreesToRadians(angle);
    float x = distance * qCos(radAngle);
    float y = distance * qSin(radAngle);

    QGraphicsRectItem* point = scene->addRect(505 + x, 495 - y, 3, 3, QPen(Qt::red), QBrush(Qt::red));
    detectionPoints.append(point);

    // Update the needle position
    float t_up = radAngle + angleOffset;
    float t_lo = radAngle - angleOffset;
    QPolygonF newTriangle;
    newTriangle.append(QPointF(r * qCos(t_up) + 505, -r * qSin(t_up) + 495));
    newTriangle.append(QPointF(505, 495));
    newTriangle.append(QPointF(r * qCos(t_lo) + 505, -r * qSin(t_lo) + 495));
    needle->setPolygon(newTriangle);

    // Clear old detection points
    clearOldDetectionPoints();
}

void Dialog::clearOldDetectionPoints() {
    // Remove old points from the scene
    while (detectionPoints.size() > 50) { // Keep the last 50 points
        QGraphicsRectItem* point = detectionPoints.takeFirst();
        scene->removeItem(point);
        delete point;
    }
}

void Dialog::on_button0_clicked() {
    updateServo("0\n");
    ui->verticalSlider->setValue(0);
}

void Dialog::on_button90_clicked() {
    updateServo("90\n");
    ui->verticalSlider->setValue(90);
}

void Dialog::on_button180_clicked() {
    updateServo("180\n");
    ui->verticalSlider->setValue(180);
}

void Dialog::on_verticalSlider_valueChanged(int value) {
    updateServo(QString::number(value) + "\n");
}

void Dialog::on_button45_clicked() {
    updateServo("45\n");
    ui->verticalSlider->setValue(45);
}

void Dialog::on_button135_clicked() {
    updateServo("135\n");
    ui->verticalSlider->setValue(135);
}

void Dialog::on_button_auto_clicked() {
    autoMode = !autoMode;

    if (autoMode) {
        autoTimer->start(500); // Update servo every 500 ms
        ui->button_auto->setText("Stop Auto");
    } else {
        autoTimer->stop();
        ui->button_auto->setText("Start Auto");
    }
}

void Dialog::resumeOperation() {
    laserActive = false;
    qDebug() << "Resuming normal operation"; // Debugging: Print resume status
    updateLaserStatus("Laser: Off"); // Ensure laser status is off when resuming
}

void Dialog::updateLaserStatus(const QString &status) {
    ui->textEdit->setPlainText(status);
}

Dialog::~Dialog() {
    if (arduino->isOpen()) {
        arduino->close();
    }
    delete ui;
}

#include "dialog.h"
#include "ui_dialog.h"
#include <QtMath>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , r(445.0) // needle radius (pixels)
    , angleOffset(0.05) // needle angle offset (rad)
    , ui(new Ui::Dialog)
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
}

void Dialog::readSerial()
{
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

            if (ok1 && ok2 && distance >= 0 && distance <= 500) { // Ensure distance is within 0-500 cm
                qDebug() << "Parsed angle:" << angle << "Parsed distance:" << distance;
                updateDetectionPoint(angle, distance);

                // Update range label in GUI
                QString rangeText = QString::number(distance, 'f', 2) + " cm";
                ui->range->setText(rangeText);
            } else {
                qDebug() << "Error: Invalid data received or out of range" << dataString;
            }
        } else {
            qDebug() << "Error: Invalid data format" << dataString;
        }
    }
}

void Dialog::updateDetectionPoint(float angle, float distance)
{
    // Clear old detection points first
    clearOldDetectionPoints();

    if (distance < 500) {  // Ensure distance is within 500 cm
        float radius = distance * 0.9; // Adjust the scaling factor for the visualization
        float x = radius * qCos(qDegreesToRadians(angle));
        float y = radius * qSin(qDegreesToRadians(angle));
        float xT = x + 505;
        float yT = -1 * y + 495;

        QPen blackpen(Qt::black);
        QBrush graybrush(Qt::gray);
        rect = scene->addRect(xT, yT, 12, 12, blackpen, graybrush);
        rect->setOpacity(0.75);
        detectionPoints.append(static_cast<QGraphicsRectItem*>(rect)); // Add new detection point to the list

        qDebug() << "Updated detection point at x:" << xT << "y:" << yT; // Debugging: Print coordinates of detection point
    } else {
        qDebug() << "Distance out of range:" << distance; // Debugging: Print distance if out of range
    }
}

void Dialog::clearOldDetectionPoints()
{
    // Clear all old detection points from the scene
    foreach (QGraphicsRectItem* item, detectionPoints) {
        scene->removeItem(item);
        delete item;
    }
    detectionPoints.clear();
}

void Dialog::updateServo(QString command)
{
    // Update servo angle
    currAngle = qDegreesToRadians(command.toFloat());
    t_up = currAngle + angleOffset;
    t_lo = currAngle - angleOffset;
    triangle[0] = QPointF(r * qCos(t_up) + 505, -r * qSin(t_up) + 495);
    triangle[2] = QPointF(r * qCos(t_lo) + 505, -r * qSin(t_lo) + 495);
    needle->setPolygon(triangle);

    if (arduino->isWritable()) {
        QString message = command + "\n";
        arduino->write(message.toStdString().c_str());
    } else {
        qDebug() << "Could not write to serial";
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_button0_clicked()
{
    servoSetting = "0";
    ui->angle->setText(servoSetting);
    ui->verticalSlider->setValue(0);
    updateServo(servoSetting);
}

void Dialog::on_button45_clicked()
{
    servoSetting = "45";
    ui->verticalSlider->setValue(45);
    ui->angle->setText(servoSetting);
    updateServo("45");
}

void Dialog::on_button90_clicked()
{
    servoSetting = "90";
    ui->verticalSlider->setValue(90);
    ui->angle->setText(servoSetting);
    updateServo("90");
}

void Dialog::on_button135_clicked()
{
    servoSetting = "135";
    ui->verticalSlider->setValue(135);
    ui->angle->setText(servoSetting);
    updateServo("135");
}

void Dialog::on_button180_clicked()
{
    servoSetting = "180";
    ui->verticalSlider->setValue(180);
    ui->angle->setText(servoSetting);
    updateServo("180");
}

void Dialog::on_verticalSlider_valueChanged(int value)
{
    servoSetting = QString::number(value);
    ui->angle->setText(servoSetting);
    updateServo(servoSetting);
}

void Dialog::on_button_auto_clicked()
{
    if (autoTimer->isActive()) {
        autoTimer->stop();
        ui->button_auto->setText("Start Auto");
    } else {
        autoTimer->start(1000);
        ui->button_auto->setText("Stop Auto");
    }
}

void Dialog::updateServoAuto()
{
    // Function to automatically update the servo (e.g. sweep from 0 to 180 degrees)
    static bool increasing = true;
    static int angle = 0;

    if (increasing) {
        angle += 5;
        if (angle >= 180) {
            increasing = false;
        }
    } else {
        angle -= 5;
        if (angle <= 0) {
            increasing = true;
        }
    }

    updateServo(QString::number(angle));
    ui->angle->setText(QString::number(angle));
    ui->verticalSlider->setValue(angle);
}

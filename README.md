https://mf234.blogspot.com/2024/06/research-analysis-of-arduino-radar.html#more

[6//11/2024]
Pada perubahan kali ini, saya telah menambahkan fitur laser yang menyala ketika objek terdeteksi dalam jarak kurang dari 50 cm. Fitur ini membuat simulasi radar terasa lebih realistis dan menarik.

Di sisi Arduino, saya menambahkan pin untuk mengontrol laser dan mengonfigurasi pin tersebut sebagai output. Saya juga membuat fungsi baru `stopAndActivateLaser()` yang bertanggung jawab untuk menyalakan laser selama 2 detik, menghentikan pergerakan servo sementara, lalu mematikan laser kembali. Fungsi ini dipanggil pada loop utama jika jarak kurang dari 50 cm.

Pada aplikasi Qt, saya menambahkan variabel baru untuk melacak status aktivasi laser dan mode operasi otomatis. Saya juga menambahkan dua timer baru - `laserTimer` untuk menangani aktivasi laser selama 2 detik, dan `resumeTimer` untuk melanjutkan operasi normal setelah aktivasi laser dan jeda 2 detik.

Saya membuat beberapa fungsi baru seperti `handleLaserActivation()` untuk menangani aktivasi laser, `resumeOperation()` untuk melanjutkan operasi normal, dan `updateLaserStatus()` untuk memperbarui status laser pada antarmuka pengguna.

Logika pada fungsi `readSerial()` juga saya perbaharui untuk menangani aktivasi laser berdasarkan jarak dan mengatur status laser dengan benar. Fungsi `updateDetectionPoint()` saya modifikasi agar tidak memperbarui titik deteksi jika laser sedang aktif.

Terakhir, saya menambahkan `textEdit` pada antarmuka pengguna untuk menampilkan status laser ("Laser: On" atau "Laser: Off").

Dengan peningkatan ini, aplikasi radar yang saya buat sekarang memiliki kemampuan untuk mengaktifkan laser selama 2 detik jika objek terdeteksi dalam jarak 50 cm. Selama aktivasi laser, servo akan berhenti berputar sementara, dan antarmuka pengguna akan menampilkan status laser yang sesuai. Setelah aktivasi laser dan jeda 2 detik, operasi normal akan dilanjutkan.


Arduino IDE:
#include <Servo.h>

// Servo
Servo myservo;

// HC-SR04 ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Laser
const int laserPin = 12;

long duration;
float distance;
int servoSetting;

void setup() {
  // Serial
  Serial.begin(9600);
  
  // Servo
  myservo.attach(11);
  myservo.write(0); // Initialize servo at angle 0
  
  // HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Laser
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW); // Ensure the laser is off initially
}

void loop() {
  getDistance();
  readSerialCommand(); // Read command from serial
  outputDistance();
  
  if (distance < 50) { // Threshold for stopping the servo and turning on the laser
    stopAndActivateLaser();
  } else {
    delay(50);
  }
}

// Function to read servo angle command from serial
void readSerialCommand() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    int angle = command.toInt();
    if (angle >= 0 && angle <= 180) {
      myservo.write(angle);
      servoSetting = angle;
    }
  }
}

// Function to get distance from HC-SR04
void getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

// Function to output distance to Serial
void outputDistance() {
  Serial.print(servoSetting); // Send servo angle
  Serial.print(",");
  Serial.println(distance);   // Send distance
}

// Function to stop servo and activate laser
void stopAndActivateLaser() {
  digitalWrite(laserPin, HIGH); // Turn on the laser
  delay(2000); // Keep the laser on for 2 seconds
  digitalWrite(laserPin, LOW); // Turn off the laser
  delay(2000); // Wait for 2 seconds before resuming
}


dialog.h:
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QtGui>
#include <QtMath>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void updateServo(QString command);
    void readSerial();
    void on_button0_clicked();
    void on_button90_clicked();
    void on_button180_clicked();
    void on_verticalSlider_valueChanged(int value);
    void on_button45_clicked();
    void on_button135_clicked();
    void on_button_auto_clicked();
    void updateServoAuto();
    void clearOldDetectionPoints();
    void updateDetectionPoint(float angle, float distance);
    void handleLaserActivation();
    void resumeOperation();
    void updateLaserStatus(const QString &status);

private:
    QGraphicsScene *scene;
    QPixmap pix;
    QGraphicsItem *rect;
    float currAngle;
    const float r;
    const float angleOffset;
    float t_up;
    float t_lo;
    QPolygonF triangle;
    QGraphicsPolygonItem* needle;
    QSerialPort *arduino;
    Ui::Dialog *ui;
    static const quint16 arduino_uno_vendorID = 9025;
    static const quint16 arduino_uno_productID = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray serialData;
    QString serialBuffer;
    QString servoSetting;
    QList<QGraphicsRectItem*> detectionPoints;
    QTimer *autoTimer;
    bool laserActive;
    QTimer *laserTimer;
    QTimer *resumeTimer;
    bool autoMode;
};
#endif // DIALOG_H


dialog.cpp:
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

    resumeTimer = new QTimer(this); // Timer to resume operations
    connect(resumeTimer, &QTimer::timeout, this, &Dialog::resumeOperation);
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
                        resumeTimer->start(4000); // Start resume timer for 4 seconds (2s laser + 2s pause)
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

void Dialog::handleLaserActivation() {
    laserActive = false;
    laserTimer->stop();
    qDebug() << "Laser turned off"; // Debugging: Print laser off status
    updateLaserStatus("Laser: Off"); // Update GUI to show laser is off
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
    angle += 5;
    if (angle > 180) angle = 0;
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


dialog.ui:
</widget>
  <widget class="QTextEdit" name="textEdit">
   <property name="geometry">
    <rect>
     <x>10</x>
     <y>510</y>
     <width>61</width>
     <height>31</height>
    </rect>
   </property>
   <property name="font">
    <font>
     <family>Times New Roman</family>
    </font>
   </property>
  </widget>

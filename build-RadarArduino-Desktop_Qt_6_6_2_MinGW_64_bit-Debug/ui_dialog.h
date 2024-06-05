/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGraphicsView *graphicsView;
    QPushButton *button0;
    QPushButton *button135;
    QPushButton *button180;
    QPushButton *button45;
    QPushButton *button90;
    QLabel *range;
    QLabel *label;
    QLabel *lablel_2;
    QSlider *verticalSlider;
    QLabel *angle;
    QPushButton *button_auto;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1262, 553);
        Dialog->setMinimumSize(QSize(1200, 540));
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(250, 10, 1000, 531));
        graphicsView->setMinimumSize(QSize(1000, 515));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush3(QColor(255, 255, 255, 127));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush4(QColor(0, 0, 0, 127));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        graphicsView->setPalette(palette);
        button0 = new QPushButton(Dialog);
        button0->setObjectName("button0");
        button0->setGeometry(QRect(10, 20, 61, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(11);
        button0->setFont(font);
        button135 = new QPushButton(Dialog);
        button135->setObjectName("button135");
        button135->setGeometry(QRect(10, 140, 61, 32));
        button135->setFont(font);
        button180 = new QPushButton(Dialog);
        button180->setObjectName("button180");
        button180->setGeometry(QRect(10, 180, 61, 32));
        button180->setFont(font);
        button45 = new QPushButton(Dialog);
        button45->setObjectName("button45");
        button45->setGeometry(QRect(10, 60, 61, 32));
        button45->setFont(font);
        button90 = new QPushButton(Dialog);
        button90->setObjectName("button90");
        button90->setGeometry(QRect(10, 100, 61, 32));
        button90->setFont(font);
        range = new QLabel(Dialog);
        range->setObjectName("range");
        range->setGeometry(QRect(40, 430, 175, 45));
        range->setMaximumSize(QSize(175, 45));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(28);
        range->setFont(font1);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 280, 150, 41));
        label->setMinimumSize(QSize(150, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        label->setFont(font2);
        lablel_2 = new QLabel(Dialog);
        lablel_2->setObjectName("lablel_2");
        lablel_2->setGeometry(QRect(80, 390, 150, 41));
        lablel_2->setMinimumSize(QSize(150, 25));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(20);
        font3.setBold(false);
        lablel_2->setFont(font3);
        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(130, 20, 100, 200));
        verticalSlider->setMinimumSize(QSize(100, 200));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        verticalSlider->setFont(font4);
        verticalSlider->setLayoutDirection(Qt::LeftToRight);
        verticalSlider->setMaximum(180);
        angle = new QLabel(Dialog);
        angle->setObjectName("angle");
        angle->setGeometry(QRect(90, 320, 71, 45));
        angle->setMaximumSize(QSize(150, 45));
        angle->setFont(font1);
        angle->setAutoFillBackground(false);
        button_auto = new QPushButton(Dialog);
        button_auto->setObjectName("button_auto");
        button_auto->setGeometry(QRect(10, 220, 101, 31));
        button_auto->setFont(font);
        button0->raise();
        button135->raise();
        button180->raise();
        button45->raise();
        button90->raise();
        range->raise();
        label->raise();
        lablel_2->raise();
        verticalSlider->raise();
        angle->raise();
        graphicsView->raise();
        button_auto->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Radar", nullptr));
        button0->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        button135->setText(QCoreApplication::translate("Dialog", "135", nullptr));
        button180->setText(QCoreApplication::translate("Dialog", "180", nullptr));
        button45->setText(QCoreApplication::translate("Dialog", "45", nullptr));
        button90->setText(QCoreApplication::translate("Dialog", "90", nullptr));
        range->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Angle:", nullptr));
        lablel_2->setText(QCoreApplication::translate("Dialog", "Range:", nullptr));
        angle->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        button_auto->setText(QCoreApplication::translate("Dialog", "Auto Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

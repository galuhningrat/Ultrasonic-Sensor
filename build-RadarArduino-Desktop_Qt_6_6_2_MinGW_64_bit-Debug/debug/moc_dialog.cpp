/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RadarArduino/dialog.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDialogENDCLASS = QtMocHelpers::stringData(
    "Dialog",
    "updateServo",
    "",
    "command",
    "readSerial",
    "on_button0_clicked",
    "on_button90_clicked",
    "on_button180_clicked",
    "on_verticalSlider_valueChanged",
    "value",
    "on_button45_clicked",
    "on_button135_clicked",
    "on_button_auto_clicked",
    "updateServoAuto",
    "clearOldDetectionPoints",
    "updateDetectionPoint",
    "angle",
    "distance"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDialogENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[11];
    char stringdata5[19];
    char stringdata6[20];
    char stringdata7[21];
    char stringdata8[31];
    char stringdata9[6];
    char stringdata10[20];
    char stringdata11[21];
    char stringdata12[23];
    char stringdata13[16];
    char stringdata14[24];
    char stringdata15[21];
    char stringdata16[6];
    char stringdata17[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDialogENDCLASS_t qt_meta_stringdata_CLASSDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Dialog"
        QT_MOC_LITERAL(7, 11),  // "updateServo"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 7),  // "command"
        QT_MOC_LITERAL(28, 10),  // "readSerial"
        QT_MOC_LITERAL(39, 18),  // "on_button0_clicked"
        QT_MOC_LITERAL(58, 19),  // "on_button90_clicked"
        QT_MOC_LITERAL(78, 20),  // "on_button180_clicked"
        QT_MOC_LITERAL(99, 30),  // "on_verticalSlider_valueChanged"
        QT_MOC_LITERAL(130, 5),  // "value"
        QT_MOC_LITERAL(136, 19),  // "on_button45_clicked"
        QT_MOC_LITERAL(156, 20),  // "on_button135_clicked"
        QT_MOC_LITERAL(177, 22),  // "on_button_auto_clicked"
        QT_MOC_LITERAL(200, 15),  // "updateServoAuto"
        QT_MOC_LITERAL(216, 23),  // "clearOldDetectionPoints"
        QT_MOC_LITERAL(240, 20),  // "updateDetectionPoint"
        QT_MOC_LITERAL(261, 5),  // "angle"
        QT_MOC_LITERAL(267, 8)   // "distance"
    },
    "Dialog",
    "updateServo",
    "",
    "command",
    "readSerial",
    "on_button0_clicked",
    "on_button90_clicked",
    "on_button180_clicked",
    "on_verticalSlider_valueChanged",
    "value",
    "on_button45_clicked",
    "on_button135_clicked",
    "on_button_auto_clicked",
    "updateServoAuto",
    "clearOldDetectionPoints",
    "updateDetectionPoint",
    "angle",
    "distance"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       4,    0,   89,    2, 0x08,    3 /* Private */,
       5,    0,   90,    2, 0x08,    4 /* Private */,
       6,    0,   91,    2, 0x08,    5 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    1,   93,    2, 0x08,    7 /* Private */,
      10,    0,   96,    2, 0x08,    9 /* Private */,
      11,    0,   97,    2, 0x08,   10 /* Private */,
      12,    0,   98,    2, 0x08,   11 /* Private */,
      13,    0,   99,    2, 0x08,   12 /* Private */,
      14,    0,  100,    2, 0x08,   13 /* Private */,
      15,    2,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   16,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dialog, std::true_type>,
        // method 'updateServo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button90_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button180_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_verticalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button45_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button135_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_auto_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateServoAuto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearOldDetectionPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDetectionPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateServo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->readSerial(); break;
        case 2: _t->on_button0_clicked(); break;
        case 3: _t->on_button90_clicked(); break;
        case 4: _t->on_button180_clicked(); break;
        case 5: _t->on_verticalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_button45_clicked(); break;
        case 7: _t->on_button135_clicked(); break;
        case 8: _t->on_button_auto_clicked(); break;
        case 9: _t->updateServoAuto(); break;
        case 10: _t->clearOldDetectionPoints(); break;
        case 11: _t->updateDetectionPoint((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'brightnessadjustbrightnesssettingsbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/brightnessadjustbrightnesssettingsbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brightnessadjustbrightnesssettingsbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic_t {
    QByteArrayData data[16];
    char stringdata0[390];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic_t qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic = {
    {
QT_MOC_LITERAL(0, 0, 39), // "BrightnessAdjustBrightnessSet..."
QT_MOC_LITERAL(1, 40, 11), // "dialogClose"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 25), // "sendBrightnessControlData"
QT_MOC_LITERAL(4, 79, 7), // "control"
QT_MOC_LITERAL(5, 87, 5), // "level"
QT_MOC_LITERAL(6, 93, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(7, 116, 33), // "on_brightnessLevelAccept_rele..."
QT_MOC_LITERAL(8, 150, 33), // "on_brightnessLevelCancel_rele..."
QT_MOC_LITERAL(9, 184, 31), // "brightnessControlSwitch_clicked"
QT_MOC_LITERAL(10, 216, 33), // "on_brightnessSlider_sliderPre..."
QT_MOC_LITERAL(11, 250, 32), // "on_brightnessSlider_valueChanged"
QT_MOC_LITERAL(12, 283, 5), // "value"
QT_MOC_LITERAL(13, 289, 36), // "on_brightnessAdjustIncrement_..."
QT_MOC_LITERAL(14, 326, 36), // "on_brightnessAdjustDecrement_..."
QT_MOC_LITERAL(15, 363, 26) // "showBrightnessAdjustScreen"

    },
    "BrightnessAdjustBrightnessSettingsBasic\0"
    "dialogClose\0\0sendBrightnessControlData\0"
    "control\0level\0writeParameterToEeprom\0"
    "on_brightnessLevelAccept_released\0"
    "on_brightnessLevelCancel_released\0"
    "brightnessControlSwitch_clicked\0"
    "on_brightnessSlider_sliderPressed\0"
    "on_brightnessSlider_valueChanged\0value\0"
    "on_brightnessAdjustIncrement_pressed\0"
    "on_brightnessAdjustDecrement_pressed\0"
    "showBrightnessAdjustScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrightnessAdjustBrightnessSettingsBasic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    2,   70,    2, 0x06 /* Public */,
       6,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BrightnessAdjustBrightnessSettingsBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrightnessAdjustBrightnessSettingsBasic *_t = static_cast<BrightnessAdjustBrightnessSettingsBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->sendBrightnessControlData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->writeParameterToEeprom(); break;
        case 3: _t->on_brightnessLevelAccept_released(); break;
        case 4: _t->on_brightnessLevelCancel_released(); break;
        case 5: _t->brightnessControlSwitch_clicked(); break;
        case 6: _t->on_brightnessSlider_sliderPressed(); break;
        case 7: _t->on_brightnessSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_brightnessAdjustIncrement_pressed(); break;
        case 9: _t->on_brightnessAdjustDecrement_pressed(); break;
        case 10: _t->showBrightnessAdjustScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BrightnessAdjustBrightnessSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessAdjustBrightnessSettingsBasic::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BrightnessAdjustBrightnessSettingsBasic::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessAdjustBrightnessSettingsBasic::sendBrightnessControlData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BrightnessAdjustBrightnessSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessAdjustBrightnessSettingsBasic::writeParameterToEeprom)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BrightnessAdjustBrightnessSettingsBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic.data,
      qt_meta_data_BrightnessAdjustBrightnessSettingsBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BrightnessAdjustBrightnessSettingsBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrightnessAdjustBrightnessSettingsBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrightnessAdjustBrightnessSettingsBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BrightnessAdjustBrightnessSettingsBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BrightnessAdjustBrightnessSettingsBasic::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BrightnessAdjustBrightnessSettingsBasic::sendBrightnessControlData(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BrightnessAdjustBrightnessSettingsBasic::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

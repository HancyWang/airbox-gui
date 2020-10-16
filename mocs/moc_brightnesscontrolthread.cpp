/****************************************************************************
** Meta object code from reading C++ file 'brightnesscontrolthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../application/brightnesscontrolthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brightnesscontrolthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrightnessControlThread_t {
    QByteArrayData data[19];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrightnessControlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrightnessControlThread_t qt_meta_stringdata_BrightnessControlThread = {
    {
QT_MOC_LITERAL(0, 0, 23), // "BrightnessControlThread"
QT_MOC_LITERAL(1, 24, 27), // "snoozeButtonPressedDetected"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "state"
QT_MOC_LITERAL(4, 59, 26), // "sendAmbientLightSensorData"
QT_MOC_LITERAL(5, 86, 8), // "luxParam"
QT_MOC_LITERAL(6, 95, 23), // "powerOffProcedureSignal"
QT_MOC_LITERAL(7, 119, 14), // "showHomeWindow"
QT_MOC_LITERAL(8, 134, 25), // "sendBrightnessControlData"
QT_MOC_LITERAL(9, 160, 7), // "control"
QT_MOC_LITERAL(10, 168, 5), // "level"
QT_MOC_LITERAL(11, 174, 28), // "readLightSensorDataIntensity"
QT_MOC_LITERAL(12, 203, 23), // "brightnessRampTimerSlot"
QT_MOC_LITERAL(13, 227, 28), // "buttonStateCheckTimerTimeout"
QT_MOC_LITERAL(14, 256, 23), // "snoozeStateTimerTimeout"
QT_MOC_LITERAL(15, 280, 17), // "touchTimerTimeout"
QT_MOC_LITERAL(16, 298, 22), // "displayDimTimerTimeout"
QT_MOC_LITERAL(17, 321, 33), // "processLightSensorDataEverySe..."
QT_MOC_LITERAL(18, 355, 29) // "rgbLedColorUpdateTimerTimeOut"

    },
    "BrightnessControlThread\0"
    "snoozeButtonPressedDetected\0\0state\0"
    "sendAmbientLightSensorData\0luxParam\0"
    "powerOffProcedureSignal\0showHomeWindow\0"
    "sendBrightnessControlData\0control\0"
    "level\0readLightSensorDataIntensity\0"
    "brightnessRampTimerSlot\0"
    "buttonStateCheckTimerTimeout\0"
    "snoozeStateTimerTimeout\0touchTimerTimeout\0"
    "displayDimTimerTimeout\0"
    "processLightSensorDataEverySecond\0"
    "rgbLedColorUpdateTimerTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrightnessControlThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   87,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,
      12,    0,   93,    2, 0x0a /* Public */,
      13,    0,   94,    2, 0x0a /* Public */,
      14,    0,   95,    2, 0x0a /* Public */,
      15,    0,   96,    2, 0x0a /* Public */,
      16,    0,   97,    2, 0x0a /* Public */,
      17,    0,   98,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BrightnessControlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrightnessControlThread *_t = static_cast<BrightnessControlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->snoozeButtonPressedDetected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendAmbientLightSensorData((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->powerOffProcedureSignal(); break;
        case 3: _t->showHomeWindow(); break;
        case 4: _t->sendBrightnessControlData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->readLightSensorDataIntensity(); break;
        case 6: _t->brightnessRampTimerSlot(); break;
        case 7: _t->buttonStateCheckTimerTimeout(); break;
        case 8: _t->snoozeStateTimerTimeout(); break;
        case 9: _t->touchTimerTimeout(); break;
        case 10: _t->displayDimTimerTimeout(); break;
        case 11: _t->processLightSensorDataEverySecond(); break;
        case 12: _t->rgbLedColorUpdateTimerTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BrightnessControlThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessControlThread::snoozeButtonPressedDetected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BrightnessControlThread::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessControlThread::sendAmbientLightSensorData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BrightnessControlThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessControlThread::powerOffProcedureSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BrightnessControlThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessControlThread::showHomeWindow)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BrightnessControlThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BrightnessControlThread.data,
      qt_meta_data_BrightnessControlThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BrightnessControlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrightnessControlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrightnessControlThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BrightnessControlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void BrightnessControlThread::snoozeButtonPressedDetected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BrightnessControlThread::sendAmbientLightSensorData(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BrightnessControlThread::powerOffProcedureSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BrightnessControlThread::showHomeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

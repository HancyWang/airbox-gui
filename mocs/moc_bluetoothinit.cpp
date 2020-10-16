/****************************************************************************
** Meta object code from reading C++ file 'bluetoothinit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ble/bluetoothinit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothinit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluetoothInit_t {
    QByteArrayData data[31];
    char stringdata0[469];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothInit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothInit_t qt_meta_stringdata_BluetoothInit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BluetoothInit"
QT_MOC_LITERAL(1, 14, 12), // "setGpioState"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "gpioNo"
QT_MOC_LITERAL(4, 35, 11), // "outputState"
QT_MOC_LITERAL(5, 47, 20), // "logDataToDebugScreen"
QT_MOC_LITERAL(6, 68, 3), // "str"
QT_MOC_LITERAL(7, 72, 23), // "BluetoothDebugColorType"
QT_MOC_LITERAL(8, 96, 4), // "type"
QT_MOC_LITERAL(9, 101, 16), // "copyDataToSDCard"
QT_MOC_LITERAL(10, 118, 12), // "bleConnected"
QT_MOC_LITERAL(11, 131, 20), // "bleConnectionUpdated"
QT_MOC_LITERAL(12, 152, 30), // "QLowEnergyConnectionParameters"
QT_MOC_LITERAL(13, 183, 13), // "newParameters"
QT_MOC_LITERAL(14, 197, 15), // "bleDisconnected"
QT_MOC_LITERAL(15, 213, 20), // "bleDiscoveryFinished"
QT_MOC_LITERAL(16, 234, 8), // "bleError"
QT_MOC_LITERAL(17, 243, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(18, 271, 8), // "newError"
QT_MOC_LITERAL(19, 280, 20), // "bleServiceDiscovered"
QT_MOC_LITERAL(20, 301, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(21, 316, 10), // "newService"
QT_MOC_LITERAL(22, 327, 15), // "bleStateChanged"
QT_MOC_LITERAL(23, 343, 37), // "QLowEnergyController::Control..."
QT_MOC_LITERAL(24, 381, 5), // "state"
QT_MOC_LITERAL(25, 387, 11), // "printOutput"
QT_MOC_LITERAL(26, 399, 10), // "printError"
QT_MOC_LITERAL(27, 410, 13), // "logDataToFile"
QT_MOC_LITERAL(28, 424, 17), // "bleInitProcedures"
QT_MOC_LITERAL(29, 442, 19), // "handleBlePowerOnOff"
QT_MOC_LITERAL(30, 462, 6) // "tState"

    },
    "BluetoothInit\0setGpioState\0\0gpioNo\0"
    "outputState\0logDataToDebugScreen\0str\0"
    "BluetoothDebugColorType\0type\0"
    "copyDataToSDCard\0bleConnected\0"
    "bleConnectionUpdated\0"
    "QLowEnergyConnectionParameters\0"
    "newParameters\0bleDisconnected\0"
    "bleDiscoveryFinished\0bleError\0"
    "QLowEnergyController::Error\0newError\0"
    "bleServiceDiscovered\0QBluetoothUuid\0"
    "newService\0bleStateChanged\0"
    "QLowEnergyController::ControllerState\0"
    "state\0printOutput\0printError\0logDataToFile\0"
    "bleInitProcedures\0handleBlePowerOnOff\0"
    "tState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothInit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    2,   94,    2, 0x06 /* Public */,
       9,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  100,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    1,  106,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,
      22,    1,  112,    2, 0x08 /* Private */,
      25,    0,  115,    2, 0x08 /* Private */,
      26,    0,  116,    2, 0x08 /* Private */,
      27,    2,  117,    2, 0x0a /* Public */,
      28,    0,  122,    2, 0x0a /* Public */,
      29,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   30,

       0        // eod
};

void BluetoothInit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BluetoothInit *_t = static_cast<BluetoothInit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGpioState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->logDataToDebugScreen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< BluetoothDebugColorType(*)>(_a[2]))); break;
        case 2: _t->copyDataToSDCard(); break;
        case 3: _t->bleConnected(); break;
        case 4: _t->bleConnectionUpdated((*reinterpret_cast< const QLowEnergyConnectionParameters(*)>(_a[1]))); break;
        case 5: _t->bleDisconnected(); break;
        case 6: _t->bleDiscoveryFinished(); break;
        case 7: _t->bleError((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 8: _t->bleServiceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 9: _t->bleStateChanged((*reinterpret_cast< QLowEnergyController::ControllerState(*)>(_a[1]))); break;
        case 10: _t->printOutput(); break;
        case 11: _t->printError(); break;
        case 12: _t->logDataToFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< BluetoothDebugColorType(*)>(_a[2]))); break;
        case 13: _t->bleInitProcedures(); break;
        case 14: _t->handleBlePowerOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::ControllerState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BluetoothInit::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothInit::setGpioState)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BluetoothInit::*)(const QString & , BluetoothDebugColorType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothInit::logDataToDebugScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BluetoothInit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothInit::copyDataToSDCard)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluetoothInit::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BluetoothInit.data,
      qt_meta_data_BluetoothInit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BluetoothInit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothInit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothInit.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluetoothInit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void BluetoothInit::setGpioState(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothInit::logDataToDebugScreen(const QString & _t1, BluetoothDebugColorType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothInit::copyDataToSDCard()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

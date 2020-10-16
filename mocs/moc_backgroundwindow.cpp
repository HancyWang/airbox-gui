/****************************************************************************
** Meta object code from reading C++ file 'backgroundwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/backgroundwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backgroundwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackgroundWindow_t {
    QByteArrayData data[31];
    char stringdata0[529];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackgroundWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackgroundWindow_t qt_meta_stringdata_BackgroundWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BackgroundWindow"
QT_MOC_LITERAL(1, 17, 30), // "startStopStateChanged_toThread"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "state"
QT_MOC_LITERAL(4, 55, 6), // "setRpm"
QT_MOC_LITERAL(5, 62, 8), // "rampTime"
QT_MOC_LITERAL(6, 71, 26), // "sendSetParameters_toThread"
QT_MOC_LITERAL(7, 98, 24), // "sendBrakeSignal_toThread"
QT_MOC_LITERAL(8, 123, 4), // "type"
QT_MOC_LITERAL(9, 128, 9), // "intensity"
QT_MOC_LITERAL(10, 138, 24), // "sendIPCCommunicationData"
QT_MOC_LITERAL(11, 163, 3), // "str"
QT_MOC_LITERAL(12, 167, 28), // "sendManufacturingModeChanged"
QT_MOC_LITERAL(13, 196, 14), // "manufModeState"
QT_MOC_LITERAL(14, 211, 25), // "sendBrightnessControlData"
QT_MOC_LITERAL(15, 237, 7), // "control"
QT_MOC_LITERAL(16, 245, 5), // "level"
QT_MOC_LITERAL(17, 251, 25), // "startSdCardDetectionTimer"
QT_MOC_LITERAL(18, 277, 25), // "snoozeButtonPressDetected"
QT_MOC_LITERAL(19, 303, 11), // "printOutput"
QT_MOC_LITERAL(20, 315, 10), // "printError"
QT_MOC_LITERAL(21, 326, 18), // "stage1TimerTimeout"
QT_MOC_LITERAL(22, 345, 22), // "handledirectoryChanged"
QT_MOC_LITERAL(23, 368, 4), // "path"
QT_MOC_LITERAL(24, 373, 17), // "handleFileChanged"
QT_MOC_LITERAL(25, 391, 30), // "manufacturingLightSensorUpdate"
QT_MOC_LITERAL(26, 422, 8), // "luxParam"
QT_MOC_LITERAL(27, 431, 21), // "powerOffProcedureSlot"
QT_MOC_LITERAL(28, 453, 17), // "showAllWindowSlot"
QT_MOC_LITERAL(29, 471, 20), // "updateEffectPointers"
QT_MOC_LITERAL(30, 492, 36) // "openTherapyWindowOnAutoStartD..."

    },
    "BackgroundWindow\0startStopStateChanged_toThread\0"
    "\0state\0setRpm\0rampTime\0"
    "sendSetParameters_toThread\0"
    "sendBrakeSignal_toThread\0type\0intensity\0"
    "sendIPCCommunicationData\0str\0"
    "sendManufacturingModeChanged\0"
    "manufModeState\0sendBrightnessControlData\0"
    "control\0level\0startSdCardDetectionTimer\0"
    "snoozeButtonPressDetected\0printOutput\0"
    "printError\0stage1TimerTimeout\0"
    "handledirectoryChanged\0path\0"
    "handleFileChanged\0manufacturingLightSensorUpdate\0"
    "luxParam\0powerOffProcedureSlot\0"
    "showAllWindowSlot\0updateEffectPointers\0"
    "openTherapyWindowOnAutoStartDetected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackgroundWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  104,    2, 0x06 /* Public */,
       6,    1,  111,    2, 0x06 /* Public */,
       7,    2,  114,    2, 0x06 /* Public */,
      10,    1,  119,    2, 0x06 /* Public */,
      12,    1,  122,    2, 0x06 /* Public */,
      14,    2,  125,    2, 0x06 /* Public */,
      17,    0,  130,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  131,    2, 0x0a /* Public */,
      19,    0,  134,    2, 0x0a /* Public */,
      20,    0,  135,    2, 0x0a /* Public */,
      21,    0,  136,    2, 0x0a /* Public */,
      22,    1,  137,    2, 0x0a /* Public */,
      24,    1,  140,    2, 0x0a /* Public */,
      25,    1,  143,    2, 0x0a /* Public */,
      27,    0,  146,    2, 0x0a /* Public */,
      28,    0,  147,    2, 0x0a /* Public */,
      29,    0,  148,    2, 0x0a /* Public */,
      30,    0,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   15,   16,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Float,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BackgroundWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackgroundWindow *_t = static_cast<BackgroundWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startStopStateChanged_toThread((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sendSetParameters_toThread((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendBrakeSignal_toThread((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sendIPCCommunicationData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendManufacturingModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sendBrightnessControlData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->startSdCardDetectionTimer(); break;
        case 7: _t->snoozeButtonPressDetected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->printOutput(); break;
        case 9: _t->printError(); break;
        case 10: _t->stage1TimerTimeout(); break;
        case 11: _t->handledirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->handleFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->manufacturingLightSensorUpdate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->powerOffProcedureSlot(); break;
        case 15: _t->showAllWindowSlot(); break;
        case 16: _t->updateEffectPointers(); break;
        case 17: _t->openTherapyWindowOnAutoStartDetected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackgroundWindow::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::startStopStateChanged_toThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::sendSetParameters_toThread)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::sendBrakeSignal_toThread)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::sendIPCCommunicationData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::sendManufacturingModeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::sendBrightnessControlData)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BackgroundWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundWindow::startSdCardDetectionTimer)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BackgroundWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BackgroundWindow.data,
      qt_meta_data_BackgroundWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BackgroundWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackgroundWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BackgroundWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void BackgroundWindow::startStopStateChanged_toThread(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackgroundWindow::sendSetParameters_toThread(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackgroundWindow::sendBrakeSignal_toThread(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BackgroundWindow::sendIPCCommunicationData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackgroundWindow::sendManufacturingModeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BackgroundWindow::sendBrightnessControlData(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BackgroundWindow::startSdCardDetectionTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

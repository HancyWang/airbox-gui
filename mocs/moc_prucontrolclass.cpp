/****************************************************************************
** Meta object code from reading C++ file 'prucontrolclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../application/prucontrolclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prucontrolclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PruControlClass_t {
    QByteArrayData data[55];
    char stringdata0[925];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PruControlClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PruControlClass_t qt_meta_stringdata_PruControlClass = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PruControlClass"
QT_MOC_LITERAL(1, 16, 23), // "addParamToSpecificFiles"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "int*"
QT_MOC_LITERAL(4, 46, 4), // "data"
QT_MOC_LITERAL(5, 51, 23), // "updateEventToDataLogger"
QT_MOC_LITERAL(6, 75, 6), // "event1"
QT_MOC_LITERAL(7, 82, 6), // "event3"
QT_MOC_LITERAL(8, 89, 25), // "sendTunningParameterToPRU"
QT_MOC_LITERAL(9, 115, 27), // "processGotoSleepRampRuntime"
QT_MOC_LITERAL(10, 143, 29), // "updateStartStopTherapyDetails"
QT_MOC_LITERAL(11, 173, 17), // "autoStartDetected"
QT_MOC_LITERAL(12, 191, 30), // "updateReferenceWindowParameter"
QT_MOC_LITERAL(13, 222, 19), // "referenceWindowData"
QT_MOC_LITERAL(14, 242, 28), // "updateCurrentWindowParameter"
QT_MOC_LITERAL(15, 271, 17), // "currentWindowData"
QT_MOC_LITERAL(16, 289, 26), // "updatePressureSensorOffset"
QT_MOC_LITERAL(17, 316, 6), // "offset"
QT_MOC_LITERAL(18, 323, 31), // "updateScreenAsPerReceivedPacket"
QT_MOC_LITERAL(19, 355, 5), // "uint*"
QT_MOC_LITERAL(20, 361, 8), // "localBuf"
QT_MOC_LITERAL(21, 370, 19), // "updateAndShowScreen"
QT_MOC_LITERAL(22, 390, 6), // "tArray"
QT_MOC_LITERAL(23, 397, 6), // "tCount"
QT_MOC_LITERAL(24, 404, 19), // "updateFlowParameter"
QT_MOC_LITERAL(25, 424, 8), // "flowData"
QT_MOC_LITERAL(26, 433, 21), // "updateEventTypeStatus"
QT_MOC_LITERAL(27, 455, 5), // "event"
QT_MOC_LITERAL(28, 461, 18), // "updateStableStatus"
QT_MOC_LITERAL(29, 480, 11), // "tStableFlag"
QT_MOC_LITERAL(30, 492, 20), // "updateMaskLeakStatus"
QT_MOC_LITERAL(31, 513, 10), // "tLeakState"
QT_MOC_LITERAL(32, 524, 16), // "updateEnableApap"
QT_MOC_LITERAL(33, 541, 7), // "tEnFlag"
QT_MOC_LITERAL(34, 549, 20), // "updateHypoApneaCount"
QT_MOC_LITERAL(35, 570, 17), // "updatebreathCount"
QT_MOC_LITERAL(36, 588, 5), // "count"
QT_MOC_LITERAL(37, 594, 18), // "updateLeakageCount"
QT_MOC_LITERAL(38, 613, 23), // "ipcReadTimerTimeOutSlot"
QT_MOC_LITERAL(39, 637, 14), // "initPruControl"
QT_MOC_LITERAL(40, 652, 32), // "beforeManufacturingModeProcedure"
QT_MOC_LITERAL(41, 685, 12), // "manuFactMode"
QT_MOC_LITERAL(42, 698, 11), // "blowerState"
QT_MOC_LITERAL(43, 710, 11), // "blowerSpeed"
QT_MOC_LITERAL(44, 722, 18), // "startPruProcessing"
QT_MOC_LITERAL(45, 741, 21), // "beforeSnoozeProcedure"
QT_MOC_LITERAL(46, 763, 5), // "state"
QT_MOC_LITERAL(47, 769, 27), // "beforeStartTherapyProcedure"
QT_MOC_LITERAL(48, 797, 22), // "updateTunningParameter"
QT_MOC_LITERAL(49, 820, 5), // "param"
QT_MOC_LITERAL(50, 826, 32), // "beforePressureOffsetGetProcedure"
QT_MOC_LITERAL(51, 859, 28), // "pruProcessorStartStopProcess"
QT_MOC_LITERAL(52, 888, 5), // "pruNo"
QT_MOC_LITERAL(53, 894, 15), // "programmFileStr"
QT_MOC_LITERAL(54, 910, 14) // "processorState"

    },
    "PruControlClass\0addParamToSpecificFiles\0"
    "\0int*\0data\0updateEventToDataLogger\0"
    "event1\0event3\0sendTunningParameterToPRU\0"
    "processGotoSleepRampRuntime\0"
    "updateStartStopTherapyDetails\0"
    "autoStartDetected\0updateReferenceWindowParameter\0"
    "referenceWindowData\0updateCurrentWindowParameter\0"
    "currentWindowData\0updatePressureSensorOffset\0"
    "offset\0updateScreenAsPerReceivedPacket\0"
    "uint*\0localBuf\0updateAndShowScreen\0"
    "tArray\0tCount\0updateFlowParameter\0"
    "flowData\0updateEventTypeStatus\0event\0"
    "updateStableStatus\0tStableFlag\0"
    "updateMaskLeakStatus\0tLeakState\0"
    "updateEnableApap\0tEnFlag\0updateHypoApneaCount\0"
    "updatebreathCount\0count\0updateLeakageCount\0"
    "ipcReadTimerTimeOutSlot\0initPruControl\0"
    "beforeManufacturingModeProcedure\0"
    "manuFactMode\0blowerState\0blowerSpeed\0"
    "startPruProcessing\0beforeSnoozeProcedure\0"
    "state\0beforeStartTherapyProcedure\0"
    "updateTunningParameter\0param\0"
    "beforePressureOffsetGetProcedure\0"
    "pruProcessorStartStopProcess\0pruNo\0"
    "programmFileStr\0processorState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PruControlClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       5,    2,  157,    2, 0x06 /* Public */,
       8,    0,  162,    2, 0x06 /* Public */,
       9,    0,  163,    2, 0x06 /* Public */,
      10,    0,  164,    2, 0x06 /* Public */,
      11,    0,  165,    2, 0x06 /* Public */,
      12,    1,  166,    2, 0x06 /* Public */,
      14,    1,  169,    2, 0x06 /* Public */,
      16,    1,  172,    2, 0x06 /* Public */,
      18,    1,  175,    2, 0x06 /* Public */,
      21,    2,  178,    2, 0x06 /* Public */,
      24,    1,  183,    2, 0x06 /* Public */,
      26,    1,  186,    2, 0x06 /* Public */,
      28,    1,  189,    2, 0x06 /* Public */,
      30,    1,  192,    2, 0x06 /* Public */,
      32,    1,  195,    2, 0x06 /* Public */,
      34,    1,  198,    2, 0x06 /* Public */,
      35,    1,  201,    2, 0x06 /* Public */,
      37,    1,  204,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      38,    0,  207,    2, 0x0a /* Public */,
      39,    0,  208,    2, 0x0a /* Public */,
      40,    3,  209,    2, 0x0a /* Public */,
      44,    0,  216,    2, 0x0a /* Public */,
      45,    1,  217,    2, 0x0a /* Public */,
      47,    0,  220,    2, 0x0a /* Public */,
      48,    1,  221,    2, 0x0a /* Public */,
      50,    0,  224,    2, 0x0a /* Public */,
      51,    3,  225,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,   22,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::UInt,   27,
    QMetaType::Void, QMetaType::UInt,   29,
    QMetaType::Void, QMetaType::UInt,   31,
    QMetaType::Void, QMetaType::UInt,   33,
    QMetaType::Void, QMetaType::UInt,   23,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::Int,   36,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   41,   42,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   52,   53,   54,

       0        // eod
};

void PruControlClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PruControlClass *_t = static_cast<PruControlClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addParamToSpecificFiles((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: _t->updateEventToDataLogger((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->sendTunningParameterToPRU(); break;
        case 3: _t->processGotoSleepRampRuntime(); break;
        case 4: _t->updateStartStopTherapyDetails(); break;
        case 5: _t->autoStartDetected(); break;
        case 6: _t->updateReferenceWindowParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateCurrentWindowParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updatePressureSensorOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateScreenAsPerReceivedPacket((*reinterpret_cast< uint*(*)>(_a[1]))); break;
        case 10: _t->updateAndShowScreen((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->updateFlowParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateEventTypeStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->updateStableStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 14: _t->updateMaskLeakStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 15: _t->updateEnableApap((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 16: _t->updateHypoApneaCount((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 17: _t->updatebreathCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->updateLeakageCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->ipcReadTimerTimeOutSlot(); break;
        case 20: _t->initPruControl(); break;
        case 21: _t->beforeManufacturingModeProcedure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 22: _t->startPruProcessing(); break;
        case 23: _t->beforeSnoozeProcedure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->beforeStartTherapyProcedure(); break;
        case 25: _t->updateTunningParameter((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 26: _t->beforePressureOffsetGetProcedure(); break;
        case 27: _t->pruProcessorStartStopProcess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PruControlClass::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::addParamToSpecificFiles)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateEventToDataLogger)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::sendTunningParameterToPRU)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::processGotoSleepRampRuntime)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateStartStopTherapyDetails)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::autoStartDetected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateReferenceWindowParameter)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateCurrentWindowParameter)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updatePressureSensorOffset)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateScreenAsPerReceivedPacket)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateAndShowScreen)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateFlowParameter)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateEventTypeStatus)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateStableStatus)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateMaskLeakStatus)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateEnableApap)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateHypoApneaCount)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updatebreathCount)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (PruControlClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PruControlClass::updateLeakageCount)) {
                *result = 18;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PruControlClass::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PruControlClass.data,
      qt_meta_data_PruControlClass,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PruControlClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PruControlClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PruControlClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PruControlClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void PruControlClass::addParamToSpecificFiles(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PruControlClass::updateEventToDataLogger(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PruControlClass::sendTunningParameterToPRU()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PruControlClass::processGotoSleepRampRuntime()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PruControlClass::updateStartStopTherapyDetails()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PruControlClass::autoStartDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PruControlClass::updateReferenceWindowParameter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PruControlClass::updateCurrentWindowParameter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PruControlClass::updatePressureSensorOffset(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PruControlClass::updateScreenAsPerReceivedPacket(unsigned int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PruControlClass::updateAndShowScreen(int * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PruControlClass::updateFlowParameter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PruControlClass::updateEventTypeStatus(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PruControlClass::updateStableStatus(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PruControlClass::updateMaskLeakStatus(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void PruControlClass::updateEnableApap(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void PruControlClass::updateHypoApneaCount(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void PruControlClass::updatebreathCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void PruControlClass::updateLeakageCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

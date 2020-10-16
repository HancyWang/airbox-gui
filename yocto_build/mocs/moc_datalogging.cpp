/****************************************************************************
** Meta object code from reading C++ file 'datalogging.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../application/datalogging.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datalogging.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataLogging_t {
    QByteArrayData data[38];
    char stringdata0[579];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataLogging_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataLogging_t qt_meta_stringdata_DataLogging = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataLogging"
QT_MOC_LITERAL(1, 12, 27), // "writeDeviceLifeDataToEeprom"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 18), // "updateSdCardStatus"
QT_MOC_LITERAL(4, 60, 5), // "state"
QT_MOC_LITERAL(5, 66, 15), // "lrdTimerTimeout"
QT_MOC_LITERAL(6, 82, 28), // "checkSdCardExistTimerTimeout"
QT_MOC_LITERAL(7, 111, 20), // "copyDataTimerTimeout"
QT_MOC_LITERAL(8, 132, 19), // "secondsTimerTimeout"
QT_MOC_LITERAL(9, 152, 24), // "therapyStartFilesProcess"
QT_MOC_LITERAL(10, 177, 23), // "therapyStopFilesProcess"
QT_MOC_LITERAL(11, 201, 18), // "getSleepReportData"
QT_MOC_LITERAL(12, 220, 16), // "tSleepReportType"
QT_MOC_LITERAL(13, 237, 20), // "sendSleepReportParam"
QT_MOC_LITERAL(14, 258, 19), // "sleepReportDuration"
QT_MOC_LITERAL(15, 278, 13), // "QFileInfoList"
QT_MOC_LITERAL(16, 292, 4), // "list"
QT_MOC_LITERAL(17, 297, 5), // "index"
QT_MOC_LITERAL(18, 303, 6), // "float*"
QT_MOC_LITERAL(19, 310, 11), // "tUsageHours"
QT_MOC_LITERAL(20, 322, 14), // "tEventsPerHour"
QT_MOC_LITERAL(21, 337, 8), // "tLeakage"
QT_MOC_LITERAL(22, 346, 4), // "int*"
QT_MOC_LITERAL(23, 351, 19), // "usedHours4PlusIndex"
QT_MOC_LITERAL(24, 371, 13), // "usedDaysIndex"
QT_MOC_LITERAL(25, 385, 13), // "tAverageUsage"
QT_MOC_LITERAL(26, 399, 16), // "getDataForOneDay"
QT_MOC_LITERAL(27, 416, 8), // "QString&"
QT_MOC_LITERAL(28, 425, 12), // "tPrevDateStr"
QT_MOC_LITERAL(29, 438, 13), // "tTodayDateStr"
QT_MOC_LITERAL(30, 452, 16), // "copyDataToSDCard"
QT_MOC_LITERAL(31, 469, 23), // "addParamToSpecificFiles"
QT_MOC_LITERAL(32, 493, 4), // "data"
QT_MOC_LITERAL(33, 498, 18), // "updateEventFromPru"
QT_MOC_LITERAL(34, 517, 6), // "event1"
QT_MOC_LITERAL(35, 524, 6), // "event3"
QT_MOC_LITERAL(36, 531, 21), // "datalogInitProcedures"
QT_MOC_LITERAL(37, 553, 25) // "startSdCardDetectionTimer"

    },
    "DataLogging\0writeDeviceLifeDataToEeprom\0"
    "\0updateSdCardStatus\0state\0lrdTimerTimeout\0"
    "checkSdCardExistTimerTimeout\0"
    "copyDataTimerTimeout\0secondsTimerTimeout\0"
    "therapyStartFilesProcess\0"
    "therapyStopFilesProcess\0getSleepReportData\0"
    "tSleepReportType\0sendSleepReportParam\0"
    "sleepReportDuration\0QFileInfoList\0"
    "list\0index\0float*\0tUsageHours\0"
    "tEventsPerHour\0tLeakage\0int*\0"
    "usedHours4PlusIndex\0usedDaysIndex\0"
    "tAverageUsage\0getDataForOneDay\0QString&\0"
    "tPrevDateStr\0tTodayDateStr\0copyDataToSDCard\0"
    "addParamToSpecificFiles\0data\0"
    "updateEventFromPru\0event1\0event3\0"
    "datalogInitProcedures\0startSdCardDetectionTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataLogging[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,   10,   99,    2, 0x0a /* Public */,
      26,    8,  120,    2, 0x0a /* Public */,
      30,    0,  137,    2, 0x0a /* Public */,
      31,    1,  138,    2, 0x0a /* Public */,
      33,    2,  141,    2, 0x0a /* Public */,
      36,    0,  146,    2, 0x0a /* Public */,
      37,    0,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13, 0x80000000 | 15, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 18,   12,   14,   16,   17,   19,   20,   21,   23,   24,   25,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15, 0x80000000 | 27, 0x80000000 | 27, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 18,   12,   16,   28,   29,   17,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   32,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,   34,   35,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataLogging::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataLogging *_t = static_cast<DataLogging *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeDeviceLifeDataToEeprom(); break;
        case 1: _t->updateSdCardStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->lrdTimerTimeout(); break;
        case 3: _t->checkSdCardExistTimerTimeout(); break;
        case 4: _t->copyDataTimerTimeout(); break;
        case 5: _t->secondsTimerTimeout(); break;
        case 6: _t->therapyStartFilesProcess(); break;
        case 7: _t->therapyStopFilesProcess(); break;
        case 8: _t->getSleepReportData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< sendSleepReportParam(*)>(_a[2])),(*reinterpret_cast< const QFileInfoList(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< float*(*)>(_a[5])),(*reinterpret_cast< float*(*)>(_a[6])),(*reinterpret_cast< float*(*)>(_a[7])),(*reinterpret_cast< int*(*)>(_a[8])),(*reinterpret_cast< int*(*)>(_a[9])),(*reinterpret_cast< float*(*)>(_a[10]))); break;
        case 9: _t->getDataForOneDay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QFileInfoList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< float*(*)>(_a[6])),(*reinterpret_cast< float*(*)>(_a[7])),(*reinterpret_cast< float*(*)>(_a[8]))); break;
        case 10: _t->copyDataToSDCard(); break;
        case 11: _t->addParamToSpecificFiles((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 12: _t->updateEventFromPru((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 13: _t->datalogInitProcedures(); break;
        case 14: _t->startSdCardDetectionTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataLogging::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLogging::writeDeviceLifeDataToEeprom)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataLogging::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLogging::updateSdCardStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataLogging::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataLogging.data,
      qt_meta_data_DataLogging,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataLogging::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataLogging::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataLogging.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataLogging::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void DataLogging::writeDeviceLifeDataToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataLogging::updateSdCardStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

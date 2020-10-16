/****************************************************************************
** Meta object code from reading C++ file 'notificationtray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/notificationtray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notificationtray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotificationTray_t {
    QByteArrayData data[31];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotificationTray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotificationTray_t qt_meta_stringdata_NotificationTray = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NotificationTray"
QT_MOC_LITERAL(1, 17, 10), // "updateTime"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 24), // "updateAirplaneModeStatus"
QT_MOC_LITERAL(4, 54, 5), // "state"
QT_MOC_LITERAL(5, 60, 21), // "updateBluetoothStatus"
QT_MOC_LITERAL(6, 82, 18), // "updateSdCardStatus"
QT_MOC_LITERAL(7, 101, 16), // "updateSystemDate"
QT_MOC_LITERAL(8, 118, 4), // "date"
QT_MOC_LITERAL(9, 123, 5), // "month"
QT_MOC_LITERAL(10, 129, 4), // "year"
QT_MOC_LITERAL(11, 134, 16), // "updateSystemTime"
QT_MOC_LITERAL(12, 151, 4), // "hour"
QT_MOC_LITERAL(13, 156, 3), // "min"
QT_MOC_LITERAL(14, 160, 3), // "sec"
QT_MOC_LITERAL(15, 164, 19), // "updateFlowParameter"
QT_MOC_LITERAL(16, 184, 8), // "flowData"
QT_MOC_LITERAL(17, 193, 21), // "updateEventTypeStatus"
QT_MOC_LITERAL(18, 215, 5), // "event"
QT_MOC_LITERAL(19, 221, 18), // "updateStableStatus"
QT_MOC_LITERAL(20, 240, 11), // "tStableFlag"
QT_MOC_LITERAL(21, 252, 20), // "updateMaskLeakStatus"
QT_MOC_LITERAL(22, 273, 10), // "tLeakState"
QT_MOC_LITERAL(23, 284, 16), // "updateEnableApap"
QT_MOC_LITERAL(24, 301, 7), // "tEnFlag"
QT_MOC_LITERAL(25, 309, 20), // "updateHypoApneaCount"
QT_MOC_LITERAL(26, 330, 6), // "tCount"
QT_MOC_LITERAL(27, 337, 17), // "updatebreathCount"
QT_MOC_LITERAL(28, 355, 5), // "count"
QT_MOC_LITERAL(29, 361, 18), // "updateLeakageCount"
QT_MOC_LITERAL(30, 380, 19) // "updateTimeToHWClock"

    },
    "NotificationTray\0updateTime\0\0"
    "updateAirplaneModeStatus\0state\0"
    "updateBluetoothStatus\0updateSdCardStatus\0"
    "updateSystemDate\0date\0month\0year\0"
    "updateSystemTime\0hour\0min\0sec\0"
    "updateFlowParameter\0flowData\0"
    "updateEventTypeStatus\0event\0"
    "updateStableStatus\0tStableFlag\0"
    "updateMaskLeakStatus\0tLeakState\0"
    "updateEnableApap\0tEnFlag\0updateHypoApneaCount\0"
    "tCount\0updatebreathCount\0count\0"
    "updateLeakageCount\0updateTimeToHWClock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotificationTray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    1,   90,    2, 0x0a /* Public */,
       5,    1,   93,    2, 0x0a /* Public */,
       6,    1,   96,    2, 0x0a /* Public */,
       7,    3,   99,    2, 0x0a /* Public */,
      11,    3,  106,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,
      17,    1,  116,    2, 0x0a /* Public */,
      19,    1,  119,    2, 0x0a /* Public */,
      21,    1,  122,    2, 0x0a /* Public */,
      23,    1,  125,    2, 0x0a /* Public */,
      25,    1,  128,    2, 0x0a /* Public */,
      27,    1,  131,    2, 0x0a /* Public */,
      29,    1,  134,    2, 0x0a /* Public */,
      30,    0,  137,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::UInt,   18,
    QMetaType::Void, QMetaType::UInt,   20,
    QMetaType::Void, QMetaType::UInt,   22,
    QMetaType::Void, QMetaType::UInt,   24,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,

       0        // eod
};

void NotificationTray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotificationTray *_t = static_cast<NotificationTray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->updateAirplaneModeStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateBluetoothStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updateSdCardStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateSystemDate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->updateSystemTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->updateFlowParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateEventTypeStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->updateStableStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: _t->updateMaskLeakStatus((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: _t->updateEnableApap((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->updateHypoApneaCount((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 12: _t->updatebreathCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateLeakageCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->updateTimeToHWClock(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NotificationTray::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NotificationTray.data,
      qt_meta_data_NotificationTray,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NotificationTray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotificationTray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotificationTray.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NotificationTray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

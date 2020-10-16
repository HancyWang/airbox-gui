/****************************************************************************
** Meta object code from reading C++ file 'sleepreportwindowbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/sleepreportwindowbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sleepreportwindowbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SleepReportWindowBasic_t {
    QByteArrayData data[27];
    char stringdata0[437];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SleepReportWindowBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SleepReportWindowBasic_t qt_meta_stringdata_SleepReportWindowBasic = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SleepReportWindowBasic"
QT_MOC_LITERAL(1, 23, 18), // "getSleepReportData"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "tSleepReportType"
QT_MOC_LITERAL(4, 60, 20), // "sendSleepReportParam"
QT_MOC_LITERAL(5, 81, 19), // "sleepReportDuration"
QT_MOC_LITERAL(6, 101, 13), // "QFileInfoList"
QT_MOC_LITERAL(7, 115, 4), // "list"
QT_MOC_LITERAL(8, 120, 5), // "index"
QT_MOC_LITERAL(9, 126, 6), // "float*"
QT_MOC_LITERAL(10, 133, 11), // "tUsageHours"
QT_MOC_LITERAL(11, 145, 14), // "tEventsPerHour"
QT_MOC_LITERAL(12, 160, 8), // "tLeakage"
QT_MOC_LITERAL(13, 169, 4), // "int*"
QT_MOC_LITERAL(14, 174, 19), // "usedHours4PlusIndex"
QT_MOC_LITERAL(15, 194, 13), // "usedDaysIndex"
QT_MOC_LITERAL(16, 208, 13), // "tAverageUsage"
QT_MOC_LITERAL(17, 222, 33), // "showSleepReportMoreScreenFrom..."
QT_MOC_LITERAL(18, 256, 14), // "QFileInfoList&"
QT_MOC_LITERAL(19, 271, 12), // "directorList"
QT_MOC_LITERAL(20, 284, 26), // "showSleepReportWindowBasic"
QT_MOC_LITERAL(21, 311, 32), // "on_homeSleepReportButton_clicked"
QT_MOC_LITERAL(22, 344, 32), // "on_moreSleepReportButton_clicked"
QT_MOC_LITERAL(23, 377, 21), // "backToHomeSleepReport"
QT_MOC_LITERAL(24, 399, 21), // "showSleepReportScreen"
QT_MOC_LITERAL(25, 421, 8), // "QWidget*"
QT_MOC_LITERAL(26, 430, 6) // "parent"

    },
    "SleepReportWindowBasic\0getSleepReportData\0"
    "\0tSleepReportType\0sendSleepReportParam\0"
    "sleepReportDuration\0QFileInfoList\0"
    "list\0index\0float*\0tUsageHours\0"
    "tEventsPerHour\0tLeakage\0int*\0"
    "usedHours4PlusIndex\0usedDaysIndex\0"
    "tAverageUsage\0showSleepReportMoreScreenFromList\0"
    "QFileInfoList&\0directorList\0"
    "showSleepReportWindowBasic\0"
    "on_homeSleepReportButton_clicked\0"
    "on_moreSleepReportButton_clicked\0"
    "backToHomeSleepReport\0showSleepReportScreen\0"
    "QWidget*\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SleepReportWindowBasic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   10,   49,    2, 0x06 /* Public */,
      17,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,   73,    2, 0x0a /* Public */,
      21,    0,   74,    2, 0x08 /* Private */,
      22,    0,   75,    2, 0x08 /* Private */,
      23,    0,   76,    2, 0x08 /* Private */,
      24,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 9,    3,    5,    7,    8,   10,   11,   12,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,

       0        // eod
};

void SleepReportWindowBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SleepReportWindowBasic *_t = static_cast<SleepReportWindowBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getSleepReportData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< sendSleepReportParam(*)>(_a[2])),(*reinterpret_cast< const QFileInfoList(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< float*(*)>(_a[5])),(*reinterpret_cast< float*(*)>(_a[6])),(*reinterpret_cast< float*(*)>(_a[7])),(*reinterpret_cast< int*(*)>(_a[8])),(*reinterpret_cast< int*(*)>(_a[9])),(*reinterpret_cast< float*(*)>(_a[10]))); break;
        case 1: _t->showSleepReportMoreScreenFromList((*reinterpret_cast< QFileInfoList(*)>(_a[1]))); break;
        case 2: _t->showSleepReportWindowBasic(); break;
        case 3: _t->on_homeSleepReportButton_clicked(); break;
        case 4: _t->on_moreSleepReportButton_clicked(); break;
        case 5: _t->backToHomeSleepReport(); break;
        case 6: _t->showSleepReportScreen((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SleepReportWindowBasic::*)(int , sendSleepReportParam , const QFileInfoList & , int , float * , float * , float * , int * , int * , float * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SleepReportWindowBasic::getSleepReportData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SleepReportWindowBasic::*)(QFileInfoList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SleepReportWindowBasic::showSleepReportMoreScreenFromList)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SleepReportWindowBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SleepReportWindowBasic.data,
      qt_meta_data_SleepReportWindowBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SleepReportWindowBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SleepReportWindowBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SleepReportWindowBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SleepReportWindowBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SleepReportWindowBasic::getSleepReportData(int _t1, sendSleepReportParam _t2, const QFileInfoList & _t3, int _t4, float * _t5, float * _t6, float * _t7, int * _t8, int * _t9, float * _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SleepReportWindowBasic::showSleepReportMoreScreenFromList(QFileInfoList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

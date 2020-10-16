/****************************************************************************
** Meta object code from reading C++ file 'timewindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/timewindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timewindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeWindowClinical_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeWindowClinical_t qt_meta_stringdata_TimeWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TimeWindowClinical"
QT_MOC_LITERAL(1, 19, 11), // "dialogClose"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "screenClose"
QT_MOC_LITERAL(4, 44, 4), // "hour"
QT_MOC_LITERAL(5, 49, 6), // "minute"
QT_MOC_LITERAL(6, 56, 22), // "on_timeAccept_released"
QT_MOC_LITERAL(7, 79, 22), // "on_timeCancel_released"
QT_MOC_LITERAL(8, 102, 14), // "showTimeScreen"
QT_MOC_LITERAL(9, 117, 8), // "QWidget*"
QT_MOC_LITERAL(10, 126, 6), // "parent"
QT_MOC_LITERAL(11, 133, 11) // "colorEffect"

    },
    "TimeWindowClinical\0dialogClose\0\0"
    "screenClose\0hour\0minute\0on_timeAccept_released\0"
    "on_timeCancel_released\0showTimeScreen\0"
    "QWidget*\0parent\0colorEffect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeWindowClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    4,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   10,    4,    5,   11,

       0        // eod
};

void TimeWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeWindowClinical *_t = static_cast<TimeWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->screenClose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_timeAccept_released(); break;
        case 3: _t->on_timeCancel_released(); break;
        case 4: _t->showTimeScreen((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (TimeWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeWindowClinical::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TimeWindowClinical::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeWindowClinical::screenClose)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TimeWindowClinical.data,
      qt_meta_data_TimeWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TimeWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TimeWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TimeWindowClinical::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TimeWindowClinical::screenClose(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

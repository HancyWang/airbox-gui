/****************************************************************************
** Meta object code from reading C++ file 'datewindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/datewindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datewindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateWindowClinical_t {
    QByteArrayData data[16];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateWindowClinical_t qt_meta_stringdata_DateWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DateWindowClinical"
QT_MOC_LITERAL(1, 19, 11), // "dialogClose"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "screenClose"
QT_MOC_LITERAL(4, 44, 4), // "date"
QT_MOC_LITERAL(5, 49, 5), // "month"
QT_MOC_LITERAL(6, 55, 4), // "year"
QT_MOC_LITERAL(7, 60, 22), // "on_dateAccept_released"
QT_MOC_LITERAL(8, 83, 22), // "on_dateCancel_released"
QT_MOC_LITERAL(9, 106, 26), // "updateDateAsPerYearOrMonth"
QT_MOC_LITERAL(10, 133, 11), // "yearChanged"
QT_MOC_LITERAL(11, 145, 12), // "monthChanged"
QT_MOC_LITERAL(12, 158, 14), // "showDateScreen"
QT_MOC_LITERAL(13, 173, 8), // "QWidget*"
QT_MOC_LITERAL(14, 182, 6), // "parent"
QT_MOC_LITERAL(15, 189, 11) // "colorEffect"

    },
    "DateWindowClinical\0dialogClose\0\0"
    "screenClose\0date\0month\0year\0"
    "on_dateAccept_released\0on_dateCancel_released\0"
    "updateDateAsPerYearOrMonth\0yearChanged\0"
    "monthChanged\0showDateScreen\0QWidget*\0"
    "parent\0colorEffect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateWindowClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    3,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    5,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   14,    4,    5,    6,   15,

       0        // eod
};

void DateWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DateWindowClinical *_t = static_cast<DateWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->screenClose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_dateAccept_released(); break;
        case 3: _t->on_dateCancel_released(); break;
        case 4: _t->updateDateAsPerYearOrMonth(); break;
        case 5: _t->yearChanged(); break;
        case 6: _t->monthChanged(); break;
        case 7: _t->showDateScreen((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
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
            using _t = void (DateWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateWindowClinical::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DateWindowClinical::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateWindowClinical::screenClose)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DateWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DateWindowClinical.data,
      qt_meta_data_DateWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DateWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DateWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DateWindowClinical::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DateWindowClinical::screenClose(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

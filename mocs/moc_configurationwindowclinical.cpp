/****************************************************************************
** Meta object code from reading C++ file 'configurationwindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/configurationwindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configurationwindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigurationWindowClinical_t {
    QByteArrayData data[30];
    char stringdata0[468];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigurationWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigurationWindowClinical_t qt_meta_stringdata_ConfigurationWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 27), // "ConfigurationWindowClinical"
QT_MOC_LITERAL(1, 28, 14), // "showDateScreen"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 8), // "QWidget*"
QT_MOC_LITERAL(4, 53, 6), // "parent"
QT_MOC_LITERAL(5, 60, 4), // "date"
QT_MOC_LITERAL(6, 65, 5), // "month"
QT_MOC_LITERAL(7, 71, 4), // "year"
QT_MOC_LITERAL(8, 76, 11), // "colorEffect"
QT_MOC_LITERAL(9, 88, 14), // "showTimeScreen"
QT_MOC_LITERAL(10, 103, 4), // "hour"
QT_MOC_LITERAL(11, 108, 6), // "minute"
QT_MOC_LITERAL(12, 115, 22), // "showPressureUnitScreen"
QT_MOC_LITERAL(13, 138, 24), // "showRestoreDefaultScreen"
QT_MOC_LITERAL(14, 163, 19), // "showEraseDataScreen"
QT_MOC_LITERAL(15, 183, 16), // "updateSystemDate"
QT_MOC_LITERAL(16, 200, 16), // "updateSystemTime"
QT_MOC_LITERAL(17, 217, 3), // "min"
QT_MOC_LITERAL(18, 221, 3), // "sec"
QT_MOC_LITERAL(19, 225, 29), // "on_backConfiguration_released"
QT_MOC_LITERAL(20, 255, 19), // "dateButton_released"
QT_MOC_LITERAL(21, 275, 19), // "timeButton_released"
QT_MOC_LITERAL(22, 295, 21), // "pressureUnit_released"
QT_MOC_LITERAL(23, 317, 23), // "restoreDefault_released"
QT_MOC_LITERAL(24, 341, 18), // "eraseData_released"
QT_MOC_LITERAL(25, 360, 18), // "pressureUnitClosed"
QT_MOC_LITERAL(26, 379, 16), // "dateWindowClosed"
QT_MOC_LITERAL(27, 396, 16), // "timeWindowClosed"
QT_MOC_LITERAL(28, 413, 22), // "timeUpdateTimerTimeout"
QT_MOC_LITERAL(29, 436, 31) // "showConfigurationClinicalScreen"

    },
    "ConfigurationWindowClinical\0showDateScreen\0"
    "\0QWidget*\0parent\0date\0month\0year\0"
    "colorEffect\0showTimeScreen\0hour\0minute\0"
    "showPressureUnitScreen\0showRestoreDefaultScreen\0"
    "showEraseDataScreen\0updateSystemDate\0"
    "updateSystemTime\0min\0sec\0"
    "on_backConfiguration_released\0"
    "dateButton_released\0timeButton_released\0"
    "pressureUnit_released\0restoreDefault_released\0"
    "eraseData_released\0pressureUnitClosed\0"
    "dateWindowClosed\0timeWindowClosed\0"
    "timeUpdateTimerTimeout\0"
    "showConfigurationClinicalScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigurationWindowClinical[] = {

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
       1,    5,  104,    2, 0x06 /* Public */,
       9,    4,  115,    2, 0x06 /* Public */,
      12,    0,  124,    2, 0x06 /* Public */,
      13,    0,  125,    2, 0x06 /* Public */,
      14,    0,  126,    2, 0x06 /* Public */,
      15,    3,  127,    2, 0x06 /* Public */,
      16,    3,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  141,    2, 0x08 /* Private */,
      20,    0,  142,    2, 0x08 /* Private */,
      21,    0,  143,    2, 0x08 /* Private */,
      22,    0,  144,    2, 0x08 /* Private */,
      23,    0,  145,    2, 0x08 /* Private */,
      24,    0,  146,    2, 0x08 /* Private */,
      25,    0,  147,    2, 0x08 /* Private */,
      26,    3,  148,    2, 0x08 /* Private */,
      27,    2,  155,    2, 0x08 /* Private */,
      28,    0,  160,    2, 0x08 /* Private */,
      29,    0,  161,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    5,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,   10,   11,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   17,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigurationWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigurationWindowClinical *_t = static_cast<ConfigurationWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showDateScreen((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: _t->showTimeScreen((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 2: _t->showPressureUnitScreen(); break;
        case 3: _t->showRestoreDefaultScreen(); break;
        case 4: _t->showEraseDataScreen(); break;
        case 5: _t->updateSystemDate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->updateSystemTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->on_backConfiguration_released(); break;
        case 8: _t->dateButton_released(); break;
        case 9: _t->timeButton_released(); break;
        case 10: _t->pressureUnit_released(); break;
        case 11: _t->restoreDefault_released(); break;
        case 12: _t->eraseData_released(); break;
        case 13: _t->pressureUnitClosed(); break;
        case 14: _t->dateWindowClosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->timeWindowClosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->timeUpdateTimerTimeout(); break;
        case 17: _t->showConfigurationClinicalScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
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
            using _t = void (ConfigurationWindowClinical::*)(QWidget * , int , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::showDateScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)(QWidget * , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::showTimeScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::showPressureUnitScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::showRestoreDefaultScreen)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::showEraseDataScreen)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::updateSystemDate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindowClinical::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigurationWindowClinical::updateSystemTime)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfigurationWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigurationWindowClinical.data,
      qt_meta_data_ConfigurationWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConfigurationWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigurationWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigurationWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfigurationWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ConfigurationWindowClinical::showDateScreen(QWidget * _t1, int _t2, int _t3, int _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConfigurationWindowClinical::showTimeScreen(QWidget * _t1, int _t2, int _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ConfigurationWindowClinical::showPressureUnitScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ConfigurationWindowClinical::showRestoreDefaultScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ConfigurationWindowClinical::showEraseDataScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ConfigurationWindowClinical::updateSystemDate(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ConfigurationWindowClinical::updateSystemTime(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

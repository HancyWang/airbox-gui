/****************************************************************************
** Meta object code from reading C++ file 'homewindowbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/homewindowbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homewindowbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HomeWindowBasic_t {
    QByteArrayData data[18];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeWindowBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeWindowBasic_t qt_meta_stringdata_HomeWindowBasic = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HomeWindowBasic"
QT_MOC_LITERAL(1, 16, 19), // "showHomeWindowBasic"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 26), // "showSleepReportWindowBasic"
QT_MOC_LITERAL(4, 64, 26), // "showMaskOptionsWindowBasic"
QT_MOC_LITERAL(5, 91, 23), // "showSettingsWindowBasic"
QT_MOC_LITERAL(6, 115, 23), // "showPasswordEnterScreen"
QT_MOC_LITERAL(7, 139, 10), // "const int*"
QT_MOC_LITERAL(8, 150, 8), // "password"
QT_MOC_LITERAL(9, 159, 22), // "showClinicalHomeScreen"
QT_MOC_LITERAL(10, 182, 22), // "therapyButton_released"
QT_MOC_LITERAL(11, 205, 26), // "sleepReportButton_released"
QT_MOC_LITERAL(12, 232, 25), // "maskOptionButton_released"
QT_MOC_LITERAL(13, 258, 23), // "settignsButton_released"
QT_MOC_LITERAL(14, 282, 20), // "timerClinicalTimeOut"
QT_MOC_LITERAL(15, 303, 25), // "passwordCheckWindowClosed"
QT_MOC_LITERAL(16, 329, 21), // "on_frescaLogo_pressed"
QT_MOC_LITERAL(17, 351, 22) // "on_frescaLogo_released"

    },
    "HomeWindowBasic\0showHomeWindowBasic\0"
    "\0showSleepReportWindowBasic\0"
    "showMaskOptionsWindowBasic\0"
    "showSettingsWindowBasic\0showPasswordEnterScreen\0"
    "const int*\0password\0showClinicalHomeScreen\0"
    "therapyButton_released\0"
    "sleepReportButton_released\0"
    "maskOptionButton_released\0"
    "settignsButton_released\0timerClinicalTimeOut\0"
    "passwordCheckWindowClosed\0"
    "on_frescaLogo_pressed\0on_frescaLogo_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeWindowBasic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       9,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

 // slots: parameters
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

void HomeWindowBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HomeWindowBasic *_t = static_cast<HomeWindowBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showHomeWindowBasic(); break;
        case 1: _t->showSleepReportWindowBasic(); break;
        case 2: _t->showMaskOptionsWindowBasic(); break;
        case 3: _t->showSettingsWindowBasic(); break;
        case 4: _t->showPasswordEnterScreen((*reinterpret_cast< const int*(*)>(_a[1]))); break;
        case 5: _t->showClinicalHomeScreen(); break;
        case 6: _t->therapyButton_released(); break;
        case 7: _t->sleepReportButton_released(); break;
        case 8: _t->maskOptionButton_released(); break;
        case 9: _t->settignsButton_released(); break;
        case 10: _t->timerClinicalTimeOut(); break;
        case 11: _t->passwordCheckWindowClosed(); break;
        case 12: _t->on_frescaLogo_pressed(); break;
        case 13: _t->on_frescaLogo_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HomeWindowBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showHomeWindowBasic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HomeWindowBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showSleepReportWindowBasic)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HomeWindowBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showMaskOptionsWindowBasic)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HomeWindowBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showSettingsWindowBasic)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HomeWindowBasic::*)(const int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showPasswordEnterScreen)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HomeWindowBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomeWindowBasic::showClinicalHomeScreen)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HomeWindowBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HomeWindowBasic.data,
      qt_meta_data_HomeWindowBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HomeWindowBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeWindowBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWindowBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int HomeWindowBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void HomeWindowBasic::showHomeWindowBasic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HomeWindowBasic::showSleepReportWindowBasic()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HomeWindowBasic::showMaskOptionsWindowBasic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HomeWindowBasic::showSettingsWindowBasic()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void HomeWindowBasic::showPasswordEnterScreen(const int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HomeWindowBasic::showClinicalHomeScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'warninginfoscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/warninginfoscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warninginfoscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WarningInfoScreen_t {
    QByteArrayData data[11];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WarningInfoScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WarningInfoScreen_t qt_meta_stringdata_WarningInfoScreen = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WarningInfoScreen"
QT_MOC_LITERAL(1, 18, 27), // "beforeStartTherapyProcedure"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "updateStartStopTherapyDetails"
QT_MOC_LITERAL(4, 77, 22), // "startPowerOffProcedure"
QT_MOC_LITERAL(5, 100, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(6, 123, 23), // "on_disabledTimerTimeout"
QT_MOC_LITERAL(7, 147, 19), // "updateAndShowScreen"
QT_MOC_LITERAL(8, 167, 4), // "int*"
QT_MOC_LITERAL(9, 172, 6), // "tArray"
QT_MOC_LITERAL(10, 179, 6) // "tCount"

    },
    "WarningInfoScreen\0beforeStartTherapyProcedure\0"
    "\0updateStartStopTherapyDetails\0"
    "startPowerOffProcedure\0on_closeButton_clicked\0"
    "on_disabledTimerTimeout\0updateAndShowScreen\0"
    "int*\0tArray\0tCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WarningInfoScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,

       0        // eod
};

void WarningInfoScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WarningInfoScreen *_t = static_cast<WarningInfoScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beforeStartTherapyProcedure(); break;
        case 1: _t->updateStartStopTherapyDetails(); break;
        case 2: _t->startPowerOffProcedure(); break;
        case 3: _t->on_closeButton_clicked(); break;
        case 4: _t->on_disabledTimerTimeout(); break;
        case 5: _t->updateAndShowScreen((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WarningInfoScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarningInfoScreen::beforeStartTherapyProcedure)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WarningInfoScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarningInfoScreen::updateStartStopTherapyDetails)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WarningInfoScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarningInfoScreen::startPowerOffProcedure)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WarningInfoScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WarningInfoScreen.data,
      qt_meta_data_WarningInfoScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WarningInfoScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarningInfoScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WarningInfoScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WarningInfoScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WarningInfoScreen::beforeStartTherapyProcedure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WarningInfoScreen::updateStartStopTherapyDetails()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WarningInfoScreen::startPowerOffProcedure()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

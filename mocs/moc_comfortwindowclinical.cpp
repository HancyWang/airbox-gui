/****************************************************************************
** Meta object code from reading C++ file 'comfortwindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/comfortwindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comfortwindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComfortWindowClinical_t {
    QByteArrayData data[17];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComfortWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComfortWindowClinical_t qt_meta_stringdata_ComfortWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ComfortWindowClinical"
QT_MOC_LITERAL(1, 22, 19), // "showGoToSleepScreen"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 18), // "showRampTimeScreen"
QT_MOC_LITERAL(4, 62, 23), // "showExhaleComfortScreen"
QT_MOC_LITERAL(5, 86, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(6, 109, 23), // "on_backComfort_released"
QT_MOC_LITERAL(7, 133, 24), // "goToSleepButton_released"
QT_MOC_LITERAL(8, 158, 19), // "rampButton_released"
QT_MOC_LITERAL(9, 178, 28), // "exhaleComfortButton_released"
QT_MOC_LITERAL(10, 207, 29), // "goToSleepButtonSwitch_clicked"
QT_MOC_LITERAL(11, 237, 33), // "exhaleComfortButtonSwitch_cli..."
QT_MOC_LITERAL(12, 271, 24), // "rampButtonSwitch_clicked"
QT_MOC_LITERAL(13, 296, 15), // "goToSleepClosed"
QT_MOC_LITERAL(14, 312, 10), // "rampClosed"
QT_MOC_LITERAL(15, 323, 18), // "exhaleWindowClosed"
QT_MOC_LITERAL(16, 342, 25) // "showComfortClinicalScreen"

    },
    "ComfortWindowClinical\0showGoToSleepScreen\0"
    "\0showRampTimeScreen\0showExhaleComfortScreen\0"
    "writeParameterToEeprom\0on_backComfort_released\0"
    "goToSleepButton_released\0rampButton_released\0"
    "exhaleComfortButton_released\0"
    "goToSleepButtonSwitch_clicked\0"
    "exhaleComfortButtonSwitch_clicked\0"
    "rampButtonSwitch_clicked\0goToSleepClosed\0"
    "rampClosed\0exhaleWindowClosed\0"
    "showComfortClinicalScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComfortWindowClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ComfortWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComfortWindowClinical *_t = static_cast<ComfortWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showGoToSleepScreen(); break;
        case 1: _t->showRampTimeScreen(); break;
        case 2: _t->showExhaleComfortScreen(); break;
        case 3: _t->writeParameterToEeprom(); break;
        case 4: _t->on_backComfort_released(); break;
        case 5: _t->goToSleepButton_released(); break;
        case 6: _t->rampButton_released(); break;
        case 7: _t->exhaleComfortButton_released(); break;
        case 8: _t->goToSleepButtonSwitch_clicked(); break;
        case 9: _t->exhaleComfortButtonSwitch_clicked(); break;
        case 10: _t->rampButtonSwitch_clicked(); break;
        case 11: _t->goToSleepClosed(); break;
        case 12: _t->rampClosed(); break;
        case 13: _t->exhaleWindowClosed(); break;
        case 14: _t->showComfortClinicalScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComfortWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfortWindowClinical::showGoToSleepScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComfortWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfortWindowClinical::showRampTimeScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ComfortWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfortWindowClinical::showExhaleComfortScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ComfortWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComfortWindowClinical::writeParameterToEeprom)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ComfortWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ComfortWindowClinical.data,
      qt_meta_data_ComfortWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ComfortWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComfortWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComfortWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ComfortWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ComfortWindowClinical::showGoToSleepScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ComfortWindowClinical::showRampTimeScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ComfortWindowClinical::showExhaleComfortScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ComfortWindowClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

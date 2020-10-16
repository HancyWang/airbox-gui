/****************************************************************************
** Meta object code from reading C++ file 'parametertunningscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/parametertunningscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametertunningscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParameterTunningScreen_t {
    QByteArrayData data[26];
    char stringdata0[547];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParameterTunningScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParameterTunningScreen_t qt_meta_stringdata_ParameterTunningScreen = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ParameterTunningScreen"
QT_MOC_LITERAL(1, 23, 22), // "updateTunningParameter"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "int*"
QT_MOC_LITERAL(4, 52, 5), // "param"
QT_MOC_LITERAL(5, 58, 19), // "updateFlowThreshold"
QT_MOC_LITERAL(6, 78, 9), // "threshold"
QT_MOC_LITERAL(7, 88, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(8, 111, 30), // "readTunningParameterFromEeprom"
QT_MOC_LITERAL(9, 142, 26), // "writeTuneParameterToEeprom"
QT_MOC_LITERAL(10, 169, 9), // "tuneParam"
QT_MOC_LITERAL(11, 179, 32), // "on_backParameterTunning_released"
QT_MOC_LITERAL(12, 212, 25), // "on_paramIncrement_pressed"
QT_MOC_LITERAL(13, 238, 25), // "on_paramDecrement_pressed"
QT_MOC_LITERAL(14, 264, 30), // "sendTunningParametersFirstTime"
QT_MOC_LITERAL(15, 295, 20), // "on_TuneButtonClicked"
QT_MOC_LITERAL(16, 316, 31), // "restoreDefaultTunningParameters"
QT_MOC_LITERAL(17, 348, 33), // "updateTunningParametersFromEe..."
QT_MOC_LITERAL(18, 382, 12), // "QStringList&"
QT_MOC_LITERAL(19, 395, 12), // "listTuneData"
QT_MOC_LITERAL(20, 408, 26), // "showParameterTunningScreen"
QT_MOC_LITERAL(21, 435, 8), // "QWidget*"
QT_MOC_LITERAL(22, 444, 6), // "parent"
QT_MOC_LITERAL(23, 451, 25), // "sendTunningParameterToPRU"
QT_MOC_LITERAL(24, 477, 34), // "restoreDefaultTunningParamete..."
QT_MOC_LITERAL(25, 512, 34) // "updateFlowBarrelTypeAndDefaul..."

    },
    "ParameterTunningScreen\0updateTunningParameter\0"
    "\0int*\0param\0updateFlowThreshold\0"
    "threshold\0writeParameterToEeprom\0"
    "readTunningParameterFromEeprom\0"
    "writeTuneParameterToEeprom\0tuneParam\0"
    "on_backParameterTunning_released\0"
    "on_paramIncrement_pressed\0"
    "on_paramDecrement_pressed\0"
    "sendTunningParametersFirstTime\0"
    "on_TuneButtonClicked\0"
    "restoreDefaultTunningParameters\0"
    "updateTunningParametersFromEeprom\0"
    "QStringList&\0listTuneData\0"
    "showParameterTunningScreen\0QWidget*\0"
    "parent\0sendTunningParameterToPRU\0"
    "restoreDefaultTunningParametersNew\0"
    "updateFlowBarrelTypeAndDefaultData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParameterTunningScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       7,    0,  100,    2, 0x06 /* Public */,
       8,    0,  101,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    1,  111,    2, 0x0a /* Public */,
      20,    1,  114,    2, 0x0a /* Public */,
      23,    0,  117,    2, 0x0a /* Public */,
      24,    0,  118,    2, 0x0a /* Public */,
      25,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParameterTunningScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParameterTunningScreen *_t = static_cast<ParameterTunningScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTunningParameter((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: _t->updateFlowThreshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->writeParameterToEeprom(); break;
        case 3: _t->readTunningParameterFromEeprom(); break;
        case 4: _t->writeTuneParameterToEeprom((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 5: _t->on_backParameterTunning_released(); break;
        case 6: _t->on_paramIncrement_pressed(); break;
        case 7: _t->on_paramDecrement_pressed(); break;
        case 8: _t->sendTunningParametersFirstTime(); break;
        case 9: _t->on_TuneButtonClicked(); break;
        case 10: _t->restoreDefaultTunningParameters(); break;
        case 11: _t->updateTunningParametersFromEeprom((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 12: _t->showParameterTunningScreen((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 13: _t->sendTunningParameterToPRU(); break;
        case 14: _t->restoreDefaultTunningParametersNew(); break;
        case 15: _t->updateFlowBarrelTypeAndDefaultData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
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
            using _t = void (ParameterTunningScreen::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParameterTunningScreen::updateTunningParameter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ParameterTunningScreen::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParameterTunningScreen::updateFlowThreshold)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ParameterTunningScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParameterTunningScreen::writeParameterToEeprom)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ParameterTunningScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParameterTunningScreen::readTunningParameterFromEeprom)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ParameterTunningScreen::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParameterTunningScreen::writeTuneParameterToEeprom)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParameterTunningScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParameterTunningScreen.data,
      qt_meta_data_ParameterTunningScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ParameterTunningScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParameterTunningScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterTunningScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ParameterTunningScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ParameterTunningScreen::updateTunningParameter(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParameterTunningScreen::updateFlowThreshold(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ParameterTunningScreen::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ParameterTunningScreen::readTunningParameterFromEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ParameterTunningScreen::writeTuneParameterToEeprom(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

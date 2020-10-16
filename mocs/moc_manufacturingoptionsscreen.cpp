/****************************************************************************
** Meta object code from reading C++ file 'manufacturingoptionsscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/manufacturingoptionsscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manufacturingoptionsscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManufacturingOptionsScreen_t {
    QByteArrayData data[18];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManufacturingOptionsScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManufacturingOptionsScreen_t qt_meta_stringdata_ManufacturingOptionsScreen = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ManufacturingOptionsScreen"
QT_MOC_LITERAL(1, 27, 23), // "showPasswordEnterScreen"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 10), // "const int*"
QT_MOC_LITERAL(4, 63, 8), // "password"
QT_MOC_LITERAL(5, 72, 32), // "showManufacturingDiagnosisScreen"
QT_MOC_LITERAL(6, 105, 28), // "showManufacturingSetupScreen"
QT_MOC_LITERAL(7, 134, 26), // "showParameterTunningScreen"
QT_MOC_LITERAL(8, 161, 20), // "showBlowerTestScreen"
QT_MOC_LITERAL(9, 182, 36), // "on_backManufacturingOptions_r..."
QT_MOC_LITERAL(10, 219, 32), // "menufacturingDiagButton_released"
QT_MOC_LITERAL(11, 252, 33), // "menufacturingSetupButton_rele..."
QT_MOC_LITERAL(12, 286, 25), // "blowerTestButton_released"
QT_MOC_LITERAL(13, 312, 28), // "parameterTuneButton_released"
QT_MOC_LITERAL(14, 341, 25), // "passwordCheckWindowClosed"
QT_MOC_LITERAL(15, 367, 30), // "showManufacturingOptionsScreen"
QT_MOC_LITERAL(16, 398, 8), // "QWidget*"
QT_MOC_LITERAL(17, 407, 6) // "parent"

    },
    "ManufacturingOptionsScreen\0"
    "showPasswordEnterScreen\0\0const int*\0"
    "password\0showManufacturingDiagnosisScreen\0"
    "showManufacturingSetupScreen\0"
    "showParameterTunningScreen\0"
    "showBlowerTestScreen\0"
    "on_backManufacturingOptions_released\0"
    "menufacturingDiagButton_released\0"
    "menufacturingSetupButton_released\0"
    "blowerTestButton_released\0"
    "parameterTuneButton_released\0"
    "passwordCheckWindowClosed\0"
    "showManufacturingOptionsScreen\0QWidget*\0"
    "parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManufacturingOptionsScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void ManufacturingOptionsScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManufacturingOptionsScreen *_t = static_cast<ManufacturingOptionsScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showPasswordEnterScreen((*reinterpret_cast< const int*(*)>(_a[1]))); break;
        case 1: _t->showManufacturingDiagnosisScreen(); break;
        case 2: _t->showManufacturingSetupScreen(); break;
        case 3: _t->showParameterTunningScreen(); break;
        case 4: _t->showBlowerTestScreen(); break;
        case 5: _t->on_backManufacturingOptions_released(); break;
        case 6: _t->menufacturingDiagButton_released(); break;
        case 7: _t->menufacturingSetupButton_released(); break;
        case 8: _t->blowerTestButton_released(); break;
        case 9: _t->parameterTuneButton_released(); break;
        case 10: _t->passwordCheckWindowClosed(); break;
        case 11: _t->showManufacturingOptionsScreen((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
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
            using _t = void (ManufacturingOptionsScreen::*)(const int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingOptionsScreen::showPasswordEnterScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ManufacturingOptionsScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingOptionsScreen::showManufacturingDiagnosisScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ManufacturingOptionsScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingOptionsScreen::showManufacturingSetupScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ManufacturingOptionsScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingOptionsScreen::showParameterTunningScreen)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ManufacturingOptionsScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingOptionsScreen::showBlowerTestScreen)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManufacturingOptionsScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManufacturingOptionsScreen.data,
      qt_meta_data_ManufacturingOptionsScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManufacturingOptionsScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManufacturingOptionsScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManufacturingOptionsScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ManufacturingOptionsScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ManufacturingOptionsScreen::showPasswordEnterScreen(const int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ManufacturingOptionsScreen::showManufacturingDiagnosisScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ManufacturingOptionsScreen::showManufacturingSetupScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ManufacturingOptionsScreen::showParameterTunningScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ManufacturingOptionsScreen::showBlowerTestScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

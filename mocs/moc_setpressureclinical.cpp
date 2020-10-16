/****************************************************************************
** Meta object code from reading C++ file 'setpressureclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/setpressureclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setpressureclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetPressureClinical_t {
    QByteArrayData data[12];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetPressureClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetPressureClinical_t qt_meta_stringdata_SetPressureClinical = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SetPressureClinical"
QT_MOC_LITERAL(1, 20, 11), // "dialogClose"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(4, 56, 29), // "on_setPressureAccept_released"
QT_MOC_LITERAL(5, 86, 29), // "on_setPressureCancel_released"
QT_MOC_LITERAL(6, 116, 34), // "on_setPressureSlider_sliderPr..."
QT_MOC_LITERAL(7, 151, 33), // "on_setPressureSlider_valueCha..."
QT_MOC_LITERAL(8, 185, 5), // "value"
QT_MOC_LITERAL(9, 191, 31), // "on_setPressureIncrement_pressed"
QT_MOC_LITERAL(10, 223, 31), // "on_setPressureDecrement_pressed"
QT_MOC_LITERAL(11, 255, 21) // "showSetPressureScreen"

    },
    "SetPressureClinical\0dialogClose\0\0"
    "writeParameterToEeprom\0"
    "on_setPressureAccept_released\0"
    "on_setPressureCancel_released\0"
    "on_setPressureSlider_sliderPressed\0"
    "on_setPressureSlider_valueChanged\0"
    "value\0on_setPressureIncrement_pressed\0"
    "on_setPressureDecrement_pressed\0"
    "showSetPressureScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetPressureClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SetPressureClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetPressureClinical *_t = static_cast<SetPressureClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->writeParameterToEeprom(); break;
        case 2: _t->on_setPressureAccept_released(); break;
        case 3: _t->on_setPressureCancel_released(); break;
        case 4: _t->on_setPressureSlider_sliderPressed(); break;
        case 5: _t->on_setPressureSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_setPressureIncrement_pressed(); break;
        case 7: _t->on_setPressureDecrement_pressed(); break;
        case 8: _t->showSetPressureScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetPressureClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPressureClinical::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetPressureClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPressureClinical::writeParameterToEeprom)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SetPressureClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetPressureClinical.data,
      qt_meta_data_SetPressureClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SetPressureClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetPressureClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetPressureClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SetPressureClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SetPressureClinical::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SetPressureClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

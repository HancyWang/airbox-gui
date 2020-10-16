/****************************************************************************
** Meta object code from reading C++ file 'setminpressureclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/setminpressureclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setminpressureclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetMinPressureClinical_t {
    QByteArrayData data[12];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetMinPressureClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetMinPressureClinical_t qt_meta_stringdata_SetMinPressureClinical = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SetMinPressureClinical"
QT_MOC_LITERAL(1, 23, 11), // "dialogClose"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(4, 59, 21), // "showMinPressureScreen"
QT_MOC_LITERAL(5, 81, 32), // "on_setMinPressureAccept_released"
QT_MOC_LITERAL(6, 114, 32), // "on_setMinPressureCancel_released"
QT_MOC_LITERAL(7, 147, 34), // "on_setMinPressureIncrement_pr..."
QT_MOC_LITERAL(8, 182, 34), // "on_setMinPressureDecrement_pr..."
QT_MOC_LITERAL(9, 217, 37), // "on_setMinPressureSlider_slide..."
QT_MOC_LITERAL(10, 255, 36), // "on_setMinPressureSlider_value..."
QT_MOC_LITERAL(11, 292, 5) // "value"

    },
    "SetMinPressureClinical\0dialogClose\0\0"
    "writeParameterToEeprom\0showMinPressureScreen\0"
    "on_setMinPressureAccept_released\0"
    "on_setMinPressureCancel_released\0"
    "on_setMinPressureIncrement_pressed\0"
    "on_setMinPressureDecrement_pressed\0"
    "on_setMinPressureSlider_sliderPressed\0"
    "on_setMinPressureSlider_valueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetMinPressureClinical[] = {

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
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void SetMinPressureClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetMinPressureClinical *_t = static_cast<SetMinPressureClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->writeParameterToEeprom(); break;
        case 2: _t->showMinPressureScreen(); break;
        case 3: _t->on_setMinPressureAccept_released(); break;
        case 4: _t->on_setMinPressureCancel_released(); break;
        case 5: _t->on_setMinPressureIncrement_pressed(); break;
        case 6: _t->on_setMinPressureDecrement_pressed(); break;
        case 7: _t->on_setMinPressureSlider_sliderPressed(); break;
        case 8: _t->on_setMinPressureSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetMinPressureClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetMinPressureClinical::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetMinPressureClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetMinPressureClinical::writeParameterToEeprom)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SetMinPressureClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetMinPressureClinical.data,
      qt_meta_data_SetMinPressureClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SetMinPressureClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetMinPressureClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetMinPressureClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SetMinPressureClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SetMinPressureClinical::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SetMinPressureClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

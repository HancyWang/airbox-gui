/****************************************************************************
** Meta object code from reading C++ file 'displaydimbrightnesssettingsbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/displaydimbrightnesssettingsbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaydimbrightnesssettingsbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplayDimBrightnessSettingsBasic_t {
    QByteArrayData data[12];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayDimBrightnessSettingsBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayDimBrightnessSettingsBasic_t qt_meta_stringdata_DisplayDimBrightnessSettingsBasic = {
    {
QT_MOC_LITERAL(0, 0, 33), // "DisplayDimBrightnessSettingsB..."
QT_MOC_LITERAL(1, 34, 11), // "dialogClose"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(4, 70, 28), // "on_displayDimAccept_released"
QT_MOC_LITERAL(5, 99, 28), // "on_displayDimCancel_released"
QT_MOC_LITERAL(6, 128, 32), // "on_displayDimSlider_valueChanged"
QT_MOC_LITERAL(7, 161, 5), // "value"
QT_MOC_LITERAL(8, 167, 33), // "on_displayDimSlider_sliderPre..."
QT_MOC_LITERAL(9, 201, 30), // "on_displayDimIncrement_pressed"
QT_MOC_LITERAL(10, 232, 30), // "on_displayDimDecrement_pressed"
QT_MOC_LITERAL(11, 263, 30) // "showDisplayDimBrightnessScreen"

    },
    "DisplayDimBrightnessSettingsBasic\0"
    "dialogClose\0\0writeParameterToEeprom\0"
    "on_displayDimAccept_released\0"
    "on_displayDimCancel_released\0"
    "on_displayDimSlider_valueChanged\0value\0"
    "on_displayDimSlider_sliderPressed\0"
    "on_displayDimIncrement_pressed\0"
    "on_displayDimDecrement_pressed\0"
    "showDisplayDimBrightnessScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayDimBrightnessSettingsBasic[] = {

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
       6,    1,   63,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplayDimBrightnessSettingsBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplayDimBrightnessSettingsBasic *_t = static_cast<DisplayDimBrightnessSettingsBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->writeParameterToEeprom(); break;
        case 2: _t->on_displayDimAccept_released(); break;
        case 3: _t->on_displayDimCancel_released(); break;
        case 4: _t->on_displayDimSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_displayDimSlider_sliderPressed(); break;
        case 6: _t->on_displayDimIncrement_pressed(); break;
        case 7: _t->on_displayDimDecrement_pressed(); break;
        case 8: _t->showDisplayDimBrightnessScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DisplayDimBrightnessSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplayDimBrightnessSettingsBasic::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DisplayDimBrightnessSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplayDimBrightnessSettingsBasic::writeParameterToEeprom)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DisplayDimBrightnessSettingsBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DisplayDimBrightnessSettingsBasic.data,
      qt_meta_data_DisplayDimBrightnessSettingsBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DisplayDimBrightnessSettingsBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayDimBrightnessSettingsBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayDimBrightnessSettingsBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DisplayDimBrightnessSettingsBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DisplayDimBrightnessSettingsBasic::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DisplayDimBrightnessSettingsBasic::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

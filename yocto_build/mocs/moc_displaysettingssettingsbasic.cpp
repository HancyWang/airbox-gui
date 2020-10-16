/****************************************************************************
** Meta object code from reading C++ file 'displaysettingssettingsbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/displaysettingssettingsbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaysettingssettingsbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplaySettingsSettingsBasic_t {
    QByteArrayData data[10];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplaySettingsSettingsBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplaySettingsSettingsBasic_t qt_meta_stringdata_DisplaySettingsSettingsBasic = {
    {
QT_MOC_LITERAL(0, 0, 28), // "DisplaySettingsSettingsBasic"
QT_MOC_LITERAL(1, 29, 26), // "showBrightnessAdjustScreen"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 30), // "showDisplayDimBrightnessScreen"
QT_MOC_LITERAL(4, 88, 31), // "on_backDisplaySettings_released"
QT_MOC_LITERAL(5, 120, 34), // "brightnessDisplaySettings_rel..."
QT_MOC_LITERAL(6, 155, 35), // "dimDurationDisplaySettings_re..."
QT_MOC_LITERAL(7, 191, 22), // "brightnessAdjustClosed"
QT_MOC_LITERAL(8, 214, 16), // "displayDimClosed"
QT_MOC_LITERAL(9, 231, 25) // "showDisplaySettingsScreen"

    },
    "DisplaySettingsSettingsBasic\0"
    "showBrightnessAdjustScreen\0\0"
    "showDisplayDimBrightnessScreen\0"
    "on_backDisplaySettings_released\0"
    "brightnessDisplaySettings_released\0"
    "dimDurationDisplaySettings_released\0"
    "brightnessAdjustClosed\0displayDimClosed\0"
    "showDisplaySettingsScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplaySettingsSettingsBasic[] = {

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
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x0a /* Public */,

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

       0        // eod
};

void DisplaySettingsSettingsBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplaySettingsSettingsBasic *_t = static_cast<DisplaySettingsSettingsBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showBrightnessAdjustScreen(); break;
        case 1: _t->showDisplayDimBrightnessScreen(); break;
        case 2: _t->on_backDisplaySettings_released(); break;
        case 3: _t->brightnessDisplaySettings_released(); break;
        case 4: _t->dimDurationDisplaySettings_released(); break;
        case 5: _t->brightnessAdjustClosed(); break;
        case 6: _t->displayDimClosed(); break;
        case 7: _t->showDisplaySettingsScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DisplaySettingsSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplaySettingsSettingsBasic::showBrightnessAdjustScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DisplaySettingsSettingsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplaySettingsSettingsBasic::showDisplayDimBrightnessScreen)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DisplaySettingsSettingsBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DisplaySettingsSettingsBasic.data,
      qt_meta_data_DisplaySettingsSettingsBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DisplaySettingsSettingsBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplaySettingsSettingsBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplaySettingsSettingsBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DisplaySettingsSettingsBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DisplaySettingsSettingsBasic::showBrightnessAdjustScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DisplaySettingsSettingsBasic::showDisplayDimBrightnessScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

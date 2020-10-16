/****************************************************************************
** Meta object code from reading C++ file 'brightnessoffsetscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/brightnessoffsetscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brightnessoffsetscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrightnessOffsetScreen_t {
    QByteArrayData data[8];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrightnessOffsetScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrightnessOffsetScreen_t qt_meta_stringdata_BrightnessOffsetScreen = {
    {
QT_MOC_LITERAL(0, 0, 22), // "BrightnessOffsetScreen"
QT_MOC_LITERAL(1, 23, 11), // "dialogClose"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 36), // "on_brightnessOffsetIncrement_..."
QT_MOC_LITERAL(4, 73, 36), // "on_brightnessOffsetDecrement_..."
QT_MOC_LITERAL(5, 110, 34), // "on_brightnessOffsetAccept_rel..."
QT_MOC_LITERAL(6, 145, 34), // "on_brightnessOffsetCancel_rel..."
QT_MOC_LITERAL(7, 180, 26) // "showBrightnessOffsetScreen"

    },
    "BrightnessOffsetScreen\0dialogClose\0\0"
    "on_brightnessOffsetIncrement_pressed\0"
    "on_brightnessOffsetDecrement_pressed\0"
    "on_brightnessOffsetAccept_released\0"
    "on_brightnessOffsetCancel_released\0"
    "showBrightnessOffsetScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrightnessOffsetScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BrightnessOffsetScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrightnessOffsetScreen *_t = static_cast<BrightnessOffsetScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->on_brightnessOffsetIncrement_pressed(); break;
        case 2: _t->on_brightnessOffsetDecrement_pressed(); break;
        case 3: _t->on_brightnessOffsetAccept_released(); break;
        case 4: _t->on_brightnessOffsetCancel_released(); break;
        case 5: _t->showBrightnessOffsetScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BrightnessOffsetScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrightnessOffsetScreen::dialogClose)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BrightnessOffsetScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BrightnessOffsetScreen.data,
      qt_meta_data_BrightnessOffsetScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BrightnessOffsetScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrightnessOffsetScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrightnessOffsetScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BrightnessOffsetScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BrightnessOffsetScreen::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

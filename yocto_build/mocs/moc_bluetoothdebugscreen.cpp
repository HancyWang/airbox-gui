/****************************************************************************
** Meta object code from reading C++ file 'bluetoothdebugscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/bluetoothdebugscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothdebugscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluetoothDebugScreen_t {
    QByteArrayData data[9];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothDebugScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothDebugScreen_t qt_meta_stringdata_BluetoothDebugScreen = {
    {
QT_MOC_LITERAL(0, 0, 20), // "BluetoothDebugScreen"
QT_MOC_LITERAL(1, 21, 29), // "on_backBluetoothDebug_pressed"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 27), // "on_decrementButton_released"
QT_MOC_LITERAL(4, 80, 27), // "on_incrementButton_released"
QT_MOC_LITERAL(5, 108, 10), // "addRowData"
QT_MOC_LITERAL(6, 119, 4), // "data"
QT_MOC_LITERAL(7, 124, 23), // "BluetoothDebugColorType"
QT_MOC_LITERAL(8, 148, 9) // "colorType"

    },
    "BluetoothDebugScreen\0on_backBluetoothDebug_pressed\0"
    "\0on_decrementButton_released\0"
    "on_incrementButton_released\0addRowData\0"
    "data\0BluetoothDebugColorType\0colorType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothDebugScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    2,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,

       0        // eod
};

void BluetoothDebugScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BluetoothDebugScreen *_t = static_cast<BluetoothDebugScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_backBluetoothDebug_pressed(); break;
        case 1: _t->on_decrementButton_released(); break;
        case 2: _t->on_incrementButton_released(); break;
        case 3: _t->addRowData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< BluetoothDebugColorType(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluetoothDebugScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BluetoothDebugScreen.data,
      qt_meta_data_BluetoothDebugScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BluetoothDebugScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothDebugScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothDebugScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BluetoothDebugScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

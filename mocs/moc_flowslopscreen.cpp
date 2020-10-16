/****************************************************************************
** Meta object code from reading C++ file 'flowslopscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/flowslopscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flowslopscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FlowSlopScreen_t {
    QByteArrayData data[9];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlowSlopScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlowSlopScreen_t qt_meta_stringdata_FlowSlopScreen = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FlowSlopScreen"
QT_MOC_LITERAL(1, 15, 11), // "dialogClose"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(4, 51, 18), // "showFlowSlopScreen"
QT_MOC_LITERAL(5, 70, 28), // "on_flowSlopDecrease_released"
QT_MOC_LITERAL(6, 99, 28), // "on_flowSlopIncrease_released"
QT_MOC_LITERAL(7, 128, 26), // "on_flowSlopAccept_released"
QT_MOC_LITERAL(8, 155, 26) // "on_flowSlopCancel_released"

    },
    "FlowSlopScreen\0dialogClose\0\0"
    "writeParameterToEeprom\0showFlowSlopScreen\0"
    "on_flowSlopDecrease_released\0"
    "on_flowSlopIncrease_released\0"
    "on_flowSlopAccept_released\0"
    "on_flowSlopCancel_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlowSlopScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FlowSlopScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlowSlopScreen *_t = static_cast<FlowSlopScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->writeParameterToEeprom(); break;
        case 2: _t->showFlowSlopScreen(); break;
        case 3: _t->on_flowSlopDecrease_released(); break;
        case 4: _t->on_flowSlopIncrease_released(); break;
        case 5: _t->on_flowSlopAccept_released(); break;
        case 6: _t->on_flowSlopCancel_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FlowSlopScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowSlopScreen::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FlowSlopScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowSlopScreen::writeParameterToEeprom)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FlowSlopScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FlowSlopScreen.data,
      qt_meta_data_FlowSlopScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FlowSlopScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlowSlopScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FlowSlopScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FlowSlopScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FlowSlopScreen::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FlowSlopScreen::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

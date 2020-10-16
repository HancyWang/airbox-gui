/****************************************************************************
** Meta object code from reading C++ file 'manufacturingdiagnosisscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/manufacturingdiagnosisscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manufacturingdiagnosisscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManufacturingDiagnosisScreen_t {
    QByteArrayData data[14];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManufacturingDiagnosisScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManufacturingDiagnosisScreen_t qt_meta_stringdata_ManufacturingDiagnosisScreen = {
    {
QT_MOC_LITERAL(0, 0, 28), // "ManufacturingDiagnosisScreen"
QT_MOC_LITERAL(1, 29, 32), // "beforeManufacturingModeProcedure"
QT_MOC_LITERAL(2, 62, 0), // ""
QT_MOC_LITERAL(3, 63, 12), // "manuFactMode"
QT_MOC_LITERAL(4, 76, 11), // "blowerState"
QT_MOC_LITERAL(5, 88, 11), // "blowerSpeed"
QT_MOC_LITERAL(6, 100, 29), // "on_startBlowerButton_released"
QT_MOC_LITERAL(7, 130, 31), // "on_decrementBlowerSpeed_pressed"
QT_MOC_LITERAL(8, 162, 31), // "on_incrementBlowerSpeed_pressed"
QT_MOC_LITERAL(9, 194, 38), // "on_backManufacturingDiagnosis..."
QT_MOC_LITERAL(10, 233, 32), // "showManufacturingDiagnosisScreen"
QT_MOC_LITERAL(11, 266, 31), // "updateScreenAsPerReceivedPacket"
QT_MOC_LITERAL(12, 298, 5), // "uint*"
QT_MOC_LITERAL(13, 304, 8) // "localBuf"

    },
    "ManufacturingDiagnosisScreen\0"
    "beforeManufacturingModeProcedure\0\0"
    "manuFactMode\0blowerState\0blowerSpeed\0"
    "on_startBlowerButton_released\0"
    "on_decrementBlowerSpeed_pressed\0"
    "on_incrementBlowerSpeed_pressed\0"
    "on_backManufacturingDiagnosis_released\0"
    "showManufacturingDiagnosisScreen\0"
    "updateScreenAsPerReceivedPacket\0uint*\0"
    "localBuf"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManufacturingDiagnosisScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    1,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void ManufacturingDiagnosisScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManufacturingDiagnosisScreen *_t = static_cast<ManufacturingDiagnosisScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beforeManufacturingModeProcedure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->on_startBlowerButton_released(); break;
        case 2: _t->on_decrementBlowerSpeed_pressed(); break;
        case 3: _t->on_incrementBlowerSpeed_pressed(); break;
        case 4: _t->on_backManufacturingDiagnosis_released(); break;
        case 5: _t->showManufacturingDiagnosisScreen(); break;
        case 6: _t->updateScreenAsPerReceivedPacket((*reinterpret_cast< uint*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManufacturingDiagnosisScreen::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManufacturingDiagnosisScreen::beforeManufacturingModeProcedure)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManufacturingDiagnosisScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManufacturingDiagnosisScreen.data,
      qt_meta_data_ManufacturingDiagnosisScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManufacturingDiagnosisScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManufacturingDiagnosisScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManufacturingDiagnosisScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ManufacturingDiagnosisScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ManufacturingDiagnosisScreen::beforeManufacturingModeProcedure(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

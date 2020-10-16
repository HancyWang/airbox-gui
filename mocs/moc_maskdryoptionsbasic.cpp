/****************************************************************************
** Meta object code from reading C++ file 'maskdryoptionsbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/maskdryoptionsbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maskdryoptionsbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaskDryOptionsBasic_t {
    QByteArrayData data[7];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaskDryOptionsBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaskDryOptionsBasic_t qt_meta_stringdata_MaskDryOptionsBasic = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MaskDryOptionsBasic"
QT_MOC_LITERAL(1, 20, 27), // "beforeStartTherapyProcedure"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 19), // "maskDryTimerTimeout"
QT_MOC_LITERAL(4, 69, 25), // "on_maskDryCancel_released"
QT_MOC_LITERAL(5, 95, 32), // "on_maskDryTestStartStop_released"
QT_MOC_LITERAL(6, 128, 23) // "showMaskDryOptionScreen"

    },
    "MaskDryOptionsBasic\0beforeStartTherapyProcedure\0"
    "\0maskDryTimerTimeout\0on_maskDryCancel_released\0"
    "on_maskDryTestStartStop_released\0"
    "showMaskDryOptionScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaskDryOptionsBasic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaskDryOptionsBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaskDryOptionsBasic *_t = static_cast<MaskDryOptionsBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beforeStartTherapyProcedure(); break;
        case 1: _t->maskDryTimerTimeout(); break;
        case 2: _t->on_maskDryCancel_released(); break;
        case 3: _t->on_maskDryTestStartStop_released(); break;
        case 4: _t->showMaskDryOptionScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaskDryOptionsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaskDryOptionsBasic::beforeStartTherapyProcedure)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MaskDryOptionsBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MaskDryOptionsBasic.data,
      qt_meta_data_MaskDryOptionsBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MaskDryOptionsBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaskDryOptionsBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaskDryOptionsBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MaskDryOptionsBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MaskDryOptionsBasic::beforeStartTherapyProcedure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

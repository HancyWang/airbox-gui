/****************************************************************************
** Meta object code from reading C++ file 'maskoptionsbasic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/maskoptionsbasic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maskoptionsbasic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaskOptionsBasic_t {
    QByteArrayData data[9];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaskOptionsBasic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaskOptionsBasic_t qt_meta_stringdata_MaskOptionsBasic = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MaskOptionsBasic"
QT_MOC_LITERAL(1, 17, 21), // "showMaskFitTestScreen"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "showMaskDryOptionScreen"
QT_MOC_LITERAL(4, 64, 26), // "showMaskOptionsWindowBasic"
QT_MOC_LITERAL(5, 91, 27), // "on_homeMaskOptions_released"
QT_MOC_LITERAL(6, 119, 22), // "maskDryButton_released"
QT_MOC_LITERAL(7, 142, 26), // "maskFitTestButton_released"
QT_MOC_LITERAL(8, 169, 17) // "maskFitTestClosed"

    },
    "MaskOptionsBasic\0showMaskFitTestScreen\0"
    "\0showMaskDryOptionScreen\0"
    "showMaskOptionsWindowBasic\0"
    "on_homeMaskOptions_released\0"
    "maskDryButton_released\0"
    "maskFitTestButton_released\0maskFitTestClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaskOptionsBasic[] = {

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

void MaskOptionsBasic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaskOptionsBasic *_t = static_cast<MaskOptionsBasic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMaskFitTestScreen(); break;
        case 1: _t->showMaskDryOptionScreen(); break;
        case 2: _t->showMaskOptionsWindowBasic(); break;
        case 3: _t->on_homeMaskOptions_released(); break;
        case 4: _t->maskDryButton_released(); break;
        case 5: _t->maskFitTestButton_released(); break;
        case 6: _t->maskFitTestClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaskOptionsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaskOptionsBasic::showMaskFitTestScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MaskOptionsBasic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaskOptionsBasic::showMaskDryOptionScreen)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MaskOptionsBasic::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MaskOptionsBasic.data,
      qt_meta_data_MaskOptionsBasic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MaskOptionsBasic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaskOptionsBasic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaskOptionsBasic.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MaskOptionsBasic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MaskOptionsBasic::showMaskFitTestScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MaskOptionsBasic::showMaskDryOptionScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

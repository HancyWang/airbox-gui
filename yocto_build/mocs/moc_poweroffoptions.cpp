/****************************************************************************
** Meta object code from reading C++ file 'poweroffoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/poweroffoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'poweroffoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowerOffOptions_t {
    QByteArrayData data[14];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowerOffOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowerOffOptions_t qt_meta_stringdata_PowerOffOptions = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PowerOffOptions"
QT_MOC_LITERAL(1, 16, 11), // "dialogClose"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "sendBrightnessControlData"
QT_MOC_LITERAL(4, 55, 7), // "control"
QT_MOC_LITERAL(5, 63, 5), // "level"
QT_MOC_LITERAL(6, 69, 28), // "pruProcessorStartStopProcess"
QT_MOC_LITERAL(7, 98, 5), // "pruNo"
QT_MOC_LITERAL(8, 104, 15), // "programmFileStr"
QT_MOC_LITERAL(9, 120, 14), // "processorState"
QT_MOC_LITERAL(10, 135, 26), // "on_powerOffCancel_released"
QT_MOC_LITERAL(11, 162, 23), // "powerOffButton_released"
QT_MOC_LITERAL(12, 186, 20), // "powerOffTimerTimeout"
QT_MOC_LITERAL(13, 207, 22) // "startPowerOffProcedure"

    },
    "PowerOffOptions\0dialogClose\0\0"
    "sendBrightnessControlData\0control\0"
    "level\0pruProcessorStartStopProcess\0"
    "pruNo\0programmFileStr\0processorState\0"
    "on_powerOffCancel_released\0"
    "powerOffButton_released\0powerOffTimerTimeout\0"
    "startPowerOffProcedure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowerOffOptions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,
       6,    3,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    0,   64,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PowerOffOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowerOffOptions *_t = static_cast<PowerOffOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->sendBrightnessControlData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->pruProcessorStartStopProcess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->on_powerOffCancel_released(); break;
        case 4: _t->powerOffButton_released(); break;
        case 5: _t->powerOffTimerTimeout(); break;
        case 6: _t->startPowerOffProcedure(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowerOffOptions::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerOffOptions::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowerOffOptions::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerOffOptions::sendBrightnessControlData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowerOffOptions::*)(int , const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerOffOptions::pruProcessorStartStopProcess)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PowerOffOptions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PowerOffOptions.data,
      qt_meta_data_PowerOffOptions,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PowerOffOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowerOffOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowerOffOptions.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PowerOffOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PowerOffOptions::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PowerOffOptions::sendBrightnessControlData(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowerOffOptions::pruProcessorStartStopProcess(int _t1, const QString & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

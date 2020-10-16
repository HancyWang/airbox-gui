/****************************************************************************
** Meta object code from reading C++ file 'therapywindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/therapywindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'therapywindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TherapyWindowClinical_t {
    QByteArrayData data[19];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TherapyWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TherapyWindowClinical_t qt_meta_stringdata_TherapyWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TherapyWindowClinical"
QT_MOC_LITERAL(1, 22, 21), // "showSetPressureScreen"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 14), // "showModeScreen"
QT_MOC_LITERAL(4, 60, 28), // "showMaskOptionClinicalScreen"
QT_MOC_LITERAL(5, 89, 21), // "showMinPressureScreen"
QT_MOC_LITERAL(6, 111, 21), // "showMaxPressureScreen"
QT_MOC_LITERAL(7, 133, 25), // "showTherapyClinicalScreen"
QT_MOC_LITERAL(8, 159, 17), // "setPressureClosed"
QT_MOC_LITERAL(9, 177, 16), // "modeWindowClosed"
QT_MOC_LITERAL(10, 194, 17), // "minPressureClosed"
QT_MOC_LITERAL(11, 212, 17), // "maxPressureClosed"
QT_MOC_LITERAL(12, 230, 23), // "on_backTherapy_released"
QT_MOC_LITERAL(13, 254, 26), // "setPressureButton_released"
QT_MOC_LITERAL(14, 281, 19), // "modeButton_released"
QT_MOC_LITERAL(15, 301, 19), // "maskButton_released"
QT_MOC_LITERAL(16, 321, 16), // "maskButtonClosed"
QT_MOC_LITERAL(17, 338, 26), // "minPressureButton_released"
QT_MOC_LITERAL(18, 365, 26) // "maxPressureButton_released"

    },
    "TherapyWindowClinical\0showSetPressureScreen\0"
    "\0showModeScreen\0showMaskOptionClinicalScreen\0"
    "showMinPressureScreen\0showMaxPressureScreen\0"
    "showTherapyClinicalScreen\0setPressureClosed\0"
    "modeWindowClosed\0minPressureClosed\0"
    "maxPressureClosed\0on_backTherapy_released\0"
    "setPressureButton_released\0"
    "modeButton_released\0maskButton_released\0"
    "maskButtonClosed\0minPressureButton_released\0"
    "maxPressureButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TherapyWindowClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TherapyWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TherapyWindowClinical *_t = static_cast<TherapyWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showSetPressureScreen(); break;
        case 1: _t->showModeScreen(); break;
        case 2: _t->showMaskOptionClinicalScreen(); break;
        case 3: _t->showMinPressureScreen(); break;
        case 4: _t->showMaxPressureScreen(); break;
        case 5: _t->showTherapyClinicalScreen(); break;
        case 6: _t->setPressureClosed(); break;
        case 7: _t->modeWindowClosed(); break;
        case 8: _t->minPressureClosed(); break;
        case 9: _t->maxPressureClosed(); break;
        case 10: _t->on_backTherapy_released(); break;
        case 11: _t->setPressureButton_released(); break;
        case 12: _t->modeButton_released(); break;
        case 13: _t->maskButton_released(); break;
        case 14: _t->maskButtonClosed(); break;
        case 15: _t->minPressureButton_released(); break;
        case 16: _t->maxPressureButton_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TherapyWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TherapyWindowClinical::showSetPressureScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TherapyWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TherapyWindowClinical::showModeScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TherapyWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TherapyWindowClinical::showMaskOptionClinicalScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TherapyWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TherapyWindowClinical::showMinPressureScreen)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TherapyWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TherapyWindowClinical::showMaxPressureScreen)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TherapyWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TherapyWindowClinical.data,
      qt_meta_data_TherapyWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TherapyWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TherapyWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TherapyWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TherapyWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void TherapyWindowClinical::showSetPressureScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TherapyWindowClinical::showModeScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TherapyWindowClinical::showMaskOptionClinicalScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TherapyWindowClinical::showMinPressureScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TherapyWindowClinical::showMaxPressureScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

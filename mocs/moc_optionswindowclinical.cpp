/****************************************************************************
** Meta object code from reading C++ file 'optionswindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/optionswindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionswindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionsWindowClinical_t {
    QByteArrayData data[7];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsWindowClinical_t qt_meta_stringdata_OptionsWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 21), // "OptionsWindowClinical"
QT_MOC_LITERAL(1, 22, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 23), // "on_backOptions_released"
QT_MOC_LITERAL(4, 70, 38), // "sleepTitrationModeButtonSwitc..."
QT_MOC_LITERAL(5, 109, 36), // "autoStartTherapyButtonSwitch_..."
QT_MOC_LITERAL(6, 146, 25) // "showOptionsClinicalScreen"

    },
    "OptionsWindowClinical\0writeParameterToEeprom\0"
    "\0on_backOptions_released\0"
    "sleepTitrationModeButtonSwitch_clicked\0"
    "autoStartTherapyButtonSwitch_clicked\0"
    "showOptionsClinicalScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsWindowClinical[] = {

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
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsWindowClinical *_t = static_cast<OptionsWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeParameterToEeprom(); break;
        case 1: _t->on_backOptions_released(); break;
        case 2: _t->sleepTitrationModeButtonSwitch_clicked(); break;
        case 3: _t->autoStartTherapyButtonSwitch_clicked(); break;
        case 4: _t->showOptionsClinicalScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionsWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsWindowClinical::writeParameterToEeprom)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OptionsWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsWindowClinical.data,
      qt_meta_data_OptionsWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionsWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OptionsWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OptionsWindowClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

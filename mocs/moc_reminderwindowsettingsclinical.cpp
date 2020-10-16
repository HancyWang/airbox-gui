/****************************************************************************
** Meta object code from reading C++ file 'reminderwindowsettingsclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/reminderwindowsettingsclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reminderwindowsettingsclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReminderWindowSettingsClinical_t {
    QByteArrayData data[14];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReminderWindowSettingsClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReminderWindowSettingsClinical_t qt_meta_stringdata_ReminderWindowSettingsClinical = {
    {
QT_MOC_LITERAL(0, 0, 30), // "ReminderWindowSettingsClinical"
QT_MOC_LITERAL(1, 31, 22), // "showMaskReminderScreen"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 27), // "showAirFilterReminderScreen"
QT_MOC_LITERAL(4, 83, 25), // "showAirTubeReminderScreen"
QT_MOC_LITERAL(5, 109, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(6, 132, 25), // "on_backReminders_released"
QT_MOC_LITERAL(7, 158, 19), // "maskButton_released"
QT_MOC_LITERAL(8, 178, 22), // "airTubeButton_released"
QT_MOC_LITERAL(9, 201, 24), // "airFilterButton_released"
QT_MOC_LITERAL(10, 226, 24), // "maskButtonSwitch_clicked"
QT_MOC_LITERAL(11, 251, 27), // "airTubeButtonSwitch_clicked"
QT_MOC_LITERAL(12, 279, 29), // "airFilterButtonSwitch_clicked"
QT_MOC_LITERAL(13, 309, 26) // "showReminderClinicalScreen"

    },
    "ReminderWindowSettingsClinical\0"
    "showMaskReminderScreen\0\0"
    "showAirFilterReminderScreen\0"
    "showAirTubeReminderScreen\0"
    "writeParameterToEeprom\0on_backReminders_released\0"
    "maskButton_released\0airTubeButton_released\0"
    "airFilterButton_released\0"
    "maskButtonSwitch_clicked\0"
    "airTubeButtonSwitch_clicked\0"
    "airFilterButtonSwitch_clicked\0"
    "showReminderClinicalScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReminderWindowSettingsClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
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

       0        // eod
};

void ReminderWindowSettingsClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReminderWindowSettingsClinical *_t = static_cast<ReminderWindowSettingsClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMaskReminderScreen(); break;
        case 1: _t->showAirFilterReminderScreen(); break;
        case 2: _t->showAirTubeReminderScreen(); break;
        case 3: _t->writeParameterToEeprom(); break;
        case 4: _t->on_backReminders_released(); break;
        case 5: _t->maskButton_released(); break;
        case 6: _t->airTubeButton_released(); break;
        case 7: _t->airFilterButton_released(); break;
        case 8: _t->maskButtonSwitch_clicked(); break;
        case 9: _t->airTubeButtonSwitch_clicked(); break;
        case 10: _t->airFilterButtonSwitch_clicked(); break;
        case 11: _t->showReminderClinicalScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReminderWindowSettingsClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReminderWindowSettingsClinical::showMaskReminderScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReminderWindowSettingsClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReminderWindowSettingsClinical::showAirFilterReminderScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReminderWindowSettingsClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReminderWindowSettingsClinical::showAirTubeReminderScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ReminderWindowSettingsClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReminderWindowSettingsClinical::writeParameterToEeprom)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ReminderWindowSettingsClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReminderWindowSettingsClinical.data,
      qt_meta_data_ReminderWindowSettingsClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReminderWindowSettingsClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReminderWindowSettingsClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReminderWindowSettingsClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReminderWindowSettingsClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ReminderWindowSettingsClinical::showMaskReminderScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ReminderWindowSettingsClinical::showAirFilterReminderScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ReminderWindowSettingsClinical::showAirTubeReminderScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ReminderWindowSettingsClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

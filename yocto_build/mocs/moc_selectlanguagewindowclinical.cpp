/****************************************************************************
** Meta object code from reading C++ file 'selectlanguagewindowclinical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screens/selectlanguagewindowclinical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectlanguagewindowclinical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelectLanguageWindowClinical_t {
    QByteArrayData data[10];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectLanguageWindowClinical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectLanguageWindowClinical_t qt_meta_stringdata_SelectLanguageWindowClinical = {
    {
QT_MOC_LITERAL(0, 0, 28), // "SelectLanguageWindowClinical"
QT_MOC_LITERAL(1, 29, 11), // "dialogClose"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 22), // "writeParameterToEeprom"
QT_MOC_LITERAL(4, 65, 32), // "showSelectLanguageClinicalScreen"
QT_MOC_LITERAL(5, 98, 26), // "on_languageAccept_released"
QT_MOC_LITERAL(6, 125, 26), // "on_languageCancel_released"
QT_MOC_LITERAL(7, 152, 18), // "on_english_pressed"
QT_MOC_LITERAL(8, 171, 18), // "on_chinese_pressed"
QT_MOC_LITERAL(9, 190, 18) // "on_spanish_pressed"

    },
    "SelectLanguageWindowClinical\0dialogClose\0"
    "\0writeParameterToEeprom\0"
    "showSelectLanguageClinicalScreen\0"
    "on_languageAccept_released\0"
    "on_languageCancel_released\0"
    "on_english_pressed\0on_chinese_pressed\0"
    "on_spanish_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectLanguageWindowClinical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectLanguageWindowClinical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectLanguageWindowClinical *_t = static_cast<SelectLanguageWindowClinical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogClose(); break;
        case 1: _t->writeParameterToEeprom(); break;
        case 2: _t->showSelectLanguageClinicalScreen(); break;
        case 3: _t->on_languageAccept_released(); break;
        case 4: _t->on_languageCancel_released(); break;
        case 5: _t->on_english_pressed(); break;
        case 6: _t->on_chinese_pressed(); break;
        case 7: _t->on_spanish_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectLanguageWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectLanguageWindowClinical::dialogClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SelectLanguageWindowClinical::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectLanguageWindowClinical::writeParameterToEeprom)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SelectLanguageWindowClinical::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectLanguageWindowClinical.data,
      qt_meta_data_SelectLanguageWindowClinical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SelectLanguageWindowClinical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectLanguageWindowClinical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelectLanguageWindowClinical.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SelectLanguageWindowClinical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SelectLanguageWindowClinical::dialogClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SelectLanguageWindowClinical::writeParameterToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

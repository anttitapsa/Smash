/****************************************************************************
** Meta object code from reading C++ file 'characterselect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/Qt_project/smash/characterselect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'characterselect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacterSelect_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharacterSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharacterSelect_t qt_meta_stringdata_CharacterSelect = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CharacterSelect"
QT_MOC_LITERAL(1, 16, 8), // "TotoroP1"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "TotoroP2"
QT_MOC_LITERAL(4, 35, 7), // "TupsuP1"
QT_MOC_LITERAL(5, 43, 7), // "TupsuP2"
QT_MOC_LITERAL(6, 51, 15), // "OpenLevelSelect"
QT_MOC_LITERAL(7, 67, 12) // "ReturnToMain"

    },
    "CharacterSelect\0TotoroP1\0\0TotoroP2\0"
    "TupsuP1\0TupsuP2\0OpenLevelSelect\0"
    "ReturnToMain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterSelect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CharacterSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TotoroP1(); break;
        case 1: _t->TotoroP2(); break;
        case 2: _t->TupsuP1(); break;
        case 3: _t->TupsuP2(); break;
        case 4: _t->OpenLevelSelect(); break;
        case 5: _t->ReturnToMain(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CharacterSelect::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CharacterSelect.data,
    qt_meta_data_CharacterSelect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CharacterSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterSelect.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CharacterSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

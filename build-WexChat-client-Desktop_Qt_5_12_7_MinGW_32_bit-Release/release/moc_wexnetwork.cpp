/****************************************************************************
** Meta object code from reading C++ file 'wexnetwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WexChat-client/wexnetwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wexnetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WexNetwork_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WexNetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WexNetwork_t qt_meta_stringdata_WexNetwork = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WexNetwork"
QT_MOC_LITERAL(1, 11, 10), // "dataArrive"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "linkOut"
QT_MOC_LITERAL(4, 31, 12), // "packageError"
QT_MOC_LITERAL(5, 44, 11), // "boardArrive"
QT_MOC_LITERAL(6, 56, 9), // "boardType"
QT_MOC_LITERAL(7, 66, 4), // "type"
QT_MOC_LITERAL(8, 71, 4) // "data"

    },
    "WexNetwork\0dataArrive\0\0linkOut\0"
    "packageError\0boardArrive\0boardType\0"
    "type\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WexNetwork[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    2,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QByteArray,    7,    8,

       0        // eod
};

void WexNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WexNetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataArrive(); break;
        case 1: _t->linkOut(); break;
        case 2: _t->packageError(); break;
        case 3: _t->boardArrive((*reinterpret_cast< boardType(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WexNetwork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WexNetwork::dataArrive)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WexNetwork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WexNetwork::linkOut)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WexNetwork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WexNetwork::packageError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WexNetwork::*)(boardType , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WexNetwork::boardArrive)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WexNetwork::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WexNetwork.data,
    qt_meta_data_WexNetwork,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WexNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WexNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WexNetwork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WexNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WexNetwork::dataArrive()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WexNetwork::linkOut()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WexNetwork::packageError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WexNetwork::boardArrive(boardType _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

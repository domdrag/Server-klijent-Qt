/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    const uint offsetsAndSize[14];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 6), // "Server"
QT_MOC_LITERAL(7, 15), // "onNewConnection"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 11), // "onReadyRead"
QT_MOC_LITERAL(36, 11), // "QTcpSocket*"
QT_MOC_LITERAL(48, 14), // "onDisconnected"
QT_MOC_LITERAL(63, 18) // "onDisconnectPushed"

    },
    "Server\0onNewConnection\0\0onReadyRead\0"
    "QTcpSocket*\0onDisconnected\0"
    "onDisconnectPushed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    1,   39,    2, 0x0a,    2 /* Public */,
       5,    1,   42,    2, 0x0a,    4 /* Public */,
       6,    0,   45,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onReadyRead((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 2: _t->onDisconnected((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 3: _t->onDisconnectPushed(); break;
        default: ;
        }
    }
}

const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Server.offsetsAndSize,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Server_t
, QtPrivate::TypeAndForceComplete<Server, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

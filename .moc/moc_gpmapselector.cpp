/****************************************************************************
** Meta object code from reading C++ file 'gpmapselector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/gpmapselector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpmapselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GPMapSelector_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GPMapSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GPMapSelector_t qt_meta_stringdata_GPMapSelector = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GPMapSelector"
QT_MOC_LITERAL(1, 14, 11), // "mapSelected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "mapPath"
QT_MOC_LITERAL(4, 35, 31), // "on_listMap_itemSelectionChanged"
QT_MOC_LITERAL(5, 67, 22), // "enabledSelectionChange"
QT_MOC_LITERAL(6, 90, 5), // "state"
QT_MOC_LITERAL(7, 96, 9), // "selectMap"
QT_MOC_LITERAL(8, 106, 4) // "text"

    },
    "GPMapSelector\0mapSelected\0\0mapPath\0"
    "on_listMap_itemSelectionChanged\0"
    "enabledSelectionChange\0state\0selectMap\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GPMapSelector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void GPMapSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GPMapSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mapSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_listMap_itemSelectionChanged(); break;
        case 2: _t->enabledSelectionChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->selectMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GPMapSelector::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GPMapSelector::mapSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GPMapSelector::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GPMapSelector.data,
    qt_meta_data_GPMapSelector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GPMapSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GPMapSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GPMapSelector.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GPMapSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GPMapSelector::mapSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

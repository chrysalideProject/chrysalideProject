/****************************************************************************
** Meta object code from reading C++ file 'tableamanger.h'
**
** Created: Fri Feb 26 10:22:45 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableamanger.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableamanger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tableAManger[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      35,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_tableAManger[] = {
    "tableAManger\0\0capaciteChanged(int)\0"
    "typeChanged(typeTable*)\0"
};

const QMetaObject tableAManger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tableAManger,
      qt_meta_data_tableAManger, 0 }
};

const QMetaObject *tableAManger::metaObject() const
{
    return &staticMetaObject;
}

void *tableAManger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tableAManger))
        return static_cast<void*>(const_cast< tableAManger*>(this));
    return QObject::qt_metacast(_clname);
}

int tableAManger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: capaciteChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: typeChanged((*reinterpret_cast< typeTable*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void tableAManger::capaciteChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tableAManger::typeChanged(typeTable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'typetable.h'
**
** Created: Thu Feb 25 16:21:13 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../typetable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'typetable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_typeTable[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_typeTable[] = {
    "typeTable\0\0typesTablesChanged()\0"
};

const QMetaObject typeTable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_typeTable,
      qt_meta_data_typeTable, 0 }
};

const QMetaObject *typeTable::metaObject() const
{
    return &staticMetaObject;
}

void *typeTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_typeTable))
        return static_cast<void*>(const_cast< typeTable*>(this));
    return QObject::qt_metacast(_clname);
}

int typeTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: typesTablesChanged(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void typeTable::typesTablesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

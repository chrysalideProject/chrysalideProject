/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Feb 24 09:39:05 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     192,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     290,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     349,   11,   11,   11, 0x08,
     384,  378,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_action_Sauvegarde_triggered()\0"
    "on_action_Manuel_triggered()\0"
    "on_action_Propos_triggered()\0"
    "on_action_gestion_des_affinit_s_triggered()\0"
    "on_action_Pr_paration_des_tables_triggered()\0"
    "on_action_Nouveau_triggered()\0"
    "on_actionRentrer_les_Tables_triggered()\0"
    "on_actionD_part_triggered()\0"
    "on_actionArriv_e_triggered()\0"
    "on_action_Quitter_triggered()\0"
    "on_action_Ouvrir_triggered()\0event\0"
    "onCloseEvent(QCloseEvent*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_action_Sauvegarde_triggered(); break;
        case 1: on_action_Manuel_triggered(); break;
        case 2: on_action_Propos_triggered(); break;
        case 3: on_action_gestion_des_affinit_s_triggered(); break;
        case 4: on_action_Pr_paration_des_tables_triggered(); break;
        case 5: on_action_Nouveau_triggered(); break;
        case 6: on_actionRentrer_les_Tables_triggered(); break;
        case 7: on_actionD_part_triggered(); break;
        case 8: on_actionArriv_e_triggered(); break;
        case 9: on_action_Quitter_triggered(); break;
        case 10: on_action_Ouvrir_triggered(); break;
        case 11: onCloseEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

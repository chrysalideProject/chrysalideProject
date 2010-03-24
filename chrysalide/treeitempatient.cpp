#include "treeitempatient.h"
#include <QStringList>




 treeitemPatient::treeitemPatient(const QList<QVariant> &data, treeitemPatient *parent)
 {
     parentItem = parent;
     itemData = data;
 }

 treeitemPatient::~treeitemPatient()
 {
     qDeleteAll(childItems);
 }

 void treeitemPatient::appendChild(treeitemPatient *item)
 {
     childItems.append(item);
 }

 treeitemPatient *treeitemPatient::child(int row)
 {
     return childItems.value(row);
 }

 int treeitemPatient::childCount() const
 {
     return childItems.count();
 }

 int treeitemPatient::columnCount() const
 {
     return itemData.count();
 }

 QVariant treeitemPatient::data(int column) const
 {
     return itemData.value(column);
 }

 treeitemPatient *treeitemPatient::parent()
 {
     return parentItem;
 }

 int treeitemPatient::row() const
 {
     if (parentItem)
         return parentItem->childItems.indexOf(const_cast<treeitemPatient*>(this));

     return 0;
 }

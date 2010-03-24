#ifndef TREEITEMPATIENT_H
#define TREEITEMPATIENT_H
#include <QList>
#include <QVariant>

class treeitemPatient
{
public:
    treeitemPatient(const QList<QVariant> &data, treeitemPatient *parent = 0);
     ~treeitemPatient();

     void appendChild(treeitemPatient *child);

     treeitemPatient *child(int row);
     int childCount() const;
     int columnCount() const;
     QVariant data(int column) const;
     int row() const;
     treeitemPatient *parent();

 private:
     QList<treeitemPatient*> childItems;
     QList<QVariant> itemData;
     treeitemPatient *parentItem;
};

#endif // treeitemPatientPATIENT_H

#ifndef TREEITEMPATIENT_H
#define TREEITEMPATIENT_H
#include <QList>
#include <QVariant>
#include <QStandardItemModel>

class treeitemPatient: public QStandardItemModel
{
    Q_OBJECT
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

     Qt::ItemFlags flags() const
     {
        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
     }

};


#endif // treeitemPatientPATIENT_H

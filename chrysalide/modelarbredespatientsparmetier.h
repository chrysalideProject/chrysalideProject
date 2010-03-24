#ifndef MODELARBREDESPATIENTSPARMETIER_H
#define MODELARBREDESPATIENTSPARMETIER_H

#include <QAbstractItemModel>
#include <QModelIndex>
 #include <QVariant>
#include "treeitempatient.h"
class modelArbreDesPatientsParMetier : public QAbstractItemModel
{
 Q_OBJECT
public:
    modelArbreDesPatientsParMetier(const QString &data, QObject *parent);
    ~modelArbreDesPatientsParMetier();
    QVariant data(const QModelIndex &index, int role) const;
     Qt::ItemFlags flags(const QModelIndex &index) const;
     QVariant headerData(int section, Qt::Orientation orientation,
                         int role = Qt::DisplayRole) const;
     QModelIndex index(int row, int column,
                       const QModelIndex &parent = QModelIndex()) const;
     QModelIndex parent(const QModelIndex &index) const;
     int rowCount(const QModelIndex &parent = QModelIndex()) const;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;

 private:
     void setupModelData( treeitemPatient *parent);

     treeitemPatient *rootItem;
};

#endif // MODELARBREDESPATIENTSPARMETIER_H

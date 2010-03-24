#include "modelarbredespatientsparmetier.h"
#include "treeitempatient.h"
#include <QStringList>
#include <QDebug>
#include "patientmodel.h"


 modelArbreDesPatientsParMetier::modelArbreDesPatientsParMetier(const QString &data, QObject *parent)
     : QAbstractItemModel(parent)
 {
     QList<QVariant> rootData;
     rootData << "Métier" << "Patient";
     rootItem = new treeitemPatient(rootData);
     setupModelData( rootItem);
 }

 modelArbreDesPatientsParMetier::~modelArbreDesPatientsParMetier()
 {
     delete rootItem;
 }

 int modelArbreDesPatientsParMetier::columnCount(const QModelIndex &parent) const
 {
     if (parent.isValid())
         return static_cast<treeitemPatient*>(parent.internalPointer())->columnCount();
     else
         return rootItem->columnCount();
 }

 QVariant modelArbreDesPatientsParMetier::data(const QModelIndex &index, int role) const
 {

     if (!index.isValid())
         return QVariant();

     if (role != Qt::DisplayRole)
         return QVariant();

     treeitemPatient *item = static_cast<treeitemPatient*>(index.internalPointer());

     return item->data(index.column());
 }

 Qt::ItemFlags modelArbreDesPatientsParMetier::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
         return 0;

     return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
 }

 QVariant modelArbreDesPatientsParMetier::headerData(int section, Qt::Orientation orientation,
                                int role) const
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
         return rootItem->data(section);

     return QVariant();
 }

 QModelIndex modelArbreDesPatientsParMetier::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();

     treeitemPatient *parentItem;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<treeitemPatient*>(parent.internalPointer());

     treeitemPatient *childItem = parentItem->child(row);
     if (childItem)
         return createIndex(row, column, childItem);
     else
         return QModelIndex();
 }

 QModelIndex modelArbreDesPatientsParMetier::parent(const QModelIndex &index) const
 {
     if (!index.isValid())
         return QModelIndex();

     treeitemPatient *childItem = static_cast<treeitemPatient*>(index.internalPointer());
     treeitemPatient *parentItem = childItem->parent();

     if (parentItem == rootItem)
         return QModelIndex();

     return createIndex(parentItem->row(), 0, parentItem);
 }

 int modelArbreDesPatientsParMetier::rowCount(const QModelIndex &parent) const
 {
     treeitemPatient *parentItem;
     if (parent.column() > 0)
         return 0;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<treeitemPatient*>(parent.internalPointer());

     return parentItem->childCount();
 }

 void modelArbreDesPatientsParMetier::setupModelData( treeitemPatient *parent)
 {
     qDebug()<<"void modelArbreDesPatientsParMetier::setupModelData(const QStringList &lines, treeitemPatient *parent)";
    //afficher les métiers et leurs patients
    QMap<int,QString> mapMetiers=patientModel::recupererMetiers();
    for(QMap<int,QString>::iterator it=mapMetiers.begin();it!=mapMetiers.end();it++)
    {
        QList<QVariant> data;
        data<<QStringList(it.value());
        treeitemPatient * nouv=new treeitemPatient(data,parent);

        parent->appendChild(nouv);

        QMap<int,patientModel *> mapPatients=patientModel::recupererPatientsAvecSelection("idtravail="+QString::number(it.key()));
        for(QMap<int,patientModel *>::iterator itP=mapPatients.begin();itP!=mapPatients.end();itP++)
        {
            patientModel * lePatient=itP.value();
            QList<QVariant> data2;
            data2<<QStringList(lePatient->getPrenom()+" "+lePatient->getNom());
            treeitemPatient * nouvP=new treeitemPatient(data2,nouv);
            nouv->appendChild(nouvP);

        }
    }
 }

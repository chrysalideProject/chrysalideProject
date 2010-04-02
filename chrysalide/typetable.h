
#ifndef TYPETABLE_H
#define TYPETABLE_H

#include <QObject>
#include <QSqlQuery>
#include <QVariant>
#include <QVector>
#include "tableamanger.h"
class tableAManger;
class typeTable : public QObject
{
    Q_OBJECT

    private:
        int numero;
        QString libelle;
    public:
        //construction à partir de l'identifiant et du sgbd
        typeTable(int);
        typeTable(QString);
        void setTypeTable(int);
        void setLibelle(QString);
        void save();
        void supprimer();
        bool isUsedByATable();
//méthodes métier
        QVector  <tableAManger*>getTablesAManger(int noRepas); //obtient la liste des tables du  type/salle
        QPointF centre();//renvoie le centre des tables d'un certain type
//accesseur en lecture seule
        int getNumero(){ return numero; }
        QString getLibelle(){ return libelle; }
//méthodes et propriétés de portée classe
        static QVector<typeTable*> recupererTypesTables();
        static typeTable* recupererTypeTableInterieur();


    signals:
        void libelleChanged();
};

#endif // TYPETABLE_H

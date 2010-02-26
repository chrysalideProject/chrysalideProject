
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
//méthodes métier
        QVector  <tableAManger*>getTablesAManger(); //obtient la liste des tables du  type/salle
//accesseur en lecture seule
        int getNumero(){ return numero; }
        QString getLibelle(){ return libelle; }
//méthodes et propriétés de portée classe
        static QVector<typeTable*> recupererTypesTables();

        static typeTable* nouveauTypeTable();
        QPointF centre();

    signals:
        void typesTablesChanged();
};

#endif // TYPETABLE_H

#include "typetable.h"
#include <QDebug>

typeTable::typeTable(int pNumero)
{
    numero = pNumero;

    QSqlQuery typeTable("SELECT libelle FROM TYPETABLE WHERE numero = "+QString::number(numero));

    if (typeTable.first()){

        libelle = typeTable.value(0).toString();

    }
    else
    {
        libelle="No "+QString::number(numero)+" non trouvé dans la table";
    }

}
void typeTable::setLibelle(QString pLibelle){
    libelle = pLibelle;
    emit libelleChanged();
}

void typeTable::setTypeTable(int pNumero){

    numero = pNumero;

    QSqlQuery typeTable("SELECT * FROM TYPETABLE WHERE numero = "+QString::number(numero));

    if (typeTable.first()){
        libelle = typeTable.value(1).toString();
    }

}

QVector<typeTable*> typeTable::recupererTypesTables(){

    QVector<typeTable*> resultat;

    QSqlQuery typesTables("SELECT * FROM TYPETABLE");

    while (typesTables.next()){
        resultat.push_back(new typeTable(typesTables.value(0).toInt()));
    }

    return resultat;

}

typeTable* typeTable::nouveauTypeTable(){

    QSqlQuery("INSERT INTO TYPETABLE (libelle) VALUES ('Nouveau type')");

}

void typeTable::save(){

    QSqlQuery("UPDATE TYPETABLE SET libelle = '"+libelle+"' WHERE numero = "+QString::number(numero));

}

void typeTable::supprimer(){

    QSqlQuery("DELETE FROM TYPETABLE WHERE numero = "+QString::number(numero));

}

bool typeTable::isUsedByATable(){

    QSqlQuery isUsed("SELECT COUNT(*) FROM TABLEAMANGER WHERE typeTable = "+QString::number(numero));

    if (isUsed.first()){
        return (isUsed.value(0).toInt() > 0);
    }
}
typeTable::typeTable(QString pLibelle){


    QSqlQuery queryMax("SELECT MAX(numero)+1 FROM TYPETABLE");
    queryMax.first();
    int numeroTable=queryMax.value(0).toInt();
    QSqlQuery query("INSERT INTO TYPETABLE (numero,libelle) VALUES ("+QString::number(numeroTable)+",'"+pLibelle+"')");
    query.exec();    
    this->numero=numeroTable;
    this->libelle=pLibelle;
}


QVector <tableAManger*> typeTable::getTablesAManger()
{
    qDebug()<<"QVector& <tableAManger*> typeTable::getTablesAManger();";
    QVector<tableAManger*> resultat;

    QSqlQuery requeteLesTables("SELECT * FROM TABLEAMANGER WHERE TYPETABLE="+QString::number(numero));

    while (requeteLesTables.next()){
        resultat.push_back(new tableAManger(requeteLesTables.value(0).toInt()));
    }
    return resultat;
}
QPointF typeTable::centre()
{
    QPointF leCentre;
    QSqlQuery req("select avg(x),avg(y) from tableamanger where typetable="+QString::number(numero));
    if(req.first()) leCentre=QPointF(req.value(0).toDouble(),req.value(1).toDouble());
    else leCentre=QPointF(50,50);
    return leCentre;
}

#include "tableamanger.h"
#include <QDebug>

tableAManger::tableAManger(int pNumero, int pCapacite, int pNumeroTypeTable)
{
    numero = pNumero;
    capacite = pCapacite;

    type = new typeTable(pNumeroTypeTable);
}


void tableAManger::setCapacite(int pCapacite){

    capacite = pCapacite;
    QSqlQuery query("UPDATE TABLEAMANGER SET capacite = "+QString::number(capacite));
    query.exec();

    emit capaciteChanged(capacite);

}


void tableAManger::setType(typeTable* pTypeTable){

    type = pTypeTable;
    emit typeChanged(type);

}


QVector<tableAManger*> tableAManger::recupererTables(){

    QVector<tableAManger*> resultat;

    QSqlQuery tables("SELECT * FROM TABLEAMANGER");

    while (tables.next()){

        resultat.push_back(new tableAManger(tables.value(0).toInt(), tables.value(1).toInt(), tables.value(2).toInt()));

    }

    return resultat;

}
void tableAManger::capaciteChanged(int nouvelleCapacite)
{
    qDebug()<<"void tableAManger::capaciteChanged(int nouvelleCapacite)";
}
void tableAManger::typeChanged(typeTable* nouveauTypeTable)
{
    qDebug()<<"void tableAManger::typeChanged(typeTable* nouveauTypeTable)";
}


#include "typetable.h"

typeTable::typeTable(int pNumero)
{
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

#include "typetable.h"

typeTable::typeTable(int pNumero)
{
    numero = pNumero;

    QSqlQuery typeTable("SELECT * FROM TYPETABLE WHERE numero = "+QString::number(numero));

    if (typeTable.first()){

        libelle = typeTable.value(1).toString();

    }

}

typeTable* typeTable::nouveauTypeTable(){

    typeTable* resultat;

    QSqlQuery query("INSERT INTO TYPETABLE (libelle) VALUES ('Nouveau type')");
    query.exec();

    QSqlQuery typeCree("SELECT * FROM TYPETABLE WHERE numero = (SELECT MAX(numero) FROM TYPETABLE)");

    if (typeCree.first()){
        resultat = new typeTable(typeCree.value(0).toInt());
    }

    return resultat;

}

QVector<typeTable*> typeTable::recupererTypesTables(){

    QVector<typeTable*> resultat;

    QSqlQuery typesTables("SELECT * FROM TYPETABLE");

    while (typesTables.next()){
        resultat.push_back(new typeTable(typesTables.value(0).toInt()));
    }

    return resultat;

}

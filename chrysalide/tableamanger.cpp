#include "tableamanger.h"
#include <QDebug>

tableAManger::tableAManger(int pNumero)
{
    //construction d'une table à partir du sgbd
    qDebug()<<"tableAManger::tableAManger(int pNumero)";
    numero = pNumero;
    QSqlQuery selectTable("SELECT capacite,typetable,x,y FROM TABLEAMANGER WHERE numero = "+QString::number(numero));

    if (selectTable.first())
    {

        capacite = selectTable.value(0).toInt();
        type=new typeTable(selectTable.value(1).toInt());
        this->position=QPointF(selectTable.value(2).toDouble(),selectTable.value(3).toDouble());

    }

}
tableAManger::tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY)
{
    //constructeur sans numéro
    QSqlQuery selectNumero("SELECT max(numero)+1 FROM TABLEAMANGER");
    if(selectNumero.first())
    {
        int identifiant=selectNumero.value(0).toInt();
        numero=identifiant;
        capacite=pCapacite;
        position=QPointF(pX,pY);
        this->type=new typeTable(pNumeroTypeTable);
        QString texteRequete="insert into TABLEAMANGER (numero,capacite,x,y,typetable) values("+QString::number(identifiant)+
                              ","+QString::number(pCapacite)+","+QString::number(pX)+","+QString::number(pY)+","+QString::number(pNumeroTypeTable)+")";
        qDebug()<<texteRequete;
        QSqlQuery insertTable(texteRequete);
        insertTable.exec();
    }
}
tableAManger::tableAManger(int pNumero, int pCapacite, int pNumeroTypeTable)
{
    numero = pNumero;
    capacite = pCapacite;

    type = new typeTable(pNumeroTypeTable);
}


void tableAManger::setCapacite(int pCapacite){

    capacite = pCapacite;
    QSqlQuery query("UPDATE TABLEAMANGER SET capacite = "+QString::number(capacite) +" where numero="+ QString::number(numero));
    query.exec();

    emit capaciteChanged(capacite);

}
void tableAManger::setPos(QPointF pPos)
{
    //sauvegarde de la position de la tableAManger dans le sgbd
    qDebug()<<"void tableAManger::setPos(QPointF pPos)";
  position=pPos;
  QSqlQuery query("UPDATE TABLEAMANGER SET x= "+QString::number(pPos.x())+", y="+QString::number(pPos.y())+" where numero="+ QString::number(numero));
    query.exec();

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



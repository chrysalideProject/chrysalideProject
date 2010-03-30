#include "surveillantmodel.h"
#include <QDebug>
#include <QDate>

surveillantModel::surveillantModel(int pNumSurveillant) : personneModel(pNumSurveillant)
{
    type="surveillant";
}

QMap<int, surveillantModel*> surveillantModel::recupererSurveillants(){
    qDebug()<<"QMap<int, surveillantModel*> surveillantModel::recupererSurveillants()";

    QMap<int, surveillantModel*> resultat;

    QSqlQuery recupSurveillants("SELECT idPersonne FROM SURVEILLANT");

    while (recupSurveillants.next()){
        resultat[recupSurveillants.value(0).toInt()] = new surveillantModel(recupSurveillants.value(0).toInt());
    }

    return resultat;

}
QMap<int, surveillantModel*> surveillantModel::recupererSurveillants(int noRepas){

    QMap<int, surveillantModel*> resultat;

    QString texteRequete="SELECT SURVEILLANT.idPersonne FROM SURVEILLANT INNER JOIN PRENDRE on SURVEILLANT.idPersonne=prendre.idPersonne where PRENDRE.idRepas="+QString::number(noRepas);

    qDebug()<<texteRequete;

    QSqlQuery recupSurveillants(texteRequete);

    while (recupSurveillants.next()){
        resultat[recupSurveillants.value(0).toInt()] = new surveillantModel(recupSurveillants.value(0).toInt());
    }

    return resultat;

}
bool surveillantModel::travaille(QDate when,QString soirMidi)
{
    QString texteReq="select * from PRENDRE inner join REPAS on REPAS.id=PRENDRE.idRepas where idPersonne="+QString::number(this->id)+" and dateRepas='"+when.toString("yyyy-MM-dd")+"' and quand='"+soirMidi+"'";
    qDebug()<<texteReq;
    QSqlQuery req(texteReq);
    return req.first();
}
int surveillantModel::getNoTable(int noRepas)
{
    QSqlQuery recupTable("SELECT idTableAManger FROM  PRENDRE  where PRENDRE.idPersonne="+QString::number(id)+" PRENDRE.idRepas="+QString::number(noRepas));
    if(recupTable.first())
        return(recupTable.value(0).toInt());
    else return(-1);
}

#include "surveillantmodel.h"
#include <QDebug>
#include <QDate>

surveillantModel::surveillantModel(int pNumSurveillant) : personneModel(pNumSurveillant)
{
}

QMap<int, surveillantModel*> surveillantModel::recupererSurveillants(){

    QMap<int, surveillantModel*> resultat;

    QSqlQuery recupSurveillants("SELECT idPersonne FROM SURVEILLANT");

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

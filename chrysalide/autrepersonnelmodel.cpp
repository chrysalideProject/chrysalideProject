#include "autrepersonnelmodel.h"
#include <QDebug>
#include <QDate>

autrePersonnelModel::autrePersonnelModel(int pNumAutrePersonnel) : personneModel(pNumAutrePersonnel)
{
}

QMap<int, autrePersonnelModel*> autrePersonnelModel::recupererAutrePersonnels(){

    QMap<int, autrePersonnelModel*> resultat;

    QSqlQuery recupAutrePersonnels("SELECT idPersonne FROM AUTRE");

    while (recupAutrePersonnels.next()){
        resultat[recupAutrePersonnels.value(0).toInt()] = new autrePersonnelModel(recupAutrePersonnels.value(0).toInt());
    }

    return resultat;

}
bool autrePersonnelModel::travaille(QDate when,QString soirMidi)
{
    QString texteReq="select * from PRENDRE inner join REPAS on REPAS.id=PRENDRE.idRepas where idPersonne="+QString::number(this->id)+" and dateRepas='"+when.toString("yyyy-MM-dd")+"' and quand='"+soirMidi+"'";
    qDebug()<<texteReq;
    QSqlQuery req(texteReq);
    return req.first();
}
void autrePersonnelModel::prendreRepas(int noRepas)
{
    //repas du personnel et des serveurs
    QString texteReq1="select numero from tableamanger where typeTable=(select numero from typeTable where libelle='Personnel')";
    QSqlQuery req1(texteReq1);
    req1.first();
    QString numeroTable=req1.value(0).toString();
    QString texteReq="insert into PRENDRE (idPersonne,idRepas,idTableAManger)values("+QString::number(id)+","+QString::number(noRepas)+","+numeroTable+")";
    QSqlQuery req2;
    req2.exec(texteReq);
}

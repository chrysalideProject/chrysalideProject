#include "cuisiniermodel.h"
#include <QDebug>

cuisinierModel::cuisinierModel(int numero):personneModel(numero)
{
}
bool cuisinierModel::travaille(QDate when,QString soirMidi)
{
    QString texteReq="select * from PRENDRE inner join REPAS on REPAS.id=PRENDRE.idRepas where idPersonne="+QString::number(this->id)+" and dateRepas='"+when.toString("yyyy-MM-dd")+"' and quand='"+soirMidi+"'";
    qDebug()<<texteReq;
    QSqlQuery req(texteReq);
    return req.first();
}
QMap<int,cuisinierModel*> cuisinierModel::recupererCuisiniers()
{
    QMap<int,cuisinierModel*> resultat;
    QSqlQuery req("select * from cuisinier");
    while(req.next())
    {
        resultat[req.value(0).toInt()]=new cuisinierModel(req.value(0).toInt());
    }
    return resultat;
}

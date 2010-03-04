#include "repasmodel.h"
#include <QSqlQuery>
#include <QVariant>

repasModel::repasModel(QDate pDate,QString pQuand)
{
    QSqlQuery req("select id from Repas where dateRepas='"+pDate.toString("yyyy-MM-dd")+"' and quand='"+pQuand+"'");
    if(!req.first())
    {
        QSqlQuery req2("select max(id)+1 from repas");
        if(req2.first())
        {
            numero=req2.value(0).toInt();
        }
        else
            numero=1;
        QString texteReq3="insert into repas(id,dateRepas,quand) values("+QString::number(numero)+",'"+pDate.toString("yyyy-MM-dd")+"','"+pQuand+"')";
        QSqlQuery req3;
        req3.exec(texteReq3);
    }
    else
    {
        numero=req.value(0).toInt();
    }
}

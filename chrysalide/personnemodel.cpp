#include "personnemodel.h"
#include <QDebug>
personneModel::personneModel(int pNumPersonne){

    QSqlQuery recupInfos("SELECT * FROM PERSONNE WHERE id = "+QString::number(pNumPersonne));

    if (recupInfos.first()){

        id = recupInfos.value(0).toInt();
        nom = recupInfos.value(1).toString();
        prenom = recupInfos.value(2).toString();

    }

}

personneModel::personneModel(long pId, QString pNom, QString pPrenom)
{
    id = pId;
    nom = pNom;
    prenom = pPrenom;
}

int personneModel::insert(QString pNom, QString pPrenom)
{
    QSqlQuery max("select max(id)+1 from PERSONNE");
    max.first();
    QString numero=max.value(0).toString();
    QSqlQuery insert("insert into personne values("+numero+",'"+pNom+"','"+pPrenom+"')");
    insert.exec();
    return numero.toInt();
}

void personneModel::majProfil(){

    QSqlQuery maj("UPDATE PERSONNE SET nom = '"+nom+"', prenom = '"+prenom+"' WHERE id = "+QString::number(id));
    maj.exec();

}

void personneModel::supprimer(){

    QSqlQuery supprimer("DELETE FROM PERSONNE WHERE id = "+QString::number(id));
    supprimer.exec();

}
bool personneModel::estALExterieur(int noRepas)
{
    qDebug()<<"bool personneModel::estALExterieur(int noRepas)";
    QSqlQuery req("select * from prendre natural join tableamanger natural join  typetable where typetable.libelle='Extèrieur' and idPersonne="+QString::number(id)+" and idRepas="+QString::number(noRepas));
    return req.first();
}

void personneModel::mangerExterieur(int noRepas,bool exterieur)
{
    qDebug()<<"void personneModel::mangerExterieur(int noRepas,bool exterieur)";
    if(exterieur)
    {
        prendreRepas(noRepas,2);//2 correspond au typetable extérieur
    }
    else
    {
        prendreRepas(noRepas,0);
    }
}

void personneModel::prendreRepas(int noRepas,int pNoTable)//si noTable vaux 0 donc faux on efface l'inscription au repas
{   QString texteReq;
    //repas des patients et surveillants
    if(pNoTable==false)
    {
        texteReq="delete from prendre where idPersonne="+QString::number(id)+" and idRepas="+QString::number(noRepas);
    }
    else
    {
       texteReq="insert into PRENDRE (idPersonne,idRepas,idTableAManger)values("+QString::number(id)+","+QString::number(noRepas)+","+pNoTable+")";
   }
    QSqlQuery req2;
    req2.exec(texteReq);

}
void personneModel::prendreRepas(int noRepas)
{
    //repas du personnel et des serveurs
    QString texteReq1="select numero from tableamanger where typeTable=(select numero from typeTable where libelle='Cuisiniers')";
    QSqlQuery req1(texteReq1);
    req1.first();
    QString numeroTable=req1.value(0).toString();
    QString texteReq="insert into PRENDRE (idPersonne,idRepas,idTableAManger)values("+QString::number(id)+","+QString::number(noRepas)+","+numeroTable+")";
    QSqlQuery req2;
    req2.exec(texteReq);
}

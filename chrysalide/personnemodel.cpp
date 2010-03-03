#include "personnemodel.h"

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

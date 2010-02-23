#include "personnemodel.h"

personneModel::personneModel(long pId, QString pNom, QString pPrenom)
{
    id = pId;
    nom = pNom;
    prenom = pPrenom;
}

void personneModel::majProfil(){

    QSqlQuery maj("UPDATE PERSONNE SET nom = '"+nom+"', prenom = '"+prenom+"' WHERE id = "+QString::number(id));
    maj.exec();

}

void personneModel::supprimer(){

    QSqlQuery supprimer("DELETE FROM PERSONNE WHERE id = "+QString::number(id));
    supprimer.exec();

}

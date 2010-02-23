#include "patientmodel.h"

patientModel::patientModel(long pId, QString pNom, QString pPrenom, int pIdRegime, int pIdSurveillance, int pIdTravail) : personneModel(pId, pNom, pPrenom)
{
    idRegime = pIdRegime;
    idSurveillance = pIdSurveillance;
    idTravail = pIdTravail;
}

QVector<patientModel*> patientModel::recupererPatients(){

    QVector<patientModel*> resultat;

    QSqlQuery recupPatients("SELECT idPersonne, nom, prenom, idRegime, idSurveillance, idTravail FROM PATIENT inner join PERSONNE on PATIENT.idPersonne = PERSONNE.id");

    while (recupPatients.next()){
        resultat.push_back(new patientModel(recupPatients.value(0).toInt(), recupPatients.value(1).toString(), recupPatients.value(2).toString(), recupPatients.value(3).toInt(), recupPatients.value(4).toInt(), recupPatients.value(5).toInt()));
    }

    return resultat;

}

void patientModel::majProfil(){

    personneModel::majProfil();

    QSqlQuery maj("UPDATE PATIENT SET idRegime = "+QString::number(idRegime)+", idSurveillance = "+QString::number(idSurveillance)+", idTravail = "+QString::number(idTravail)+" WHERE idPersonne = "+QString::number(id));
    maj.exec();

}

void patientModel::supprimer(){

    QSqlQuery supprimer("DELETE FROM PATIENT WHERE idPersonne = "+QString::number(id));
    supprimer.exec();

    personneModel::supprimer();

}

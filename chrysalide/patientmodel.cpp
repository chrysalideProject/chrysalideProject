#include "patientmodel.h"
#include <QDebug>
patientModel::patientModel(int pNumPatient) : personneModel(pNumPatient)
{
    QSqlQuery recupInfos("SELECT * FROM PATIENT WHERE idPersonne = "+QString::number(pNumPatient));
 
    if (recupInfos.first()){
        idRegime = recupInfos.value(2).toInt();
        idSurveillance = recupInfos.value(3).toInt();
        idTravail = recupInfos.value(1).toInt();
        recupererAffinites();
        recupererIncompatibles();
    }
 
}
QMap<int,QString> patientModel::recupererMetiers()
{
    QMap<int,QString> resultat;
    QSqlQuery recupMetiers("SELECT distinct idTravail,libelle FROM PATIENT inner join TRAVAIL on travail.id=patient.idtravail");
     while (recupMetiers.next()){
        resultat[recupMetiers.value(0).toInt()] = recupMetiers.value(1).toString();
    }
 
    return resultat;
 
}
QMap<int, patientModel*> patientModel::recupererPatients(){
 
    QMap<int, patientModel*> resultat;
 
    QSqlQuery recupPatients("SELECT idPersonne FROM PATIENT");
 
    while (recupPatients.next()){
        resultat[recupPatients.value(0).toInt()] = new patientModel(recupPatients.value(0).toInt());
    }
 
    return resultat;
 
}
QMap<int, patientModel*> patientModel::recupererPatientsAvecSelection(QString where){
 
    QMap<int, patientModel*> resultat;
 
    QSqlQuery recupPatients("SELECT idPersonne FROM PATIENT WHERE "+where);
 
    while (recupPatients.next()){
        resultat[recupPatients.value(0).toInt()] = new patientModel(recupPatients.value(0).toInt());
    }
 
    return resultat;
 
}
patientModel::patientModel(long pId, QString pNom, QString pPrenom, int pIdRegime, int pIdSurveillance, int pIdTravail) : personneModel(pId, pNom, pPrenom)
{
    idRegime = pIdRegime;
    idSurveillance = pIdSurveillance;
    idTravail = pIdTravail;
 
    recupererAffinites();
    recupererIncompatibles();
}
 
QMap<int,patientModel*> patientModel::recupererPatientsNonPlaces(int noRepas)
{
    QMap<int,patientModel*> resultat;

    QSqlQuery recupPatients("SELECT idPersonne, nom, prenom, idRegime, idSurveillance, idTravail FROM PATIENT inner join PERSONNE on PATIENT.idPersonne = PERSONNE.id where not exists(select * from PRENDRE where prendre.idPersonne=PERSONNE.id and prendre.idRepas="+QString::number(noRepas)+")");

    while (recupPatients.next())
    {
        resultat[recupPatients.value(0).toInt()]=new patientModel(recupPatients.value(0).toInt(), recupPatients.value(1).toString(), recupPatients.value(2).toString(), recupPatients.value(3).toInt(), recupPatients.value(4).toInt(), recupPatients.value(5).toInt());
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
 
void patientModel::recupererAffinites(){
 
    QSqlQuery recupAffinites("SELECT idPersonne2, nom, prenom, idRegime, idSurveillance, idTravail FROM PATIENT inner join AFFINITE on AFFINITE.idPersonne2 = PATIENT.idPersonne WHERE idPersonne1 = "+QString::number(id));
 
    while(recupAffinites.next()){
        affinites.push_back(new patientModel(recupAffinites.value(0).toInt(), recupAffinites.value(1).toString(), recupAffinites.value(2).toString(), recupAffinites.value(3).toInt(), recupAffinites.value(4).toInt(), recupAffinites.value(5).toInt()));
    }
 
}
 
void patientModel::recupererIncompatibles(){
 
    QSqlQuery recupIncompatibles("SELECT idPersonne2, nom, prenom, idRegime, idSurveillance, idTravail FROM PATIENT inner join INCOMPATIBILITE on INCOMPATIBILITE.idPersonne2 = PATIENT.idPersonne WHERE idPersonne1 = "+QString::number(id));
 
    while(recupIncompatibles.next()){
        incompatibles.push_back(new patientModel(recupIncompatibles.value(0).toInt(), recupIncompatibles.value(1).toString(), recupIncompatibles.value(2).toString(), recupIncompatibles.value(3).toInt(), recupIncompatibles.value(4).toInt(), recupIncompatibles.value(5).toInt()));
    }
 
}

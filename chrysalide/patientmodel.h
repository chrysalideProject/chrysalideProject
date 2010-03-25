#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H
 
#include <QVector>
#include "personnemodel.h"
 
class patientModel :public personneModel
{
private:
    int idRegime;
    int idSurveillance;
    int idTravail;
    bool isServeur;
    QVector<patientModel*> affinites;
    QVector<patientModel*> incompatibles;
 
public:
 
    patientModel(long, QString, QString, int, int, int);
    patientModel(int);
 
    //static QVector<patientModel*> recupererPatients();
    static QMap<int, patientModel*> recupererPatients();
    static QMap<int, patientModel*>recupererPatientsAvecSelection(QString where);
    void majProfil();
    void supprimer();
    int getIdRegime(){ return idRegime; }
    int getIdSurveillance(){ return idSurveillance; }
    int getIdTravail(){ return idTravail; }
    bool getIsServeur(){ return isServeur; }
 
    void setIsServeur(bool);
    void recupererAffinites();
    void recupererIncompatibles();
    static QMap<int,QString>recupererMetiers();
};
 
#endif // PATIENTMODEL_H

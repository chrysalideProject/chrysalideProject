#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QVector>
#include "personnemodel.h"

class patientModel : personneModel
{
    private:
        int idRegime;
        int idSurveillance;
        int idTravail;

        QVector<patientModel*> affinites;
        QVector<patientModel*> incompatibles;

    public:
        patientModel(long, QString, QString, int, int, int);
        static QVector<patientModel*> recupererPatients();
};

#endif // PATIENTMODEL_H

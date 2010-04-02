#ifndef SURVEILLANTMODEL_H
#define SURVEILLANTMODEL_H
#include "personnemodel.h"

class surveillantModel : public personneModel
{
    public:
        surveillantModel(int);
        static QMap<int, surveillantModel*> recupererSurveillants();
        static QMap<int, surveillantModel*> recupererSurveillants(int noRepas);
        static QMap<int, surveillantModel*> recupererSurveillantsInterieur(int noRepas);
        bool travaille(QDate when,QString soirMidi);
        int getNoTable(int noRepas);
};

#endif // SURVEILLANTMODEL_H

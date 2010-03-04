#ifndef SURVEILLANTMODEL_H
#define SURVEILLANTMODEL_H
#include "personnemodel.h"

class surveillantModel : public personneModel
{
    public:
        surveillantModel(int);
        static QMap<int, surveillantModel*> recupererSurveillants();
        bool travaille(QDate when,QString soirMidi);
};

#endif // SURVEILLANTMODEL_H

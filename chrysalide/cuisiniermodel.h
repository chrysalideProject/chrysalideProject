#ifndef CUISINIERMODEL_H
#define CUISINIERMODEL_H
#include "personnemodel.h"
#include "cuisinierview.h"
#include <QDate>

class cuisinierModel : public personneModel
{
public:
    cuisinierModel(int);
    static QMap<int,cuisinierModel*> recupererCuisiniers();
    //creation des vues à partir des modeles
    bool travaille(QDate when,QString soirMidi);
};

#endif // CUISINIERMODEL_H

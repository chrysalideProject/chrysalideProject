#ifndef CUISINIERVIEW_H
#define CUISINIERVIEW_H

#include <QListWidgetItem>
#include "cuisiniermodel.h"
class cuisinierModel;
class cuisinierView : public QListWidgetItem
{

public:
    cuisinierView();
    cuisinierModel* modele;
    QString text();
    void setModele(cuisinierModel* pCM){modele=pCM;};


};

#endif // CUISINIERVIEW_H

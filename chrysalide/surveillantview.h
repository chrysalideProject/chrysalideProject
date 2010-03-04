#ifndef SURVEILLANTVIEW_H
#define SURVEILLANTVIEW_H

#include <QListWidgetItem>
#include "surveillantmodel.h"
class surveillantModel;
class surveillantView : public QListWidgetItem
{

public:
    surveillantView();
    surveillantModel* modele;
    QString text();
    void setModele(surveillantModel* pCM){modele=pCM;};


};

#endif // SURVEILLANTVIEW_H

#ifndef AUTREPERSONNELVIEW_H
#define AUTREPERSONNELVIEW_H

#include <QListWidgetItem>
#include "autrepersonnelmodel.h"
class autrePersonnelModel;
class autrePersonnelView : public QListWidgetItem
{

public:
    autrePersonnelView();
    autrePersonnelModel* modele;
    QString text();
    void setModele(autrePersonnelModel* pCM){modele=pCM;};


};

#endif // AUTREPERSONNELVIEW_H

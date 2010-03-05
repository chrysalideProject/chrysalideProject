#include "autrepersonnelview.h"
#include <QDebug>
QString autrePersonnelView::text()
{
    if(modele!=NULL)
        return modele->getPrenom()+" "+modele->getNom();
    else
        return "";
}
autrePersonnelView::autrePersonnelView():QListWidgetItem()
{
    qDebug()<<"autrePersonnelView::autrePersonnelView():QListWidgetItem()";
}


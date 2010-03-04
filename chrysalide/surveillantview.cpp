#include "surveillantview.h"
#include <QDebug>
QString surveillantView::text()
{
    if(modele!=NULL)
        return modele->getPrenom()+" "+modele->getNom();
    else
        return "";
}
surveillantView::surveillantView():QListWidgetItem()
{
    qDebug()<<"surveillantView::surveillantView():QListWidgetItem()";
}


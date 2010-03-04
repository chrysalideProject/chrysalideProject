#include "cuisinierview.h"
#include <QDebug>
QString cuisinierView::text()
{
    if(modele!=NULL)
        return modele->getPrenom()+" "+modele->getNom();
    else
        return "";
}
cuisinierView::cuisinierView():QListWidgetItem()
{
    qDebug()<<"cuisinierView::cuisinierView():QListWidgetItem()";
}


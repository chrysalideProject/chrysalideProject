#include "tableamangerview.h"
#include <QDebug>
const int HAUTEUR =60;
const int LARGEUR =30;

tableAMangerView::tableAMangerView(QGraphicsScene* pScene):QGraphicsRectItem(0,pScene)
{

}
void tableAMangerView::setModel(tableAManger* pModele)
{
    qDebug()<<"void tableAMangerView::setModel(tableAManger* pModele)";
    model=pModele;
    //obtention de l'abscisse et de l'odonnée ainsi que du nombre de place
    int nomBreDePlace=model->getCapacite();
    QPointF pos=model->getPosition();
    setRect(pos.x(),pos.y(),LARGEUR*nomBreDePlace/2,HAUTEUR);
    qDebug()<<"hauteur"<<rect().height()<<"largeur"<<rect().width();
    setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
}
QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)

{
    qDebug()<<"QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)";
    if (change == QGraphicsItem::ItemPositionHasChanged)
    {
         model->setPos(pos());
         qDebug()<<"x:"<<pos().x()<<" y: "<<pos().y();
     }
     return value;
}

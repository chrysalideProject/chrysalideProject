#include "tableamangerview.h"
#include <QDebug>
const int HAUTEUR =60;
const int LARGEUR =30;

tableAMangerView::tableAMangerView(QGraphicsScene* pScene):QGraphicsRectItem(0,pScene)
{
  doitEtreEnregistree=false;
}
void tableAMangerView::setModel(tableAManger* pModele)
{
    qDebug()<<"void tableAMangerView::setModel(tableAManger* pModele)";
    model=pModele;
    //obtention de l'abscisse et de l'odonnée ainsi que du nombre de place
    int nomBreDePlace=model->getCapacite();
    QPointF pos=model->getPosition();
    setRect(0,0,LARGEUR*nomBreDePlace/2,HAUTEUR);
    setPos(pos);
    qDebug()<<"hauteur"<<rect().height()<<"largeur"<<rect().width();
    setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
}
void tableAMangerView::enregistrePosition()
{
    qDebug()<<"void tableAMangerView::enregistrePosition()";
    model->setPos(pos());
}
void tableAMangerView::supprimeModel()
{
    model->supprime();
}
tableAMangerView::~tableAMangerView()
{
    qDebug()<<"tableAMangerView::~tableAMangerView()";
    if(doitEtreEnregistree)
    {
        model->setPos(pos());
    }
    delete(model);
}
QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)
{
    qDebug()<<"QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)";
    if (change == QGraphicsItem::ItemPositionHasChanged)
    {
         //model->setPos(pos());
         doitEtreEnregistree=true;
     }
     return value;
}

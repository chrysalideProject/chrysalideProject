#include "typetableview.h"
#include "tableamangerview.h"
#include <QDebug>
#include <QInputDialog>

typeTableView::typeTableView(QWidget* parent): QGraphicsView(parent)
{
//rien à faire du tout...
}
void typeTableView::setTypeTable(int numeroTypeDeTable,bool affPersonnes)
{
    //mise en relation de la vue avec son modele
    sonType=new typeTable(numeroTypeDeTable);
    affiche(affPersonnes);
}
void typeTableView::clear()
{
    //effacement graphique des tablesAManger    
    qDebug()<<"void typeTableView::clear()";
/*
    foreach(tableAMangerView* uneTable,vecteurDesTablesDuType)
    {
        qDebug()<<"FOREACH - avant le Delete - foreach(QGraphicsItem* uneTable,all)";

        delete(uneTable);
        qDebug()<<"FOREACH - apres le Delete - foreach(QGraphicsItem* uneTable,all)";
    }
    qDebug()<<"FIN - void typeTableView::clear()";*/
}


void typeTableView::affiche(bool affichePatient)
{
    qDebug()<<"void typeTableView::affiche()";
  //recup de ttes les tables et instanciations correspondantes
    QVector<tableAManger*> mesTables=sonType->getTablesAManger();
    qDebug()<<"TEST 1 ";
    //j'efface tout
    clear();
    //et on y va
    qDebug()<<"TEST 2 ";
    foreach(tableAManger* uneTable,mesTables)
    {

        //creation d'autant de tableAMangerView que de tableAManger
        tableAMangerView * nouvelleTable=new tableAMangerView(this->scene(),affichePatient);

        //on fait le rapprochement entre la vue et son modèle
        nouvelleTable->setModel(uneTable,repasCourant);
        //ajout au vecteur
        vecteurDesTablesDuType.push_back(nouvelleTable);
    }
    centrer();
}
void typeTableView::dragEnterEvent(QDragEnterEvent *event)
 {
    qDebug("void typeTableView::::dragEnterEvent(QDragEnterEvent *event)");
    if(event->source()->objectName()=="listWidgetTable")
    {
        event->accept();
    }
 }
void typeTableView::dragMoveEvent(QDragMoveEvent *event)
 {
    qDebug()<<":typeTableView:::dragMoveEvent(QDragMoveEvent *event)";
    if(event->source()->objectName()=="listWidgetTable")
    {
        event->accept();
    }
 }

void typeTableView::dropEvent(QDropEvent *event)
{
    qDebug()<<"void typeTableView::dropEvent(QDropEvent *event)";
    QPointF lePointMapp=this->mapToScene(event->pos());
   QPoint  lePointMappe=lePointMapp.toPoint();
    if(event->source()->objectName()=="listWidgetTable")
    {

        bool ok;
        int nombreDePlace=QInputDialog::getInt(this,"Saisie du nombre de place","Nombre de places:",6,2,30,2,&ok);
        if (ok)
        {

            tableAMangerView * nouvelleTable= new tableAMangerView(this->scene(),false);

            nouvelleTable->setModel(new tableAManger(nombreDePlace,sonType->getNumero(),lePointMappe.x(),lePointMappe.y()),0);
        }
    }
}
void typeTableView::enregistrePositions()
{
    qDebug()<<"void typeTableView::enregistrePositions()";
    QList<QGraphicsItem*> all =this->items(this->rect(),Qt::ContainsItemShape);
    foreach(QGraphicsItem* uneTable,all)
    {

        ((tableAMangerView*)uneTable)->enregistrePosition();
    }
}
void typeTableView::supprimeTablesSelectionnees()
{
      //effacement des tablesAManger
    qDebug()<<"void typeTableView::clear()";
    QList<QGraphicsItem*> listeDesTablesSelectionnees =this->scene()->selectedItems();
    foreach(QGraphicsItem* uneTable,listeDesTablesSelectionnees)
    {
        ((tableAMangerView *)uneTable)->supprimeModel();
        delete(uneTable);
    }
}
void typeTableView::centrer()
{
    centerOn(centre());
}
QPointF typeTableView::centre()
{
    QPointF leCentre(0,0);

    return leCentre;
}

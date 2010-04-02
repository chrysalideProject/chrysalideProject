#include "typetableview.h"
#include "tableamangerview.h"
#include <QDebug>
#include <QInputDialog>

typeTableView::typeTableView(QWidget* parent): QGraphicsView(parent)
{
    sonType=NULL;
}
void typeTableView::setTypeTable(int numeroTypeDeTable,bool affPersonnes)
{
    qDebug()<<"void typeTableView::setTypeTable(int numeroTypeDeTable,bool affPersonnes)";
    //mise en relation de la vue avec son modele
    sonType=new typeTable(numeroTypeDeTable);
    affiche(affPersonnes);
}
void typeTableView::clear()
{
    //effacement  des tablesAManger
    qDebug()<<"void typeTableView::clear()";
    foreach(tableAMangerView* uneTable,vecteurDesTablesDuType)
    {
        delete(uneTable);
    }
    vecteurDesTablesDuType.clear();//on vide le vecteur

}


void typeTableView::affiche(bool affichePatient)
{
    qDebug()<<"void typeTableView::affiche(bool affichePatient)";
    //recup de ttes les tables du type et instanciations correspondantes
    if(sonType!=NULL)
    {
        QVector<tableAManger*> mesTables=sonType->getTablesAManger(repasCourant);

        //j'efface tout ce qu'il y a déjà
        clear();
        //et on y va

        foreach(tableAManger* uneTable,mesTables)
        {

            //creation d'autant de tableAMangerView que de tableAManger
            tableAMangerView * nouvelleTable=new tableAMangerView(this->scene(),affichePatient);

            //on fait le rapprochement entre la vue et son modèle
            nouvelleTable->setModel(uneTable);
            //ajout au vecteur
            vecteurDesTablesDuType.push_back(nouvelleTable);
        }
        centrer();
    }
    else
        qDebug()<<"Le type de table intérieur... n'est pas défini";
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

            nouvelleTable->setModel(new tableAManger(nombreDePlace,sonType->getNumero(),lePointMappe.x(),lePointMappe.y(),-1));
            //ajout au vecteur
            vecteurDesTablesDuType.push_back(nouvelleTable);

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
    //supression des tables de la vue puis de la base de donnée
    //effacement des tablesAManger
    qDebug()<<"void typeTableView::supprimeTablesSelectionnees()";
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

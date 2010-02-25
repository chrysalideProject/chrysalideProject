#include "typetableview.h"
#include "tableamangerview.h"
#include <QDebug>
#include <QInputDialog>

typeTableView::typeTableView(QWidget* parent): QGraphicsView(parent)
{

}
void typeTableView::setTypeTable(int numeroTypeDeTable)
{
    sonType=new typeTable(numeroTypeDeTable);
    affiche();
}
void typeTableView::clear()
{
    //effacement des tablesAManger
    qDebug()<<"void typeTableView::clear()";
    QList<QGraphicsItem*> all =this->items(this->rect(),Qt::ContainsItemShape);
    foreach(QGraphicsItem* uneTable,all)
    {
        delete(uneTable);
    }
}
void typeTableView::affiche()
{
  //recup de ttes les tables et instanciations correspondantes
    QVector<tableAManger*> mesTables=sonType->getTablesAManger();
    //j'efface tout
    clear();
    //et on y va
    foreach(tableAManger* uneTable,mesTables)
    {
        //creation d'autant de tableAMangerView que de tableAManger
        tableAMangerView * nouvelleTable=new tableAMangerView(this->scene());
        //on fait le rapprochement entre la vue et son modèle
        nouvelleTable->setModel(uneTable);

    }

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
{  QPointF lePointMapp=this->mapToScene(event->pos());
   QPoint  lePointMappe=lePointMapp.toPoint();
    if(event->source()->objectName()=="listWidgetTable")
    {
        /*QStandardItemModel model(this->parent());
                    model.dropMimeData(event->mimeData(), Qt::CopyAction, 0,0, QModelIndex());
                    condition=delimiteur+model.item(0,0)->text()+delimiteur;QStandardItemModel model(this->parent());*/
        //création d'une table
        bool ok;
        int nombreDePlace=QInputDialog::getInt(this,"Saisie du nombre de place","Nombre de places:",6,2,30,2,&ok);
        if (ok)
        {
            tableAMangerView * nouvelleTable= new tableAMangerView(this->scene());
            nouvelleTable->setModel(new tableAManger(nombreDePlace,sonType->getNumero(),lePointMappe.x(),lePointMappe.y()));
        }

    }
}

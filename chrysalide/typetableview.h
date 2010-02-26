#ifndef TYPETABLEVIEW_H
#define TYPETABLEVIEW_H

#include <QGraphicsView>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include "typetable.h"

class typeTableView : public QGraphicsView
{
public:
    typeTableView(QWidget*);
    typeTable* sonType;
    //mise en rapport avec le modele
    void setTypeTable(int numeroTypeDeTable);
    //affichage
    void affiche();
    //efface les tables de la vue
    void clear();
    //drag and drop
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void enregistrePositions();
    void supprimeTablesSelectionnees();
    QPointF centre();
    void centrer();
};

#endif // TYPETABLEVIEW_H

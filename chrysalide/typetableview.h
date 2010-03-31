#ifndef TYPETABLEVIEW_H
#define TYPETABLEVIEW_H

#include <QGraphicsView>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include "typetable.h"
#include "tableamangerview.h"

class typeTableView : public QGraphicsView
{
public:
    typeTableView(QWidget*);
    QVector<tableAMangerView*> vecteurDesTablesDuType;
    int repasCourant;
    void setRepasCourant(int noRepas){repasCourant=noRepas;};
    typeTable* sonType;

    //mise en rapport avec le modele
    void setTypeTable(int numeroTypeDeTable,bool);
    //affichage
    void affiche(bool patient=false);
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

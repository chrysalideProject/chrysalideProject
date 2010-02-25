#ifndef TABLEAMANGERVIEW_H
#define TABLEAMANGERVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "tableamanger.h"

class tableAMangerView : public QGraphicsRectItem
{
    private:
    //son modèle
        tableAManger * model;
public:
    //le constructeur
    tableAMangerView(QGraphicsScene*);
    //réalise le lien entre la vue et le modèle
    void setModel(tableAManger*);
    //gère le changement de position
    QVariant itemChange(GraphicsItemChange change,const QVariant &value);

};

#endif // TABLEAMANGERVIEW_H

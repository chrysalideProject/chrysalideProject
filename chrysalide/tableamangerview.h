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
        bool doitEtreEnregistree;
public:
    //le constructeur
    tableAMangerView(QGraphicsScene*);
    //destructeur
    ~tableAMangerView();

    //réalise le lien entre la vue et le modèle
    void setModel(tableAManger*);
    //enregistre le changement de position
    void enregistrePosition();
    //modif de position par exemple
    QVariant itemChange(GraphicsItemChange change,const QVariant &value);
    //supprime la tableAManger de la base de données
    void supprimeModel();
};

#endif // TABLEAMANGERVIEW_H

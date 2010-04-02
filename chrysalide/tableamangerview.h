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
        bool affichePatients;
        QVector<QGraphicsTextItem*> vecteurPersonne;
public:
    //le constructeur
    tableAMangerView(QGraphicsScene*,bool);
    //destructeur
    ~tableAMangerView();

    //réalise le lien entre la vue et le modèle
    void setModel(tableAManger*);
    //enregistre le changement de position
    void enregistrePosition();

    //supprime la tableAManger de la base de données
    void supprimeModel();
};

#endif // TABLEAMANGERVIEW_H

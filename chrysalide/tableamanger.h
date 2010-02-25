#ifndef TABLEAMANGER_H
#define TABLEAMANGER_H
#include <QPointF>
#include "typetable.h"
class typeTable;
class tableAManger : public QObject
{
    Q_OBJECT

    private:
        int numero;
        int capacite;
        //salle de la table
        typeTable* type;
        //position
        QPointF position;

    public:
        tableAManger(int, int, int);//hum....
        tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY);//constructeur qui cree la table ds le sgbd
        tableAManger(int);//constructeur depuis le sgbd
        void setCapacite(int);
        void setPos(QPointF pPos);
        int getCapacite(){return capacite;};
        QPointF getPosition(){return position;};
        void setType(typeTable*);
        static QVector<tableAManger*> recupererTables();

    signals:
        void capaciteChanged(int);
        void typeChanged(typeTable*);
};

#endif // TABLEAMANGER_H

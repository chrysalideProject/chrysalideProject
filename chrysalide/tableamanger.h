#ifndef TABLEAMANGER_H
#define TABLEAMANGER_H

#include "typetable.h"

class tableAManger : public QObject
{
    Q_OBJECT

    private:
        int numero;
        int capacite;
        typeTable* type;

    public:
        tableAManger(int, int, int);
        void setCapacite(int);
        void setType(typeTable*);
        static QVector<tableAManger*> recupererTables();

    signals:
        void capaciteChanged(int);
        void typeChanged(typeTable*);
};

#endif // TABLEAMANGER_H

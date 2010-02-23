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
        void setTypeTable(typeTable*);
        static QVector<tableAManger*> recupererTables();
};

#endif // TABLEAMANGER_H

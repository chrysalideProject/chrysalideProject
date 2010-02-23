#ifndef TYPETABLE_H
#define TYPETABLE_H

#include <QObject>
#include <QSqlQuery>
#include <QVariant>
#include <QVector>

class typeTable : public QObject
{
    Q_OBJECT

    private:
        int numero;
        QString libelle;

    public:
        typeTable(int);
        static QVector<typeTable*> recupererTypesTables();
};

#endif // TYPETABLE_H

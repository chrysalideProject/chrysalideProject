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

        int getNumero(){ return numero; }
        QString getLibelle(){ return libelle; }

        static QVector<typeTable*> recupererTypesTables();
        static typeTable* nouveauTypeTable();

    signals:
        void typesTablesChanged();
};

#endif // TYPETABLE_H

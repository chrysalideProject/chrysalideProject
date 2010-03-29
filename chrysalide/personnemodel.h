#ifndef PERSONNEMODEL_H
#define PERSONNEMODEL_H

#include <QObject>
#include <QSqlQuery>
#include <QVariant>

class personneModel : public QObject
{
    Q_OBJECT

    protected:
        long id;
        QString nom;
        QString prenom;

    public:
        personneModel(long, QString, QString);
        personneModel(int);
        QString getNom(){return nom;};
        QString getPrenom(){return prenom;};
        QString type;
        long getId(){return id;};
        static int insert(QString,QString);
        void majProfil();
        void supprimer();
        void estAbsent(int noRepas,bool absent);
        void prendreRepas(int noRepas,int noTable);
        void prendreRepasAvantLHeure(int noRepas);
        void mangerExterieur(int noRepas,bool exterieur);
        bool estALExterieur(int noRepas);
};

#endif // PERSONNEMODEL_H

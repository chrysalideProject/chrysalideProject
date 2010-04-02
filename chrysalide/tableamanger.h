#ifndef TABLEAMANGER_H
#define TABLEAMANGER_H
#include <QPointF>
#include <QMap>
#include "typetable.h"
#include "patientmodel.h"
#include "surveillantmodel.h"

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
        int repasCourant;
        void remplirLesMaps(int noRepas);
        void viderLesMaps();

    public:

        ~tableAManger();
        tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY,int);//constructeur qui cree la table ds le sgbd
        tableAManger(int,int);//constructeur à partir de l'identifiant va chercher les infos dans le sgbd
        QMap<int, patientModel*> mapPatients;
        QMap<int, surveillantModel*> mapSurveillants;
        QMap<int, personneModel*>mapAutresPersonnes;
        void setCapacite(int);
        void setPos(QPointF pPos);
        int getCapacite(){return capacite;};
        int getNumero(){ return numero; };
        typeTable* getType(){ return type; };
        void save();
        QPointF getPosition(){return position;};
        void setType(typeTable*);
        //membres de classe
        static QVector<tableAManger*> recupererTables(int noRepas);
        static QVector<tableAManger*> recupererTables(QString typeTable,int noRepas);
        //fin membres de classe
        void supprime();
        void setTypeTable(int);
        bool isCompatibleWith(patientModel*);
        bool estPleine();
        bool estVide();
        bool ajouterPatient(patientModel*);
        bool ajouterPatientSansCompatibilite(patientModel*);
        void recupererPersonnes(int noRepas);
        void enregistrer(int noRepas);
        void supprimer();
    signals:
        void capaciteChanged(int);
        void typeChanged(typeTable*);
        void tableSupprimee();
        // Individus à la table

};

#endif // TABLEAMANGER_H

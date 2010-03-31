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
        surveillantModel* surveillant;
        void viderLesMaps();

    public:

        ~tableAManger();
        tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY);//constructeur qui cree la table ds le sgbd
        tableAManger(int);//constructeur à partir de l'identifiant va chercher les infos dans le sgbd
        QMap<int, patientModel*> mapPatients;
        QMap<int, surveillantModel*> mapSurveillants;
        QMap<int, personneModel*>mapAutresPersonnes;

        void setNoRepas(int noRepas);
        void setCapacite(int);
        void setPos(QPointF pPos);
        int getCapacite(){return capacite;};
        int getNumero(){ return numero; };
        typeTable* getType(){ return type; };
        void save();
        QPointF getPosition(){return position;};
        void setType(typeTable*);
        static QVector<tableAManger*> recupererTables();
        static QVector<tableAManger*> recupererTables(QString typeTable);
        void supprime();
        void afficher();

        void setTypeTable(int);
        bool needsSurveillant();
        bool isCompatibleWith(patientModel*);
        bool estPleineSansSurveillant();
        bool estPleine();
        bool estVide();
        bool ajouterSurveillant(surveillantModel*);
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

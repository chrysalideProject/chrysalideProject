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
        QPointF position;// Individus à la table
        QMap<int, patientModel*> mapPatients;
        QMap<int, surveillantModel*> mapSurveillants;
        surveillantModel* surveillant;


    public:
        tableAManger(int, int, int);//hum....
        tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY);//constructeur qui cree la table ds le sgbd
        tableAManger(int);//constructeur depuis le sgbd
        void setCapacite(int);
        void setPos(QPointF pPos);
        int getCapacite(){return capacite;};
        int getNumero(){ return numero; };
        typeTable* getType(){ return type; };
        void save();
        QPointF getPosition(){return position;};
        void setType(typeTable*);
        static QVector<tableAManger*> recupererTables();
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
        static void nouvelleTable();
        void supprimer();
    signals:
        void capaciteChanged(int);
        void typeChanged(typeTable*);
        void tableSupprimee();

};

#endif // TABLEAMANGER_H

#include "tableamanger.h"
#include <QDebug>

void tableAManger::nouvelleTable(){

    QSqlQuery nouvelle("INSERT INTO TABLEAMANGER (capacite, typeTable) VALUES (6, (SELECT numero FROM TYPETABLE LIMIT 0,1))");

}
tableAManger::tableAManger(int pNumero)
{
    //construction d'une table à partir du sgbd
    qDebug()<<"tableAManger::tableAManger(int pNumero)";
    numero = pNumero;
    QSqlQuery selectTable("SELECT capacite,typetable,x,y FROM TABLEAMANGER WHERE numero = "+QString::number(numero));

    if (selectTable.first())
    {

        capacite = selectTable.value(0).toInt();
        type=new typeTable(selectTable.value(1).toInt());
        this->position=QPointF(selectTable.value(2).toDouble(),selectTable.value(3).toDouble());

    }

}
tableAManger::tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY)
{
    //constructeur sans numéro
    QSqlQuery selectNumero("SELECT max(numero)+1 FROM TABLEAMANGER");
    if(selectNumero.first())
    {
        int identifiant=selectNumero.value(0).toInt();
        numero=identifiant;
        capacite=pCapacite;
        position=QPointF(pX,pY);
        this->type=new typeTable(pNumeroTypeTable);
        QString texteRequete="insert into TABLEAMANGER (numero,capacite,x,y,typetable) values("+QString::number(identifiant)+
                              ","+QString::number(pCapacite)+","+QString::number(pX)+","+QString::number(pY)+","+QString::number(pNumeroTypeTable)+")";
        qDebug()<<texteRequete;
        QSqlQuery insertTable(texteRequete);
        insertTable.exec();
    }
}
tableAManger::tableAManger(int pNumero, int pCapacite, int pNumeroTypeTable)
{
    numero = pNumero;
    capacite = pCapacite;

    type = new typeTable(pNumeroTypeTable);
}


void tableAManger::setCapacite(int pCapacite){

    capacite = pCapacite;
    QSqlQuery query("UPDATE TABLEAMANGER SET capacite = "+QString::number(capacite) +" where numero="+ QString::number(numero));
    query.exec();

    emit capaciteChanged(capacite);

}
void tableAManger::setPos(QPointF pPos)
{
    //sauvegarde de la position de la tableAManger dans le sgbd
    qDebug()<<"void tableAManger::setPos(QPointF pPos)";
  position=pPos;
  QString texteRequete="UPDATE TABLEAMANGER SET x= "+QString::number(position.x())+", y="+QString::number(position.y())+" where numero="+ QString::number(numero);
  QSqlQuery query(texteRequete);
    query.exec();

}


void tableAManger::setType(typeTable* pTypeTable)
{
    type = pTypeTable;
    emit typeChanged(type);
}


QVector<tableAManger*> tableAManger::recupererTables()
{
    qDebug()<<"QVector<tableAManger*> tableAManger::recupererTables()";

    QVector<tableAManger*> resultat;

    QSqlQuery tables("SELECT * FROM TABLEAMANGER");

    while (tables.next())
    {
        resultat.push_back(new tableAManger(tables.value(0).toInt(), tables.value(1).toInt(), tables.value(2).toInt()));
    }
    return resultat;

}
void tableAManger::supprime()
{
    qDebug()<<"void tableAManger::supprime()";
    //supression de la table dans le sgbd
    QSqlQuery reqsupr("delete from TABLEAMANGER where numero="+QString::number(this->numero));
    reqsupr.exec();
}
void tableAManger::supprimer(){

    QSqlQuery suppression("DELETE FROM TABLEAMANGER WHERE numero = "+QString::number(numero));
    emit tableSupprimee();

}void tableAManger::setTypeTable(int pType){

    type->setTypeTable(pType);

}
void tableAManger::save(){

    QSqlQuery saving("UPDATE TABLEAMANGER SET capacite = "+QString::number(capacite)+" , typeTable = "+QString::number(type->getNumero())+" WHERE numero = "+QString::number(numero));

}

bool tableAManger::needsSurveillant(){

    bool found = false;
    int cpt = 0;

    // Pour voir si la table a besoin d'un surveillant, on regarde si elle contient quelqu'un qui
    // a besoin d'etre surveillé

    while(cpt < mapPatients.size() && !found){
        if (mapPatients.value(mapPatients.keys().at(cpt))->getIdSurveillance() == 3){
            found = true;
        }
        else cpt++;
    }

    // On a trouvé quelqu'un qui a besoin d'etre surveillé, on regarde si il n'y aurait pas déja un surveillant
    if (found){
        return (mapSurveillants.size() == 0);
    }

    else return false;

}

bool tableAManger::isCompatibleWith(patientModel* lePatient){

        // La table contient-elle quelqu'un qui n'ait pas le meme regime ?
        bool foundNotCompatible = false;
        int cpt = 0;

        while (!foundNotCompatible && cpt < mapPatients.size()){
            qDebug()<<mapPatients.value(mapPatients.keys().at(cpt))->getNom()<<" : "<<mapPatients.value(mapPatients.keys().at(cpt))->getIdRegime();
            qDebug()<<lePatient->getNom()<<" : "<<lePatient->getIdRegime();
            if (mapPatients.value(mapPatients.keys().at(cpt))->getIdRegime() != lePatient->getIdRegime()){
                foundNotCompatible = true;
            }
            else cpt++;
        }

        if (foundNotCompatible){
            return false;
        }

        else{
            // La table est compatible avec le patient
            qDebug()<<lePatient->getNom()<<" est compatible avec la table "<<numero;
            return true;
        }

}

bool tableAManger::ajouterPatient(patientModel* lePatient){

    // On regarde si la table n'est pas pleine
    if (!estPleineSansSurveillant()){

        // On vérifie que le patient soit compatible avec la table
        if (isCompatibleWith(lePatient)){

            mapPatients[lePatient->getId()] = lePatient;
            return true;

        }

        else return false;
    }

    else return false;

}

bool tableAManger::ajouterPatientSansCompatibilite(patientModel* lePatient){

    // On regarde si la table n'est pas pleine
    if (!estPleineSansSurveillant()){

            mapPatients[lePatient->getId()] = lePatient;
            return true;
    }

    else return false;

}

void tableAManger::afficher(){

    qDebug()<<"************************";
    qDebug()<<QString::fromUtf8("Table N°")<<numero;

    for (int cpt=0; cpt < mapSurveillants.size(); cpt++){

        qDebug()<<cpt+1<<" : "<<mapSurveillants.value(mapSurveillants.keys().at(cpt))->getNom()<<" (surveillant)";

    }

    for (int cpt=0; cpt < mapPatients.size(); cpt++){

        qDebug()<<cpt+2<<" : "<<mapPatients.value(mapPatients.keys().at(cpt))->getNom();

    }

    qDebug()<<"****************************";

}

bool tableAManger::ajouterSurveillant(surveillantModel* leSurveillant){

    if (!estPleine()){
        mapSurveillants[leSurveillant->getId()] = leSurveillant;
        return true;
    }

    else return false;

}

bool tableAManger::estPleineSansSurveillant(){

    return (mapPatients.size() == 5);
}

bool tableAManger::estPleine(){

    return (mapPatients.size()+mapSurveillants.size() == 6);
}

bool tableAManger::estVide(){
    return (mapPatients.size() == 0);
}


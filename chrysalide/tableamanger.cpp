#include "tableamanger.h"
#include <QDebug>

void tableAManger::viderLesMaps()
{
    qDebug()<<"void tableAManger::viderLesMaps()";
    foreach(patientModel* lePatient, mapPatients)
    {
        delete lePatient;
    }
    mapPatients.clear();
    foreach(surveillantModel* leSurveillant, mapSurveillants)
    {
        delete leSurveillant;
    }
    mapSurveillants.clear();

    foreach(personneModel* laPersonne, mapAutresPersonnes)
    {
        delete laPersonne;
    }
    mapAutresPersonnes.clear();
}

tableAManger::~tableAManger()
{
    qDebug()<<"tableAManger::~tableAManger()";
    //effacement du type
    delete type;
    //effacement de ce qu'il y a dans les maps
    viderLesMaps();


}
tableAManger::tableAManger(int pNumero)
{
    //construction d'une table à partir du sgbd
    qDebug()<<"tableAManger::tableAManger(int pNumero)";
    numero = pNumero;
    QString texteReq="SELECT capacite,typetable,x,y FROM TABLEAMANGER WHERE numero = "+QString::number(numero);
    qDebug()<<texteReq;
    QSqlQuery selectTable(texteReq);

    if (selectTable.first())
    {
        this->numero=pNumero;
        capacite = selectTable.value(0).toInt();
        type=new typeTable(selectTable.value(1).toInt());
        this->position=QPointF(selectTable.value(2).toDouble(),selectTable.value(3).toDouble());
    }

}
tableAManger::tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY)
{
    qDebug()<<"tableAManger::tableAManger(int pCapacite, int pNumeroTypeTable,double pX,double pY)";
    //constructeur sans numéro cela cree la tableamanger dans le sgbd
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
void tableAManger::setNoRepas(int noRepas)
{
    qDebug()<<"void tableAManger::setNoRepas(int noRepas)";
    repasCourant=noRepas;
    remplirLesMaps(noRepas);
}

void tableAManger::setCapacite(int pCapacite)
{
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
    qDebug()<<texteRequete;
    QSqlQuery query;
    query.exec(texteRequete);

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
        resultat.push_back(new tableAManger(tables.value(0).toInt()));
    }
    return resultat;

}
void tableAManger::remplirLesMaps(int noRepas)
{
    qDebug()<<"voidtableAManger::remplirLesMaps(int noRepas)";
    viderLesMaps();
    QString texteReq="SELECT idPersonne FROM  prendre  where idtableamanger="+QString::number(numero)+" and idrepas="+QString::number(noRepas);
    qDebug()<<texteReq;
    QSqlQuery personnes(texteReq);

    while (personnes.next())
    {
        if(personneModel(personnes.value(0).toInt()).type=="surveillant")
        {
            mapSurveillants[personnes.value(0).toInt()]=new surveillantModel(personnes.value(0).toInt());
        }
        else
        {
            if(personneModel(personnes.value(0).toInt()).type=="patient")
            {
                mapPatients[personnes.value(0).toInt()]=new patientModel(personnes.value(0).toInt());
            }
            else
            {
                mapAutresPersonnes[personnes.value(0).toInt()]=new personneModel(personnes.value(0).toInt());
            }
        }

    }
}

QVector<tableAManger*> tableAManger::recupererTables(QString typeTable)
{
    qDebug()<<"QVector<tableAManger*> tableAManger::recupererTables()";

    QVector<tableAManger*> resultat;
    QString texteRequete="SELECT * FROM TABLEAMANGER ta inner join typetable ty on ta.typetable= ty.idtypetable  where ty.libelle='"+typeTable+"' ";
    QSqlQuery tables(texteRequete);

    while (tables.next())
    {
        resultat.push_back(new tableAManger(tables.value(0).toInt()));
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

bool tableAManger::isCompatibleWith(patientModel* lePatient)
{

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

    qDebug()<<"bool tableAManger::ajouterPatient(patientModel* lePatient)";
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

    qDebug()<<"bool tableAManger::ajouterPatientSansCompatibilite(patientModel* lePatient)";
    // On regarde si la table n'est pas pleine
    if (!estPleineSansSurveillant()){

        mapPatients[lePatient->getId()] = lePatient;
        return true;
    }

    else return false;

}
void tableAManger::enregistrer(int noRepas)
{
    qDebug()<<"void tableAManger::enregistrer(int noRepas)";
    //enregistrement dans la base de données des patients à la table ce repas

    foreach(surveillantModel* surveillant,mapSurveillants)
    {
        int num=surveillant->getId();
        QSqlQuery insertion("insert into prendre(idPersonne,idRepas,idTableAManger) values("+QString::number(num)+","+QString::number(noRepas)+","+QString::number(numero)+")");
        insertion.exec();
    }
    foreach(patientModel* patient,mapPatients)
    {
        int num=patient->getId();
        QSqlQuery insertion("insert into prendre(idPersonne,idRepas,idTableAManger) values("+QString::number(num)+","+QString::number(noRepas)+","+QString::number(numero)+")");
        insertion.exec();
    }
    foreach(personneModel* laPersonne,mapAutresPersonnes)
    {
        int num=laPersonne->getId();
        QSqlQuery insertion("insert into prendre(idPersonne,idRepas,idTableAManger) values("+QString::number(num)+","+QString::number(noRepas)+","+QString::number(numero)+")");
        insertion.exec();
    }

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


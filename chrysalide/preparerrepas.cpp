#include "preparerrepas.h"
#include "ui_preparerrepas.h"
#include <QDebug>
#include "repasmodel.h"
#include "surveillantview.h"
#include "autrepersonnelview.h"
#include <QVariant>
#include <QTreeWidgetItem>
#include <QVariant>
#include <QMessageBox>
#include <QVector>


preparerRepas::preparerRepas(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::preparerRepas)
{
    //constructeur
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    changeRepasCourant();
    initialiserCuisiniers();
    initialiserSurveillants();
    initialiserAutresPersonnels();
    initialiserTreeWidgetExterieur();
    initialiserServeurs();
    initialiserAbsents();
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(changeRepasCourant()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeRepasCourant()));
    connect (ui->listWidgetCuisinier,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerCuisinier(QListWidgetItem*)));
    connect (ui->listWidgetSurveillants,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerSurveillant(QListWidgetItem*)));
    connect (ui->listWidgetAutrePersonnel,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerAutrePersonnel(QListWidgetItem*)));
    qDebug()<<"void DialogSalleConceptor::remplirComboTypeDeTable()";
    //vidons la combo
    ui->comboBoxSalle->clear();
    //ajout des types de tables de la base de données dans le vecteur
    vectTypesTable=typeTable::recupererTypesTables();
     //on remplit la combo de choix de la salle/typeDeTable
    foreach(typeTable* tT,vectTypesTable)
    {
        ui->comboBoxSalle->insertItem(0,tT->getLibelle(),(qlonglong)tT);
    }
    //on raffrachit la vue du typeTable Courant
    if(ui->comboBoxSalle->count()>0)
    {
    ui->comboBoxSalle->setCurrentIndex(0);
}

    //placerPersonnes();
}
void preparerRepas::changeRepasCourant()
{
    //qd la date ou midi soir change cgt du repas courant
    QDate laDate=ui->dateEdit->date();
    QString midiSoir=ui->comboBox->currentText();
    repasModel* repas=new repasModel(laDate,midiSoir);
    repasCourant=repas->getNumero();
    //rafraichissement des listes
    initialiserCuisiniers();
    initialiserSurveillants();
    initialiserAutresPersonnels();
    ui->treeWidgetPatientsParMetiers->setEnabled(midiSoir=="Midi");
    if(midiSoir=="Midi")
    {
      initialiserTreeWidgetExterieur();
    }
    else ui->treeWidgetPatientsParMetiers->clear();

    initialiserServeurs();
    initialiserAbsents();


}
void preparerRepas::initialiserServeurs()
{
    //remplir et proposer
    qDebug()<<"void preparerRepas::initialiserServeurs()";
    //d'abord vider la liste
    ui->listWidgetServeurs->clear();
    //remplir la liste des serveurs du jour
    QString texteRequete="select prenom||' '||nom,id from personne inner join patient on patient.idPersonne=personne.id inner join prendre on prendre.idPersonne=personne.id inner join tableAManger on prendre.idTableAManger=tableamanger.numero inner join typetable on typeTable.numero=tableamanger.typeTable  where prendre.idRepas="+QString::number(repasCourant)+" and typetable.libelle='Cuisiniers'";
    qDebug()<<texteRequete;
    QSqlQuery requete(texteRequete);
    while(requete.next())
    {
        QListWidgetItem* serveur=new QListWidgetItem(requete.value(0).toString());
        serveur->setData(32,requete.value(1));
        ui->listWidgetServeurs->addItem(serveur);
    }
    //les autres vont aller dans la combo.
    QString texteRequete1="select prenom||' '||nom,patient.idPersonne,((select count(*) from prendre inner join tableamanger on tableamanger.numero=prendre.idTableAManger inner join typetable on tableamanger.typeTable=typetable.numero where typetable.libelle='Cuisiniers' and prendre.idPersonne=patient.idPersonne)/(select max(count(*),1) from prendre where prendre.idPersonne=patient.idPersonne) ) as tauxDeService from personne inner join patient on patient.idPersonne=personne.id inner join surveillance on patient.idSurveillance=surveillance.id where surveillance.libelle<>'forte' and not exists (select * from prendre where idPersonne=patient.idPersonne and idRepas="+QString::number(repasCourant)+") order by tauxDeService asc, random() asc";
    qDebug()<<texteRequete1;
    QSqlQuery requete1(texteRequete1);
    //vidons la combo
    ui->comboBoxPatientsPouvantServir->clear();
    while(requete1.next())
    {
        ui->comboBoxPatientsPouvantServir->addItem(requete1.value(0).toString(),requete1.value(1));
    }
    ui->salleViewCourante->setScene(new QGraphicsScene(this));
}
void preparerRepas::initialiserAbsents()
{
    ui->listWidgetAbsents->clear();
    //obtention des absents et ajout à la liste
    QString texteRequete="select prenom||' '||nom,id from personne inner join patient on patient.idPersonne=personne.id inner join prendre on prendre.idPersonne=personne.id inner join tableAManger on prendre.idTableAManger=tableamanger.numero inner join typetable on typeTable.numero=tableamanger.typeTable  where prendre.idRepas="+QString::number(repasCourant)+" and typetable.libelle='Absents'";
    qDebug()<<texteRequete;
    QSqlQuery requete(texteRequete);
    while(requete.next())
    {
        QListWidgetItem* absent=new QListWidgetItem(requete.value(0).toString());
        absent->setData(32,requete.value(1));
        ui->listWidgetAbsents->addItem(absent);
    }
    //les autres vont aller dans la combo.
    QString texteRequete1="select  prenom||' '||nom,patient.idPersonne from personne inner join patient on personne.id=patient.idPersonne  left outer join prendre on patient.idPersonne=prendre.idPersonne and prendre.idRepas="+QString::number(repasCourant)+" where prendre.idPersonne is null";

    qDebug()<<texteRequete1;
    QSqlQuery requete1(texteRequete1);
    //vidons la combo
    ui->comboBoxPatientsPouvantEtreAbsents->clear();
    while(requete1.next())
    {
        ui->comboBoxPatientsPouvantEtreAbsents->addItem(requete1.value(0).toString(),requete1.value(1));
    }

}

void preparerRepas::initialiserTreeWidgetExterieur()
{
    ui->treeWidgetPatientsParMetiers->clear();
    qDebug()<<"void preparerRepas::initialiserTreeWidgetExterieur()";
    QMap<int,QString> mapMetiers=patientModel::recupererMetiers();
    //deconnecter le signal du slot
    ui->treeWidgetPatientsParMetiers->disconnect(this);
    for(QMap<int,QString>::iterator it=mapMetiers.begin();it!=mapMetiers.end();it++)
    {
        QStringList(it.value());
        QTreeWidgetItem * nouv=new QTreeWidgetItem(QStringList(it.value()));;
        nouv->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
        nouv->setCheckState(0,Qt::Unchecked);
        ui->treeWidgetPatientsParMetiers->addTopLevelItem(nouv);//ajout du métier

        QMap<int,patientModel *> mapPatients=patientModel::recupererPatientsAvecSelection("idtravail="+QString::number(it.key()));
        //boucle d'ajout des patients
        for(QMap<int,patientModel *>::iterator itP=mapPatients.begin();itP!=mapPatients.end();itP++)
        {
            patientModel * lePatient=itP.value();
            QString data2=lePatient->getPrenom()+" "+lePatient->getNom();
            QTreeWidgetItem * nouvP=new QTreeWidgetItem(QStringList(data2));

            nouvP->setData(1,32,(int)lePatient->getId());//je stocke le numero du patient
            nouv->addChild(nouvP);
            nouvP->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
            Qt::CheckState etat;
            if(lePatient->estALExterieur(repasCourant))etat=Qt::Checked;
            else etat=Qt::Unchecked;
            nouvP->setCheckState(0,etat);
        }
    }
    //et reconnexion
    connect(ui->treeWidgetPatientsParMetiers,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(on_treeWidgetPatientsParMetiers_itemChanged(QTreeWidgetItem*,int)));

}

void preparerRepas::initialiserCuisiniers()
{
    qDebug()<<"void preparerRepas::initialiserCuisiniers()";
    //nettoyage de la map
    for(QMap<int,cuisinierModel*>::iterator it=mapCuisiniers.begin();it!=mapCuisiniers.end();it++)
    {
        delete it.value();

    }
    mapCuisiniers.clear();
    ui->listWidgetCuisinier->clear();
    //obtention de la map
    mapCuisiniers=cuisinierModel::recupererCuisiniers();
    for(QMap<int,cuisinierModel*>::iterator it=mapCuisiniers.begin();it!=mapCuisiniers.end();it++)
    {
        cuisinierView * nouv=new cuisinierView();
        nouv->setModele(it.value());
        nouv->setText(nouv->text());
        qDebug()<<nouv->text();
        Qt::CheckState etat;
        if(nouv->modele->travaille(ui->dateEdit->date(),ui->comboBox->currentText()))
            etat=Qt::Checked;
        else etat=Qt::Unchecked;
        nouv->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        nouv->setCheckState(etat);
        ui->listWidgetCuisinier->insertItem(0,nouv);

    }

}
void preparerRepas::initialiserSurveillants()
{
    qDebug()<<"void preparerRepas::initialiserSurveillant()";
    //nettoyage de la map
    for(QMap<int,surveillantModel*>::iterator it=mapSurveillants.begin();it!=mapSurveillants.end();it++)
    {
        delete it.value();

    }
    mapSurveillants.clear();
    ui->listWidgetSurveillants->clear();
    //obtention de la map
    mapSurveillants=surveillantModel::recupererSurveillants();
    for(QMap<int,surveillantModel*>::iterator it=mapSurveillants.begin();it!=mapSurveillants.end();it++)
    {
        surveillantView * nouv=new surveillantView();
        nouv->setModele(it.value());
        nouv->setText(nouv->text());
        qDebug()<<nouv->text();
        Qt::CheckState etat;
        if(nouv->modele->travaille(ui->dateEdit->date(),ui->comboBox->currentText()))
            etat=Qt::Checked;
        else etat=Qt::Unchecked;
        nouv->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        nouv->setCheckState(etat);
        ui->listWidgetSurveillants->insertItem(0,nouv);

    }

}
void preparerRepas::initialiserAutresPersonnels()
{
    qDebug()<<"void preparerRepas::initialiserAutrePersonnel()";
    //nettoyage de la map
    for(QMap<int,autrePersonnelModel*>::iterator it=mapAutrePersonnels.begin();it!=mapAutrePersonnels.end();it++)
    {
        delete it.value();

    }
    mapAutrePersonnels.clear();
    ui->listWidgetAutrePersonnel->clear();
    //obtention de la map
    mapAutrePersonnels=autrePersonnelModel::recupererAutrePersonnels();
    for(QMap<int,autrePersonnelModel*>::iterator it=mapAutrePersonnels.begin();it!=mapAutrePersonnels.end();it++)
    {
        autrePersonnelView * nouv=new autrePersonnelView();
        nouv->setModele(it.value());
        nouv->setText(nouv->text());
        qDebug()<<nouv->text();
        Qt::CheckState etat;
        if(nouv->modele->travaille(ui->dateEdit->date(),ui->comboBox->currentText()))
            etat=Qt::Checked;
        else etat=Qt::Unchecked;
        nouv->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        nouv->setCheckState(etat);
        ui->listWidgetAutrePersonnel->insertItem(0,nouv);

    }

}
void preparerRepas::faireTravaillerCuisinier(QListWidgetItem * leCuisinier)
{
    if (leCuisinier->checkState()==Qt::Checked)
    {
        ((cuisinierView*)leCuisinier)->modele->prendreRepasAvantLHeure(repasCourant);
    }
    else
    {
        ((cuisinierView*)leCuisinier)->modele->prendreRepas(repasCourant,false);
    }
}
void preparerRepas::faireTravaillerSurveillant(QListWidgetItem * leSurveillant)
{
    qDebug()<<"void preparerRepas::faireTravaillerSurveillant(QListWidgetItem * leSurveillant)";
    if (leSurveillant->checkState()==Qt::Checked)
    {
        //demander s'il surveille à l'intérieur ou l'extérieur
        if(QMessageBox::information(this,"Lieu de travail","Ce suveillant surveille à l'extérieur",QMessageBox::No|QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
            ((surveillantView*)leSurveillant)->modele->mangerExterieur(repasCourant,true);
        else
        {
            //il faut lui affecter une table à l'intérieur à laquelle il n'y a pas encore de suveillant
            QString texteRequete="select numero from tableamanger where typetable=(select numero from typeTable where libelle='"+QObject::tr("Intèrieur")+"') and not exists(select * from prendre inner join personne on prendre.idPersonne= personne.id inner join surveillant on surveillant.idPersonne=personne.id where idtableamanger=tableamanger.numero and idRepas="+QString::number(repasCourant)+")";
            QSqlQuery reqTableSansSurveillant(texteRequete);
            reqTableSansSurveillant.first();
            int numeroDeLaTable=reqTableSansSurveillant.value(0).toInt();
            ((surveillantView*)leSurveillant)->modele->prendreRepas(repasCourant,numeroDeLaTable);
        }
    }
    else
    {
        ((surveillantView*)leSurveillant)->modele->prendreRepas(repasCourant,false);
    }
}
void preparerRepas::faireTravaillerAutrePersonnel(QListWidgetItem * employe)
{
    if (employe->checkState()==Qt::Checked)
    {
        ((autrePersonnelView*)employe)->modele->prendreRepasAvantLHeure(repasCourant);//ils prennent leur repas à la table personnel
    }
    else
    {
        ((personneModel*) ((autrePersonnelView*)employe)->modele)->prendreRepas(repasCourant,false);
    }
}
void preparerRepas::updateView(){
    //visualisation des tables:
    for (int cpt=0; cpt < tablesAManger.size(); cpt++){
        tablesAManger[cpt]->afficher();
    }

}

void preparerRepas::placerPersonnes(){

    // On récupère nos patients à placer
    mapPatients = patientModel::recupererPatientsNonPlaces(repasCourant);

    // On récupère nos surveillants
    QMap<int, surveillantModel*> mapSurveillants = surveillantModel::recupererSurveillants(repasCourant);
    //combien sont-ils
    int nombreDeTablesAvecSurveillant=mapSurveillants.count();

    //obtention des tables des surveillants
    QVector <tableAManger*> vecteurTablesSurveillees;
    for (QMap<int, surveillantModel*>::iterator gary = mapSurveillants.begin(); gary != mapSurveillants.end(); gary++)
    {
        vecteurTablesSurveillees.push_back(new tableAManger((gary.value()->getNoTable(repasCourant))));
    }
    //distribution des patients à surveiller aux tables des surveillants
    QMap<int, patientModel*> mapPatientsSurveillanceElevee;
    int nombreDePatientsASurveiller=0;

    for (QMap<int, patientModel*>::iterator itPatient = mapPatients.begin();  itPatient!= mapPatients.end(); itPatient++)
    {
        if (itPatient.value()->getIdSurveillance() == 3)
        {
            mapPatientsSurveillanceElevee[itPatient.key()] = mapPatients.take(itPatient.key());
            //affectation à une des tables du vecteur
            vecteurTablesSurveillees[nombreDePatientsASurveiller%nombreDeTablesAvecSurveillant]->ajouterPatient(itPatient.value());
            nombreDePatientsASurveiller++;
        }
    }

    // On récupère nos tables de l'intérieur
    tablesAManger = tableAManger::recupererTables();

    // On place ensuite le reste des patients en les répartissant dans trois groupes
    QMap<int, patientModel*> patientsRegime;
    QMap<int, patientModel*> patientsSurveillance;
    QMap<int, patientModel*> patientsNormaux;

    for (QMap<int, patientModel*>::iterator gary = mapPatients.begin(); gary != mapPatients.end(); gary++){

        int typeRegime = gary.value()->getIdRegime();
        switch(typeRegime){

            // Régime
        case 1:
            qDebug()<<gary.value()->getNom()<<" est au régime";
            patientsRegime[gary.key()] = mapPatients.take(gary.key());
            break;

            // Surveillance
        case 2:
            qDebug()<<gary.value()->getNom()<<" n'a pas le droit au pain";
            patientsSurveillance[gary.key()] = mapPatients.take(gary.key());
            break;

            // Normal
        case 3:
            qDebug()<<gary.value()->getNom()<<" peut manger autant de pain qu'il veut";
            patientsNormaux[gary.key()] = mapPatients.take(gary.key());
            break;

        }

    }

    // Tant que tous les patients Régime n'ont pas été placés
    int cpt=0;
    while (patientsRegime.size() > 0 && cpt < tablesAManger.size()){

        if (!tablesAManger[cpt]->ajouterPatient(patientsRegime.begin().value())){
            cpt++;
        }
        else patientsRegime.take(patientsRegime.begin().key());

    }

    // Tant que tous les patients Surveillance n'ont pas été placés
    cpt = 0;
    while (patientsSurveillance.size() > 0 && cpt < tablesAManger.size()){

        if (!tablesAManger[cpt]->ajouterPatient(patientsSurveillance.begin().value())){
            cpt++;
        }
        else patientsSurveillance.take(patientsSurveillance.begin().key());

    }

    // Tant que tous les patients Normaux n'ont pas été placés
    cpt = 0;
    while (patientsNormaux.size() > 0 && cpt < tablesAManger.size()){

        if (!tablesAManger[cpt]->ajouterPatient(patientsNormaux.begin().value())){
            cpt++;
        }
        else patientsNormaux.take(patientsNormaux.begin().key());

    }

    mapPatients.clear();

    for (QMap<int, patientModel*>::iterator gary = patientsRegime.begin(); gary != patientsRegime.end(); gary++){
        mapPatients[gary.key()] = gary.value();
    }

    for (QMap<int, patientModel*>::iterator gary = patientsSurveillance.begin(); gary != patientsSurveillance.end(); gary++){
        mapPatients[gary.key()] = gary.value();
    }

    for (QMap<int, patientModel*>::iterator gary = patientsNormaux.begin(); gary != patientsNormaux.end(); gary++){
        mapPatients[gary.key()] = gary.value();
    }

    // On place maintenant le reste des patient qui n'ont pas trouvé de place là où il en reste
    cpt = 0;
    while (mapPatients.size() > 0 && cpt < tablesAManger.size()){

        if (!tablesAManger[cpt]->ajouterPatientSansCompatibilite(mapPatients.begin().value())){
            cpt++;
        }

        else{
            mapPatients.take(mapPatients.begin().key());
        }

    }

    // On place maintenant le reste des surveillants qui n'ont pas trouvé de place là où il en reste
    cpt = 0;
    while (mapSurveillants.size() > 0 && cpt < tablesAManger.size()){

        if (!tablesAManger[cpt]->ajouterSurveillant(mapSurveillants.begin().value())){
            cpt++;
        }
        else {
            mapSurveillants.take(mapSurveillants.begin().key());
        }

    }

    updateView();

}

preparerRepas::~preparerRepas()
{
    delete ui;
}

void preparerRepas::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void preparerRepas::on_pushButtonFermer_clicked()
{
    close();
}

void preparerRepas::on_treeWidgetPatientsParMetiers_itemChanged(QTreeWidgetItem* item, int column)
{
    qDebug()<<"void preparerRepas::on_treeWidgetPatientsParMetiers_itemChanged(QTreeWidgetItem* item, int column)";
    //si c'est un metier qui vient d'être coché ou décoché
    if(column==0)//changement d'état
    {
        if(item->parent()==0)
        {
            //recupération de l'état: coché ou non
            Qt::CheckState etat=item->checkState(0);
            //on coche ou décoche tous les patients qui ont ce métier
            for(int noEnfant=0;noEnfant<item->childCount();noEnfant++)
            {
                item->child(noEnfant)->setCheckState(0,etat);
            }

        }
        else
        {
            //sinon c'est donc un patient

            Qt::CheckState etat=item->checkState(0);
            patientModel * lePatient=new patientModel(item->data(1,32).toInt());
            if(etat==Qt::Unchecked)
            {
                lePatient->mangerExterieur(repasCourant,false);
            }
            else
            {
                lePatient->mangerExterieur(repasCourant,true);
            }
            //raffraichir la liste des serveurs
            initialiserServeurs();
        }
    }
}

void preparerRepas::on_pushButtonAjouterServeur_clicked()
{
    patientModel * lePatient=new patientModel(ui->comboBoxPatientsPouvantServir->itemData(ui->comboBoxPatientsPouvantServir->currentIndex()).toInt());
    lePatient->prendreRepasAvantLHeure(repasCourant);
    this->initialiserServeurs();
}

void preparerRepas::on_pushButtonAjouterAbsent_clicked()
{
    patientModel * lePatient=new patientModel(ui->comboBoxPatientsPouvantEtreAbsents->itemData(ui->comboBoxPatientsPouvantEtreAbsents->currentIndex()).toInt());
    lePatient->estAbsent(repasCourant,true);
    this->initialiserAbsents();
}

void preparerRepas::on_pushButtonValider_clicked()
{
    placerPersonnes();
}

void preparerRepas::on_comboBoxSalle_currentIndexChanged(int index)
{
    qDebug()<<"void preparerRepas::on_comboBoxSalle_currentIndexChanged(int index)";
    //si il y a un type dans la combo
    if(index!=-1)
    {
       //on fait correspondre la vue avec son modele
        ui->salleViewCourante->setTypeTable(typeTableCourant()->getNumero(),true);
   }
}
typeTable* preparerRepas::typeTableCourant()
{
    qDebug()<<"typeTable * preparerRepas::typeTableCourant()";
    return (typeTable*) ui->comboBoxSalle->itemData(ui->comboBoxSalle->currentIndex()).toLongLong();
}

#include "preparerrepas.h"
#include "ui_preparerrepas.h"
#include <QDebug>
#include "repasmodel.h"
#include "surveillantview.h"
#include "autrepersonnelview.h"
#include <QVariant>
#include "modelarbredespatientsparmetier.h"


preparerRepas::preparerRepas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preparerRepas)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    changeRepasCourant();
    initialiserCuisiniers();
    initialiserSurveillants();
    initialiserAutresPersonnels();

    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(changeRepasCourant()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeRepasCourant()));

    placerPersonnes();
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
    initialiserTreeWidgetExterieur();

}
void preparerRepas::initialiserTreeWidgetExterieur()
{
    qDebug()<<"void preparerRepas::initialiserTreeWidgetExterieur()";
    lesPatientsParMetier=new modelArbreDesPatientsParMetier("Métier\nPatient",this);
    ui->treeViewPatientsParMetiers->setModel(lesPatientsParMetier);
    //ui->treeViewPatientsParMetiers->show();

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
    connect (ui->listWidgetCuisinier,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerCuisinier(QListWidgetItem*)));
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
    connect (ui->listWidgetSurveillants,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerSurveillant(QListWidgetItem*)));
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
    connect (ui->listWidgetAutrePersonnel,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerAutrePersonnel(QListWidgetItem*)));
}
void preparerRepas::faireTravaillerCuisinier(QListWidgetItem * leCuisinier)
{
    if (leCuisinier->checkState()==Qt::Checked)
    {
        ((cuisinierView*)leCuisinier)->modele->prendreRepas(repasCourant);
    }
    else
    {
        ((cuisinierView*)leCuisinier)->modele->prendreRepas(repasCourant,false);
    }
}
void preparerRepas::faireTravaillerSurveillant(QListWidgetItem * leSurveillant)
{
    if (leSurveillant->checkState()==Qt::Checked)
    {
        ((surveillantView*)leSurveillant)->modele->prendreRepas(repasCourant);
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
        ((autrePersonnelView*)employe)->modele->prendreRepas(repasCourant);//ils prennent leur repas à la table personnel
    }
    else
    {
        ((personneModel*) ((autrePersonnelView*)employe)->modele)->prendreRepas(repasCourant,false);
    }
}
void preparerRepas::updateView(){

    for (int cpt=0; cpt < tablesAManger.size(); cpt++){
       tablesAManger[cpt]->afficher();
    }

}

void preparerRepas::placerPersonnes(){

    // On récupère nos patients à placer
    mapPatients = patientModel::recupererPatients();

    // On récupère nos surveillants
    mapSurveillants = surveillantModel::recupererSurveillants();

    // On récupère nos tables
    tablesAManger = tableAManger::recupererTables();


    // On a tout pour commencer

    // On commence par regrouper les patients ayant un niveau de surveillance élevé

    QMap<int, patientModel*> mapPatientsSurveillanceElevee;

    for (QMap<int, patientModel*>::iterator gary = mapPatients.begin(); gary != mapPatients.end(); gary++){
        if (gary.value()->getIdSurveillance() == 3){
            mapPatientsSurveillanceElevee[gary.key()] = mapPatients.take(gary.key());
        }
    }

    // On va les regrouper sur des tables
    for (QMap<int, patientModel*>::iterator gary = mapPatientsSurveillanceElevee.begin(); gary != mapPatientsSurveillanceElevee.end(); gary++){

        int cpt = 0;
        bool patientAdded = false;

        while (cpt < tablesAManger.size() && !patientAdded){

            patientAdded = tablesAManger[cpt]->ajouterPatient(gary.value());
            cpt++;

        }

    }

    // On place nos surveillants
    for (QMap<int, surveillantModel*>::iterator gary = mapSurveillants.begin(); gary != mapSurveillants.end(); gary++){

        qDebug()<<"placement du surveillant "<<gary.value()->getNom();

        bool assigned = false;
        int cpt = 0;

        while (!assigned && cpt < tablesAManger.size()){
            if (tablesAManger[cpt]->needsSurveillant()) {
                tablesAManger[cpt]->ajouterSurveillant(gary.value());
                mapSurveillants.take(gary.key());
                assigned = true;
            }

            else cpt++;
        }

    }

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
                qDebug()<<gary.value()->getNom()<<" peut bouffer autant de pain qu'il veut";
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

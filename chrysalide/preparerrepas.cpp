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
    initialiseComboTypeSalle();
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(changeRepasCourant()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeRepasCourant()));
    connect (ui->listWidgetCuisinier,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerCuisinier(QListWidgetItem*)));
    connect (ui->listWidgetSurveillants,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerSurveillant(QListWidgetItem*)));
    connect (ui->listWidgetAutrePersonnel,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(faireTravaillerAutrePersonnel(QListWidgetItem*)));



    //placerPersonnes();
}
void preparerRepas::initialiseComboTypeSalle()
{
    qDebug()<<"void preparerRepas::initialiseComboTypeSalle()";
    //déconnection du signal du slot
    disconnect(ui->comboBoxSalle,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBoxSalle_currentIndexChanged(int)));
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
    //reconnexion
    connect(ui->comboBoxSalle,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBoxSalle_currentIndexChanged(int)));
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
    //la vue doit porter sur le nouveau repas
    ui->salleViewCourante->setRepasCourant(repasCourant);

}
void preparerRepas::initialiserServeurs()
{
    //remplir et proposer
    qDebug()<<"void preparerRepas::initialiserServeurs()";
    //d'abord vider la liste
    ui->listWidgetServeurs->clear();
    //remplir la liste des serveurs du jour pas de serveur chez les patients nécessitant une forte surveillance
    QString texteRequete="select prenom||' '||nom,id from personne inner join patient on patient.idPersonne=personne.id inner join prendre on prendre.idPersonne=personne.id inner join tableAManger on prendre.idTableAManger=tableamanger.numero inner join typetable on typeTable.numero=tableamanger.typeTable  where  prendre.idRepas="+QString::number(repasCourant)+" and typetable.libelle='Cuisiniers'";
    qDebug()<<texteRequete;
    QSqlQuery requete(texteRequete);
    while(requete.next())
    {
        QListWidgetItem* serveur=new QListWidgetItem(requete.value(0).toString());
        serveur->setData(32,requete.value(1));
        ui->listWidgetServeurs->addItem(serveur);
    }
    //les autres vont aller dans la combo.
    QString texteRequete1="select prenom||' '||nom,patient.idPersonne,((select count(*) from prendre inner join tableamanger on tableamanger.numero=prendre.idTableAManger inner join typetable on tableamanger.typeTable=typetable.numero where patient.idSurveillance <3 and typetable.libelle='Cuisiniers' and prendre.idPersonne=patient.idPersonne)/(select max(count(*),1) from prendre where prendre.idPersonne=patient.idPersonne) ) as tauxDeService from personne inner join patient on patient.idPersonne=personne.id inner join surveillance on patient.idSurveillance=surveillance.id where surveillance.libelle<>'forte' and not exists (select * from prendre where idPersonne=patient.idPersonne and idRepas="+QString::number(repasCourant)+") order by tauxDeService asc, random() asc";
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
        if(QMessageBox::information(this,"Lieu de travail",tr("Ce surveillant surveille à l'extérieur?"),QMessageBox::No|QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
            ((surveillantView*)leSurveillant)->modele->mangerExterieur(repasCourant,true);
        else
        {
            //il faut lui affecter une table à l'intérieur à laquelle il n'y a pas encore de suveillant
            QString texteRequete="select numero from tableamanger where typetable=(select numero from typeTable where libelle='"+QObject::tr("Intèrieur")+"') and not exists(select * from prendre inner join personne on prendre.idPersonne= personne.id inner join surveillant on surveillant.idPersonne=personne.id where idtableamanger=tableamanger.numero and idRepas="+QString::number(repasCourant)+")";

            qDebug()<<texteRequete;

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
void preparerRepas::enregistrer(){
    qDebug()<<"void preparerRepas::enregistrer()";
    //visualisation des tables:
    for (int cpt=0; cpt < tablesAManger.size(); cpt++)
    {
        tablesAManger[cpt]->enregistrer(repasCourant);;
    }

}

void preparerRepas::placerPersonnes()
{
    qDebug()<<"void preparerRepas::placerPersonnes()";
    // On récupère nos surveillants de l'intérieur
    QMap<int, surveillantModel*> mapSurveillants = surveillantModel::recupererSurveillantsInterieur(repasCourant);
    //combien sont-ils
    int nombreDeTablesAvecSurveillant=mapSurveillants.count();

    //obtention des tables des surveillants
    QVector <tableAManger*> vecteurTablesSurveillees;
    foreach (surveillantModel* leSurveillant,mapSurveillants)
    {
        vecteurTablesSurveillees.push_back(new tableAManger(leSurveillant->getNoTable(repasCourant),repasCourant));
    }

    //distribution des patients à surveiller aux tables des surveillants

    int nombreDePatientsASurveiller=0;
    qDebug()<<"repas courant:"<<repasCourant;

    qDebug()<<"******************************************************************************************";
    // On récupère nos patients à placer
    QMap<int,patientModel*> lesPatientsAPlacer=patientModel::recupererPatientsNonPlaces(repasCourant);
    foreach (patientModel* lePatient, lesPatientsAPlacer)
    {
        qDebug()<<lePatient->getNom()<<" "<<lePatient->getPrenom()<<" "<<lePatient->getIdSurveillance();

        if (lePatient->getIdSurveillance() == 3)
        {

            qDebug()<<" nombreDePatientsASurveiller : "<<nombreDePatientsASurveiller;
            qDebug()<<" nombreDeTablesAvecSurveillant : "<<nombreDeTablesAvecSurveillant;
            //affectation à une des tables du vecteur des tables surveillées
            if(! vecteurTablesSurveillees.empty() && nombreDeTablesAvecSurveillant!=0)
            {
                vecteurTablesSurveillees[nombreDePatientsASurveiller%nombreDeTablesAvecSurveillant]->ajouterPatientSansCompatibilite(lePatient);
                qDebug()<<"ajout a la table surveillée n°"<<nombreDePatientsASurveiller%nombreDeTablesAvecSurveillant;
                //retrait de la map:
                lesPatientsAPlacer.remove(lePatient->getId());
            }
            else
            {
                QMessageBox::critical(this,"Placement des patients",tr("Vous n'avez pas encore désigné de surveillant \n alors que des patients nécessitent \n une surveillance forte."));
            }

            nombreDePatientsASurveiller++;
        }
    }




    // On récupère nos tables de l'intérieur
    QVector <tableAManger*> lesTablesInterieures =tableAManger::recupererTables(tr("Intèrieur"),repasCourant);

    // On place ensuite le reste des patients en les répartissant dans trois groupes en fonction du pain
    QMap<int, patientModel*> patientsRegime;//sans pain
    QMap<int, patientModel*> patientsSurveillance;//un pain
    QMap<int, patientModel*> patientsNormaux;//pain à volonté

    foreach (patientModel* lePatient,lesPatientsAPlacer)
    {

        int typeRegime = lePatient->getIdRegime();
        switch(typeRegime){

            // Régime
        case 1:

            patientsRegime[lePatient->getId()] = lePatient;
            break;

            // Surveillance
        case 2:

            patientsSurveillance[lePatient->getId()] = lePatient;
            break;

            // Normal
        case 3:

            patientsNormaux[lePatient->getId()] = lePatient;
            break;

        }

    }

    // Tant que tous les patients Régime sans pain n'ont pas été placés

    foreach(patientModel* lePatient,patientsRegime)
    {  int cpt=0;
        while (!(cpt==lesTablesInterieures.size()||lesTablesInterieures[cpt]->ajouterPatient(lePatient)))
        {
            cpt++;
        }
        delete lePatient;
    }
    patientsRegime.clear();

    // Tant que tous les patients "1 pain" n'ont pas été placés

    foreach(patientModel* lePatient,patientsSurveillance)
    {  int cpt=0;
        while (!(cpt==lesTablesInterieures.size()||lesTablesInterieures[cpt]->ajouterPatient(lePatient)))
        {

            cpt++;
        }
        delete lePatient;
    }
    patientsSurveillance.clear();

    // Tant que tous les patients pain à volonté n'ont pas été placés

    foreach(patientModel* lePatient,patientsNormaux)
    {  int cpt=0;
        while (!(cpt==lesTablesInterieures.size()||lesTablesInterieures[cpt]->ajouterPatient(lePatient)))
        {

            cpt++;
        }
        delete lePatient;
    }
    patientsNormaux.clear();

    //actualiserLaVue
    ui->comboBoxSalle->setCurrentIndex(ui->comboBoxSalle->findText(tr("Intèrieur")));
    //nettoyage du vecteur des tablesamanger
    foreach(tableAManger* laTable,lesTablesInterieures )
    {
        delete laTable;
    }
    lesTablesInterieures.clear();




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

void preparerRepas::on_pushButtonRAZ_clicked()
{
    qDebug()<<"void preparerRepas::on_pushButtonRAZ_clicked()";
    QSqlQuery raz;
    if(QMessageBox::question(this,tr("Confirmation"),tr("Cela effacera toutes les inscriptions du repas courant\n Etes vous sûr de vouloir effacer ?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No)==QMessageBox::Yes)
    {
        QString texteReq="delete from prendre where idRepas="+QString::number(repasCourant);
        qDebug()<<texteReq;
        raz.exec(texteReq);
        changeRepasCourant();
    }
}

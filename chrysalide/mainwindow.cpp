#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QCloseEvent>
#include <QDebug>
#include "dialogsalleconceptor.h"
#include "arriveepersonne.h"
#include "gerertypestables.h"
#include "sauvegarde.h"
#include "gestionaffinites.h"
#include "rentrertables.h"

MainWindow::MainWindow(QSqlDatabase* pDatabase, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    database = pDatabase;
    //desactivation des menus tant que il n'a pas réussi l'ouverture d'une base ou sa création
    activedesactiveMenusNecessitantOuvertureBase(false);
}
void MainWindow::activedesactiveMenusNecessitantOuvertureBase(bool activation)
{
   ui->actionArriv_e->setEnabled(activation);
   ui->actionD_part->setEnabled(activation);
   ui->actionRentrer_les_Tables->setEnabled(activation);
   ui->action_gestion_des_affinit_s->setEnabled(activation);
   ui->action_Modification_Personne->setEnabled(activation);
   ui->action_Patients->setEnabled(activation);
   ui->action_Repas->setEnabled(activation);
   ui->action_Sauvegarde->setEnabled(activation);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Ouvrir_triggered()
{
    qDebug()<<"void MainWindow::on_action_Ouvrir_triggered()";
    //ouverture de la base sqlite
    QFileDialog dialogOuvertureBase(this);
    dialogOuvertureBase.setFilter("*.db");
  if(dialogOuvertureBase.exec())
    {
      QString fileName=dialogOuvertureBase.selectedFiles().first();
      database->setDatabaseName(fileName);
      if (!database->open())
      {
          QMessageBox::critical(this, windowTitle()+" Erreur", "Impossible d'ouvrir cette base de données");
      }
      else activedesactiveMenusNecessitantOuvertureBase(true);

  }

}

void MainWindow::on_action_Quitter_triggered()
{
    qDebug()<<"void MainWindow::on_action_Quitter_triggered()";
    //choix de l'option quitter du menu
  close();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    //demande de fermeture de la part de l'utilisateur
    qDebug()<<"void MainWindow::onCloseEvent(QCloseEvent* event)";
    if (QMessageBox::warning(this,this->windowTitle()+" Quitter?","Etes-vous sûr de vouloir quitter l'application?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No)==QMessageBox::Yes)
    {
        event->accept();
    }
    else
        event->ignore();
}

void MainWindow::on_actionArriv_e_triggered()
{
   qDebug()<<"void MainWindow::on_actionArriv_e_triggered()";
   //arrivée d'une personne concernée par l'application
   arriveePersonne* dialogArriveePersonne=new arriveePersonne(this);
   dialogArriveePersonne->exec();
}

void MainWindow::on_actionD_part_triggered()
{
    qDebug("void MainWindow::on_actionD_part_triggered()");
    //départ d'une personne quelle qu'elle soit
}

void MainWindow::on_actionRentrer_les_Tables_triggered()
{
    qDebug()<<"void MainWindow::on_actionRentrer_les_Tables_triggered()";
    //configuration initiale on rentre les tables constituant la salle de restauration
    DialogSalleConceptor* dsc=new DialogSalleConceptor(this);
    dsc->exec();
    delete dsc;
}

void MainWindow::on_action_Nouveau_triggered()
{
        qDebug()<<"void MainWindow::on_action_Nouveau_triggered()";
        //nouvelle base de donnée
        //création de la base et exécution du script sql de création des tables sans jeu d'essais
}

void MainWindow::on_action_Pr_paration_des_tables_triggered()
{
        qDebug()<<"void MainWindow::on_action_Pr_paration_des_tables_triggered()";
        //le gros du taf: oraganisation du repas
        //ici on cree les repas midi et soir et on place les gens à leurs tables

}

void MainWindow::on_action_gestion_des_affinit_s_triggered()
{
        qDebug()<<"void MainWindow::on_action_gestion_des_affinit_s_triggered()";
        //gestion des incidents et des affinités entre patients
        gestionAffinites* fenGestAffinite=new gestionAffinites(this);
        fenGestAffinite->exec();
}

void MainWindow::on_action_Propos_triggered()
{
        qDebug()<<"void MainWindow::on_action_Propos_triggered()";
        //là on donne des infos sur les auteurs
}

void MainWindow::on_action_Manuel_triggered()
{
        qDebug()<<"void MainWindow::on_action_Manuel_triggered()";
        //activation du manuel de l'utilisateur
}

void MainWindow::on_action_Sauvegarde_triggered()
{
    qDebug()<<"void MainWindow::on_action_Sauvegarde_triggered()";
    //sauvegarde de la base sur un support amovible
    sauvegarde * leDialogPourSauvegarder = new sauvegarde(this);
    leDialogPourSauvegarder->setWindowTitle(windowTitle()+" sauvegarde");
    leDialogPourSauvegarder->exec();
}

void MainWindow::on_action_Salles_typeTable_triggered()
{
    gererTypesTables * fenGestionDesTypes=new gererTypesTables(this);
    fenGestionDesTypes->exec();
}

void MainWindow::on_actionRentrerBis_triggered()
{
    rentrerTables* fenRentrerTables= rentrerTables::getInstance();
    fenRentrerTables->exec();
}

#include "sauvegarde.h"
#include "ui_sauvegarde.h"
#include "mainwindow.h"
 #include <QDateTime>
#include <QDebug>
sauvegarde::sauvegarde(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::sauvegarde)
{
    m_ui->setupUi(this);
}

sauvegarde::~sauvegarde()
{
    delete m_ui;
}

void sauvegarde::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void sauvegarde::on_pushButtonParcourir_clicked()
{
    /*Ouverture d'une fenêtre qui ne montre que les dossiers*/
    QString dossier = QFileDialog::getExistingDirectory(this);
    /*Si un dossier a été choisi*/
    if(!dossier.isEmpty())
    m_ui->lineEditChemin->setText(dossier);
}

void sauvegarde::on_pushButtonSauvegarder_clicked()
{
     QDateTime maintenant=QDateTime::currentDateTime();
     QString date = maintenant.toString( "_dd_MM_yyyy_hh_mm" );
     QString baseASauver=((MainWindow *)parent())->getDatabase()->databaseName();
     QFile baseActuelle(baseASauver);
     baseActuelle.copy("chrysalide"+date+".db");
     //on avertit l'utilisateur que la sauvegarde c'est bien passé
     m_ui->label_Etat->setText("Sauvegarde effectuée");
     m_ui->pushButtonSauvegarder->setDisabled(true);
}

void sauvegarde::on_pushButtonFermer_clicked()
{
    close();
}

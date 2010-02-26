#include "sauvegarde.h"
#include "ui_sauvegarde.h"

sauvegarde::sauvegarde(QWidget *parent) :
    QWidget(parent),
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
    m_ui->lineEditChemin->setText(dossier);
}

void sauvegarde::on_pushButtonSauvegarder_clicked()
{
     QDateTime maQDateTime;
     QString date = maQDateTime.toString( "dd/MM/yyyy hh:mm" );

     qDebug(date.toStdString().c_str());
}

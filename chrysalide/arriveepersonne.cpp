#include "arriveepersonne.h"
#include "ui_arriveepersonne.h"
#include <QSqlQuery>

arriveePersonne::arriveePersonne(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::arriveePersonne)
{
    m_ui->setupUi(this);
}

arriveePersonne::~arriveePersonne()
{
    delete m_ui;
}

void arriveePersonne::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void arriveePersonne::on_pushButton_continuer_clicked()
{
    //créer une instance du dialog d'elsa
    if (m_ui->comboBox_rang->itemText(m_ui->comboBox_rang->currentIndex()) == "Cuisinier")
    {
        QSqlQuery requete ("select MAX(id) from personne");

        requete.first();
        QSqlQuery req ("insert into personne values (:id,:nom,:prenom)");
        req.bindValue(":id", requete.value(0).toInt()+1, QSql::In);
        req.bindValue(":nom", m_ui->lineEdit_nomPersonne->text(), QSql::In);
        req.bindValue(":prenom", m_ui->lineEdit_prenomPersonne->text(), QSql::In);
        req.exec();

    }
}

void arriveePersonne::on_pushButton_annuler_clicked()
{
    this->close();
}

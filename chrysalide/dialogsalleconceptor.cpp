#include "dialogsalleconceptor.h"
#include "ui_dialogsalleconceptor.h"
#include <QDebug>
#include <QInputDialog>

DialogSalleConceptor::DialogSalleConceptor(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::DialogSalleConceptor)
{
    m_ui->setupUi(this);   
    //toute QGraphics View doit avoir une scene donc on la crée
    m_ui->salleViewCourante->setScene(new QGraphicsScene(this));
    m_ui->salleViewCourante->addAction(m_ui->actionSupprimerTable);
    remplirLaVue();

}

DialogSalleConceptor::~DialogSalleConceptor()
{
    delete m_ui;
}



void DialogSalleConceptor::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DialogSalleConceptor::remplirLaVue()
{
    qDebug()<<"void DialogSalleConceptor::remplirComboTypeDeTable()";
    m_ui->salleViewCourante->setTypeTable(typeTable::recupererTypeTableInterieur()->getNumero(),false);

}











void DialogSalleConceptor::on_actionSupprimerTable_triggered()
{
    qDebug()<<"void DialogSalleConceptor::on_actionSupprimerTable_triggered()";
    m_ui->salleViewCourante->supprimeTablesSelectionnees();
}

void DialogSalleConceptor::on_pushButtonQuitter_clicked()
{
    qDebug()<<"void DialogSalleConceptor::on_pushButtonQuitter_clicked()";
    close();
}

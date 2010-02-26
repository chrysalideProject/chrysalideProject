#include "dialogsalleconceptor.h"
#include "ui_dialogsalleconceptor.h"
#include <QDebug>
#include <QInputDialog>

DialogSalleConceptor::DialogSalleConceptor(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogSalleConceptor)
{
    m_ui->setupUi(this);
    remplirComboTypeDeTable();
    //toute QGraphics View doit avoir une scene donc on la crée
    m_ui->salleViewCourante->setScene(new QGraphicsScene(this));
    m_ui->salleViewCourante->addAction(m_ui->actionSupprimerTable);
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

void DialogSalleConceptor::remplirComboTypeDeTable()
{
    qDebug()<<"void DialogSalleConceptor::remplirComboTypeDeTable()";
    //vidons la combo
    m_ui->comboBoxSalle->clear();
    //ajout des types de tables de la base de données dans le vecteur
     vectTypesTable=typeTable::recupererTypesTables();
     //on remplit la combo de choix de la salle/typeDeTable
    foreach(typeTable* tT,vectTypesTable)
    {
        m_ui->comboBoxSalle->insertItem(0,tT->getLibelle(),(qlonglong)tT);
    }
    //on raffrachit la vue du typeTable Courant
    emit(on_comboBoxSalle_currentIndexChanged(m_ui->comboBoxSalle->currentIndex()));
}
typeTable* DialogSalleConceptor::typeTableCourant()
{
    qDebug()<<"typeTable* DialogSalleConceptor::typeTableCourant()";
    return (typeTable*) m_ui->comboBoxSalle->itemData(m_ui->comboBoxSalle->currentIndex()).toLongLong();
}



void DialogSalleConceptor::on_comboBoxSalle_currentIndexChanged(int index)
{
    qDebug()<<"void DialogSalleConceptor::on_comboBoxSalle_currentIndexChanged(int index)";
    //si il y a un type dans la combo
    if(index!=-1)
    {
       //on fait correspondre la vue avec son modele
        m_ui->salleViewCourante->setTypeTable(typeTableCourant()->getNumero());
   }
}

void DialogSalleConceptor::on_pushButtonNewSalle_clicked()
{
    qDebug()<<"void DialogSalleConceptor::on_pushButtonNewSalle_clicked()";
    bool ok;
    QString nouveauType = QInputDialog::getText(0, QObject::tr("Nouveau type"),QObject::tr("Nom:"), QLineEdit::Normal,"", &ok);
    if (ok && !nouveauType.isEmpty())
    {
        //on crée le nouveau type
        typeTable* newType=new typeTable(nouveauType);
        //raffraichissement de la combo:
        remplirComboTypeDeTable();
        //selection du type Qui vient d'être créé
        m_ui->comboBoxSalle->setCurrentIndex(m_ui->comboBoxSalle->findText(newType->getLibelle()));
    }

}



void DialogSalleConceptor::on_pushButtonSauver_clicked()
{
    qDebug()<<"void DialogSalleConceptor::on_pushButtonSauver_clicked()";
    m_ui->salleViewCourante->enregistrePositions();
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

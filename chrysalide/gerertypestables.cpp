#include "gerertypestables.h"
#include "ui_gerertypestables.h"

gererTypesTables* gererTypesTables::instance = NULL;

gererTypesTables::gererTypesTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gererTypesTables)
{
    ui->setupUi(this);

    ui->typeTableView->hide();
    typesTables = typeTable::recupererTypesTables();

    ui->listeTypesTables->clear();

    for(long cpt=0; cpt < typesTables.size(); cpt++){
        ui->listeTypesTables->addItem(typesTables[cpt]->getLibelle());
    }
}

gererTypesTables::~gererTypesTables()
{
    delete ui;
}

gererTypesTables* gererTypesTables::getInstance(){

    if (gererTypesTables::instance == NULL){
        gererTypesTables::instance = new gererTypesTables;
    }

    return gererTypesTables::instance;

}

void gererTypesTables::changeEvent(QEvent *e)
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

void gererTypesTables::on_nouveauTypeTableButton_clicked()
{
    typesTables.push_back(new typeTable("nouveau type"));
    ui->listeTypesTables->addItem(typesTables.last()->getLibelle());
}

void gererTypesTables::on_supprimerButton_clicked()
{
    typesTables.remove(ui->listeTypesTables->currentRow());
    ui->listeTypesTables->takeItem(ui->listeTypesTables->currentRow());
    ui->listeTypesTables->setCurrentRow(0);
}

void gererTypesTables::on_listeTypesTables_currentRowChanged(int currentRow)
{
    if (currentRow >= 0){
        ui->numeroLabel->setText(QString::number(typesTables[currentRow]->getNumero()));
        ui->libelleLineEdit->setText(typesTables[currentRow]->getLibelle());
        ui->typeTableView->show();
    }
}

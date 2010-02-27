#include "gerertypestables.h"
#include "ui_gerertypestables.h"
#include <QDebug>



gererTypesTables::gererTypesTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gererTypesTables)
{
    ui->setupUi(this);

    ui->typeTableView->hide();
    updateView();
}

gererTypesTables::~gererTypesTables()
{
    delete ui;
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
    typeTable* nouveauTypeTable=new typeTable("Nouveau Type");
    updateView();
}

void gererTypesTables::on_supprimerButton_clicked()
{
    typesTables[ui->listeTypesTables->currentRow()]->supprimer();
    updateView();
}

void gererTypesTables::on_listeTypesTables_currentRowChanged(int currentRow)
{
    if (currentRow >= 0){
        ui->numeroLabel->setText(QString::number(typesTables[currentRow]->getNumero()));
        ui->libelleLineEdit->setText(typesTables[currentRow]->getLibelle());
        ui->typeTableView->show();
        if (typesTables[currentRow]->isUsedByATable()) ui->supprimerButton->setDisabled(true);
        else ui->supprimerButton->setEnabled(true);
    }
}

void gererTypesTables::updateView(){

    ui->listeTypesTables->clear();
    ui->libelleLineEdit->clear();
    ui->numeroLabel->clear();
    ui->supprimerButton->setDisabled(true);

    typesTables = typeTable::recupererTypesTables();

    for (long cpt=0; cpt < typesTables.size(); cpt++){
        ui->listeTypesTables->addItem(typesTables.at(cpt)->getLibelle());
    }

    ui->listeTypesTables->setCurrentRow(0);

}

void gererTypesTables::on_appliquerPushButton_clicked()
{
    typesTables[ui->listeTypesTables->currentRow()]->setLibelle(ui->libelleLineEdit->text());
    typesTables[ui->listeTypesTables->currentRow()]->save();
    updateView();
}

void gererTypesTables::on_libelleLineEdit_textEdited(QString value)
{
    if (value.isEmpty()) ui->appliquerPushButton->setDisabled(true);
    else ui->appliquerPushButton->setEnabled(true);
}

void gererTypesTables::on_pushButtonQuitter_clicked()
{
    close();
}

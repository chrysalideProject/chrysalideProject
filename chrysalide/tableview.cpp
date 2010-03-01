#include "tableview.h"
#include "ui_tableview.h"
#include <QDebug>

tableView::tableView(tableAManger* newModel, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableView)
{
    ui->setupUi(this);

    ui->appliquerPushButton->setDisabled(true);

    connect(this, SIGNAL(modelChanged()), this, SLOT(updateFields()));

    setModel(newModel);

    connect(ui->capaciteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(showThatItHasBeenModified()));
    connect(ui->typeComboBox, SIGNAL(activated(int)), this, SLOT(showThatItHasBeenModified()));
}

void tableView::setModel(tableAManger* newModel){
    leModel = newModel;
    emit modelChanged();
}

void tableView::updateFields(){

    ui->groupBox->setTitle(QString::fromUtf8("Table N° ")+QString::number(leModel->getNumero()));
    ui->capaciteSpinBox->setValue(leModel->getCapacite());

    QVector<typeTable*> listeTypes = typeTable::recupererTypesTables();

    for(long cpt=0; cpt < listeTypes.size(); cpt++){
        ui->typeComboBox->addItem(listeTypes[cpt]->getLibelle());
        ui->typeComboBox->setItemData(cpt, listeTypes[cpt]->getNumero());
    }
    ui->typeComboBox->addItem("Autre...");
    ui->typeComboBox->setItemData(ui->typeComboBox->count()-1, -1);

    ui->typeComboBox->setCurrentIndex(ui->typeComboBox->findData(leModel->getType()->getNumero()));

}

void tableView::showThatItHasBeenModified(){

    bool hasBeenModified = (ui->capaciteSpinBox->value() != leModel->getCapacite()) + (ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toInt() != leModel->getType()->getNumero());

    if (hasBeenModified){
        setStyleSheet("background-color: rgb(180, 180, 180)");
        ui->appliquerPushButton->setEnabled(true);
    }

    else{
        setStyleSheet("background-color: rgb(100, 172, 49)");
        ui->appliquerPushButton->setDisabled(true);
    }

}

tableView::~tableView()
{
    delete ui;
}

void tableView::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void tableView::on_supprimerPushButton_clicked()
{
    leModel->supprimer();
}

void tableView::on_appliquerPushButton_clicked()
{
    leModel->setCapacite(ui->capaciteSpinBox->value());
    leModel->setTypeTable(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toInt());
    leModel->save();
    showThatItHasBeenModified();
}

void tableView::on_typeComboBox_activated(int index)
{
    if (ui->typeComboBox->itemData(index).toInt() == -1){

        // Ouverture de la dialog pour gérer les types de tables
        gererTypesTables::getInstance()->show();
        ui->typeComboBox->setCurrentIndex(0);

    }
}

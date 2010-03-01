#include "rentrertables.h"
#include "ui_rentrertables.h"
#include <QComboBox>
#include <QDebug>

rentrerTables* rentrerTables::instance = NULL;

rentrerTables::rentrerTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentrerTables)
{
    ui->setupUi(this);
    zoneTables = new QWidget;
    zoneTables->setGeometry(10, 100, 531, 100);
    connect(gererTypesTables::getInstance(), SIGNAL(closed()), this, SLOT(updateView()));
}

rentrerTables* rentrerTables::getInstance(){

    if (rentrerTables::instance == NULL){
        rentrerTables::instance = new rentrerTables;
    }

    rentrerTables::instance->updateView();
    return rentrerTables::instance;

}


void rentrerTables::updateView(){

    tables = tableAManger::recupererTables();

    if (typeTable::recupererTypesTables().size() > 0) {
        ui->ajouterTableButton->setEnabled(true);
        ui->msgErreur->hide();
    }
    else {
        ui->ajouterTableButton->setEnabled(false);
        ui->msgErreur->show();
        ui->msgErreur->setText(QString::fromUtf8("Vous devez avoir créé au moins un type de table avant de pouvoir ajouter des tables"));
        ui->msgErreur->adjustSize();
    }

    for (long cpt=0; cpt < tables.size(); cpt++){
        connect(tables[cpt], SIGNAL(tableSupprimee()), this, SLOT(updateView()));
    }

    ui->nbTables->setText(QString::number(tables.size()));

    for (long cpt=0; cpt < vuesTables.size(); cpt++){
        delete vuesTables[cpt];
    }
    vuesTables.clear();
    ui->scrollArea->setWidget(zoneTables);

    zoneTables->resize(535, tables.size()*153);

    for (long cpt=0; cpt < tables.size(); cpt++){
        vuesTables.push_back(new tableView(tables[cpt], zoneTables));
        vuesTables[cpt]->show();
        if (cpt > 0) vuesTables[cpt]->setGeometry(cpt%3*180, (int)cpt/3*155, 177, 153);
    }

}


rentrerTables::~rentrerTables()
{
    delete ui;
}

void rentrerTables::changeEvent(QEvent *e)
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

void rentrerTables::on_ajouterTableButton_clicked()
{
    tableAManger::nouvelleTable();
    updateView();
}

void rentrerTables::on_gererTypesTablesButton_clicked()
{
    gererTypesTables::getInstance()->show();
}

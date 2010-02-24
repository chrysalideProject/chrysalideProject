#include "gestiontable.h"
#include "ui_gestiontable.h"

gestionTable::gestionTable(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::gestionTable)
{
    m_ui->setupUi(this);
}

gestionTable::~gestionTable()
{
    delete m_ui;
}

void gestionTable::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

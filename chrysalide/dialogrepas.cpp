#include "dialogrepas.h"
#include "ui_dialogrepas.h"

DialogRepas::DialogRepas(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogRepas)
{
    m_ui->setupUi(this);
}

DialogRepas::~DialogRepas()
{
    delete m_ui;
}

void DialogRepas::changeEvent(QEvent *e)
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

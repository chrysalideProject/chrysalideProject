#ifndef ARRIVWIZARDPAGESURVEILLANT_H
#define ARRIVWIZARDPAGESURVEILLANT_H
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QWizardPage>
#include <QLabel>
#include    <QLineEdit>
#include   <QComboBox>
#include "arriveewizard.h"

class arrivWizardPageSurveillant : public QWizardPage
{
public:
    arrivWizardPageSurveillant();
    QComboBox * comboBoxPoste;
    QLabel * labelPoste;
    int nextId() const{return arriveeWizard::PageRecapitulatif;};
};

#endif // ARRIVWIZARDPAGESURVEILLANT_H

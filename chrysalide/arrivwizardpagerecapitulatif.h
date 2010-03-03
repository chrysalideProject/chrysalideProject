#ifndef ARRIVWIZARDPAGERECAPITULATIF_H
#define ARRIVWIZARDPAGERECAPITULATIF_H

#include <QWizardPage>

#include <QLabel>
#include    <QLineEdit>
#include   <QComboBox>
#include "arriveewizard.h"
class arrivWizardPageRecapitulatif: public QWizardPage
{
public:
    arrivWizardPageRecapitulatif();
    void initializePage();
    QLabel* labelTypePersonne;
    QLabel * labelNom;
    QLabel * labelPrenom;
    QLabel * labelRegime;
    QLabel * labelSurveillance;
    QLabel* labelTravail;
    QLabel * labelPoste;
    QLabel * labelFonction;

};

#endif // ARRIVWIZARDPAGERECAPITULATIF_H

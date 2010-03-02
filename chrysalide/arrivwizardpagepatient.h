#ifndef ARRIVWIZARDPAGEPATIENT_H
#define ARRIVWIZARDPAGEPATIENT_H

#include <QWizardPage>
#include <QLabel>
#include    <QLineEdit>
#include   <QComboBox>
#include "arriveewizard.h"
class arrivWizardPagePatient : public QWizardPage
{
public:
    arrivWizardPagePatient();
    QComboBox* comboBoxRegime;
    QComboBox* comboBoxSurveillance;
    QComboBox* comboBoxTravail;
     QLabel * labelRegime;
     QLabel * labelSurveillance;
     QLabel* labelTravail;
     int nextId() const;

};

#endif // ARRIVWIZARDPAGEPATIENT_H

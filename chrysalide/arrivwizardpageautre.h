#ifndef ARRIVWIZARDPAGEAUTRE_H
#define ARRIVWIZARDPAGEAUTRE_H

#include <QWizardPage>
#include <QLabel>
#include    <QLineEdit>
#include   <QComboBox>
#include "arriveewizard.h"
class arrivWizardPageAutre : public QWizardPage
{
public:
    arrivWizardPageAutre();
    QLineEdit* lineEditFonction;
     QLabel * labelFonction;
     int nextId() const{return -1;};

};

#endif // ARRIVWIZARDPAGEAUTRE_H

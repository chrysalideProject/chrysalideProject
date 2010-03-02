#ifndef ARRIVWIZARDPAGEPERSONNE_H
#define ARRIVWIZARDPAGEPERSONNE_H

#include <QWizardPage>
#include <QLabel>
 #include    <QLineEdit>
  #include   <QComboBox>
#include "arriveewizard.h"

class arrivWizardPagePersonne : public QWizardPage
{
public:
    arrivWizardPagePersonne();
    QLabel * labelNom;
     QLabel * labelPrenom;
     QLabel* labelType;
     QLineEdit * lineEditNom;
     QLineEdit * lineEditPrenom;
     QComboBox * comboBoxType;
     int nextId() const;
};

#endif // ARRIVWIZARDPAGEPERSONNE_H

#ifndef ARRIVWIZARDPAGEPERSONNE_H
#define ARRIVWIZARDPAGEPERSONNE_H

#include <QWizardPage>
#include <QLabel>
 #include    <QLineEdit>
  #include   <QComboBox>

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
};

#endif // ARRIVWIZARDPAGEPERSONNE_H

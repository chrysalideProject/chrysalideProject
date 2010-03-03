#include "arrivwizardpagepersonne.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
arrivWizardPagePersonne::arrivWizardPagePersonne()
{
     setTitle("Arrivée");
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);
     QHBoxLayout * layoutNom = new QHBoxLayout;
     layoutVerticale->addLayout(layoutNom);
     labelNom = new QLabel(tr("&Nom:"),this);
     layoutNom->addWidget(labelNom);
     lineEditNom = new QLineEdit(this);
     labelNom->setBuddy(lineEditNom);
     layoutNom->addWidget(lineEditNom);
     QHBoxLayout * layoutPrenom = new QHBoxLayout;
     layoutVerticale->addLayout(layoutPrenom);
     labelPrenom = new QLabel(tr("&Prénom:"),this);
     layoutPrenom->addWidget(labelPrenom);
     lineEditPrenom = new QLineEdit(this);
     layoutPrenom->addWidget(lineEditPrenom);
     labelPrenom->setBuddy(lineEditPrenom);
     QHBoxLayout * layoutType = new QHBoxLayout;
     layoutVerticale->addLayout(layoutType);
     labelType=new QLabel(tr("&Type"),this);

     layoutType->addWidget(labelType);
     comboBoxType = new QComboBox(this);
     labelType->setBuddy(comboBoxType);
     comboBoxType->addItem("Choisissez");
     comboBoxType->addItem("Patient");
     comboBoxType->addItem("Surveillant");
     comboBoxType->addItem("Cuisinier");
     comboBoxType->addItem("Autre");
     layoutType->addWidget(comboBoxType);

     registerField("nom*", lineEditNom);
     registerField("prenom*",lineEditPrenom);
     registerField("type*", comboBoxType);
}
int arrivWizardPagePersonne::nextId() const
{
    if (comboBoxType->currentText()=="Patient" )
    {
        return arriveeWizard::PagePatient;
    }
    else
    {
        if(comboBoxType->currentText()=="Surveillant")
            return arriveeWizard::PageSurveillant;
        else
        {
            if(comboBoxType->currentText()=="Cuisinier")
                return arriveeWizard::PageRecapitulatif;
            else
            {
                return arriveeWizard::PageAutre;
            }
        }
    }
 }


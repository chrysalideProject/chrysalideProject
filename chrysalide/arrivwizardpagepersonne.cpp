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
     labelNom = new QLabel("&Nom:");
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
     labelType=new QLabel("&Type");
     layoutType->addWidget(labelType);
     comboBoxType = new QComboBox(this);
     comboBoxType->addItem("Patient");
     comboBoxType->addItem("Surveillant");
     comboBoxType->addItem("Cuisinier");
     comboBoxType->addItem("Autre");
     layoutType->addWidget(comboBoxType);

     registerField("nom*", lineEditNom);
     registerField("prenom*",lineEditPrenom);
     registerField("type*", comboBoxType);
}

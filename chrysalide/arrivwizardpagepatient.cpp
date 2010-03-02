#include "arrivwizardpagepatient.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlQuery>

arrivWizardPagePatient::arrivWizardPagePatient()
{
    setTitle("Arrivée d'un patient");
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);
     QHBoxLayout * layoutRegime = new QHBoxLayout;
     layoutVerticale->addLayout(layoutRegime);
     labelRegime = new QLabel(tr("&Regime:"),this);
     layoutRegime->addWidget(labelRegime);
     comboBoxRegime = new QComboBox(this);
     comboBoxRegime->addItem("Choisissez");
     QSqlQuery req0("select libelle from regime");
     while (req0.next())
     {
         comboBoxRegime->addItem(req0.value(0).toString());
     }


     labelRegime->setBuddy(comboBoxRegime);
     layoutRegime->addWidget(comboBoxRegime);
     QHBoxLayout * layoutSurveillance = new QHBoxLayout;
     layoutVerticale->addLayout(layoutSurveillance);
     labelSurveillance = new QLabel(tr("&Surveillance:"),this);
     layoutSurveillance->addWidget(labelSurveillance);
     comboBoxSurveillance = new QComboBox(this);

     comboBoxSurveillance->addItem("Choisissez");
     QSqlQuery req1("select libelle from surveillance");
     while (req1.next())
     {
         comboBoxSurveillance->addItem(req1.value(0).toString());
     }


     layoutSurveillance->addWidget(comboBoxSurveillance);
     labelSurveillance->setBuddy(comboBoxSurveillance);
     QHBoxLayout * layoutTravail = new QHBoxLayout;
     layoutVerticale->addLayout(layoutTravail);
     labelTravail=new QLabel(tr("&Travail"),this);

     layoutTravail->addWidget(labelTravail);
     comboBoxTravail= new QComboBox(this);
     labelTravail->setBuddy(comboBoxTravail);
     comboBoxTravail->addItem("Choisissez");
     //boucle de création des item
     QSqlQuery req("select libelle from travail");
     while (req.next())
     {
         comboBoxTravail->addItem(req.value(0).toString());
     }
     comboBoxTravail->addItem("Aucun");

     layoutTravail->addWidget(comboBoxTravail);

     registerField("regime*", comboBoxRegime);
     registerField("surveillance*",comboBoxSurveillance);
     registerField("travail*", comboBoxTravail);
}
int arrivWizardPagePatient::nextId() const
{
    return(arriveeWizard::PageConclusion);
}


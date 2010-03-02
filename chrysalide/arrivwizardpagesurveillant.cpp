#include "arrivwizardpagesurveillant.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

arrivWizardPageSurveillant::arrivWizardPageSurveillant()
{

setTitle(tr("Arrivée d'un Surveillant"));
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);
     QHBoxLayout * layoutPoste = new QHBoxLayout;
     layoutVerticale->addLayout(layoutPoste);
     labelPoste = new QLabel(tr("&Poste:"),this);
     layoutPoste->addWidget(labelPoste);
     comboBoxPoste = new QComboBox(this);
     comboBoxPoste->addItem("Choisissez");
     QSqlQuery req0("select libelle from poste");
     while (req0.next())
     {
         comboBoxPoste->addItem(req0.value(0).toString());
     }


     labelPoste->setBuddy(comboBoxPoste);
     layoutPoste->addWidget(comboBoxPoste);

     registerField("poste*", comboBoxPoste);
 }
int arrivWizardPageSurveillant::nextId() const
{
    return(arriveeWizard::PageConclusion);
}

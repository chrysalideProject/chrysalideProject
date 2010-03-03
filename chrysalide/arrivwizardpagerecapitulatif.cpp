#include "arrivwizardpagerecapitulatif.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
arrivWizardPageRecapitulatif::arrivWizardPageRecapitulatif()
{
}
void arrivWizardPageRecapitulatif::initializePage()
{
    setTitle("Récapitulatif");
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);

    labelTypePersonne=new QLabel();
    layoutVerticale->addWidget(labelTypePersonne);
    labelTypePersonne->setText("type:"+wizard()->field("type").toString());
    labelNom=new QLabel();

    labelNom->setText("Nom:"+wizard()->field("nom").toString());
    layoutVerticale->addWidget(labelNom);
    labelPrenom=new QLabel();
    layoutVerticale->addWidget(labelPrenom);
    labelPrenom->setText("Prénom:"+wizard()->field("prenom").toString());

    if(wizard()->hasVisitedPage(arriveeWizard::PageAutre))
    {
        //c'est un autre
        labelFonction=new QLabel();
        layoutVerticale->addWidget(labelFonction);
        labelFonction->setText("fonction:"+wizard()->field("fonction").toString());
    }
    else
    {
        if(wizard()->hasVisitedPage(arriveeWizard::PagePatient))
        {
            //c'est un patient
            labelRegime=new QLabel();
            layoutVerticale->addWidget(labelRegime);
            labelRegime->setText("Régime:"+wizard()->field("regime").toString());
            labelSurveillance=new QLabel();
            layoutVerticale->addWidget(labelSurveillance);
            labelSurveillance->setText("Surveillance:"+wizard()->field("surveillance").toString());
            labelTravail=new QLabel();
            layoutVerticale->addWidget(labelTravail);
            labelTravail->setText("Travail:"+wizard()->field("travail").toString());

        }
        else
        {
            if(wizard()->hasVisitedPage(arriveeWizard::PageSurveillant))
            {
                //c'est un surveillant
                labelPoste=new QLabel();
                layoutVerticale->addWidget(labelPoste);
                labelPoste->setText("Poste:"+wizard()->field("poste").toString());
            }
            else//c'est un cuisinier
            {
                //rien à faire du tout

            }

        }
    }
}

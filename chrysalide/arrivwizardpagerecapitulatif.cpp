#include "arrivwizardpagerecapitulatif.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
arrivWizardPageRecapitulatif::arrivWizardPageRecapitulatif()
{
}
void arrivWizardPageRecapitulatif::initializePage()
{

    delete layout();
    foreach(QObject * enfant,children())
    {
          delete enfant;
    }
    qDebug()<<"void arrivWizardPageRecapitulatif::initializePage()";
    setTitle(tr("Récapitulatif"));
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);

    labelTypePersonne=new QLabel(this);
    layoutVerticale->addWidget(labelTypePersonne);
    labelTypePersonne->setText("type:"+wizard()->field("type").toString());
    labelNom=new QLabel(this);

    labelNom->setText("Nom:"+wizard()->field("nom").toString());
    layoutVerticale->addWidget(labelNom);
    labelPrenom=new QLabel(this);
    layoutVerticale->addWidget(labelPrenom);
    labelPrenom->setText(tr("Prénom:")+wizard()->field("prenom").toString());

    if(wizard()->hasVisitedPage(arriveeWizard::PageAutre))
    {
        //c'est un autre
        labelFonction=new QLabel(this);
        layoutVerticale->addWidget(labelFonction);
        labelFonction->setText("fonction:"+wizard()->field("fonction").toString());
    }
    else
    {
        if(wizard()->hasVisitedPage(arriveeWizard::PagePatient))
        {
            //c'est un patient
            labelRegime=new QLabel(this);
            layoutVerticale->addWidget(labelRegime);
            labelRegime->setText(tr("Régime:")+wizard()->field("regime").toString());
            labelSurveillance=new QLabel(this);
            layoutVerticale->addWidget(labelSurveillance);
            labelSurveillance->setText("Surveillance:"+wizard()->field("surveillance").toString());
            labelTravail=new QLabel(this);
            layoutVerticale->addWidget(labelTravail);
            labelTravail->setText("Travail:"+wizard()->field("travail").toString());

        }
        else
        {
            if(wizard()->hasVisitedPage(arriveeWizard::PageSurveillant))
            {
                //c'est un surveillant
                labelPoste=new QLabel(this);
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

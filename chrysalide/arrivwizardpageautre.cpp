#include "arrivwizardpageautre.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
arrivWizardPageAutre::arrivWizardPageAutre()
{
    setTitle(tr("Arrivée d'un Surveillant"));
     QVBoxLayout *layoutVerticale = new QVBoxLayout(this);
     setLayout(layoutVerticale);
     QHBoxLayout * layoutFonction = new QHBoxLayout;
     layoutVerticale->addLayout(layoutFonction);
     labelFonction= new QLabel(tr("&Fonction:"),this);
     layoutFonction->addWidget(labelFonction);
     lineEditFonction = new QLineEdit(this);

     labelFonction->setBuddy(lineEditFonction);
     layoutFonction->addWidget(lineEditFonction);

     registerField("fonction*", lineEditFonction);
}

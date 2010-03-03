#ifndef ARRIVEEWIZARD_H
#define ARRIVEEWIZARD_H

#include <QWizard>
#include "arrivwizardpagepersonne.h"
class arrivWizardPagePersonne;
class arriveeWizard : public QWizard
{


     private:

     arrivWizardPagePersonne * pagePersonne;
public:
    arriveeWizard(QWidget* parent);
    void enregistre();
    enum { PagePersonne, PagePatient, PageSurveillant,  PageAutre,
            PageRecapitulatif};
};

#endif // ARRIVEEWIZARD_H

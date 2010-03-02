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
    enum { PagePersonne, PagePatient, PageSurveillant, PageCuisinier, PageAutre,
            PageConclusion };
};

#endif // ARRIVEEWIZARD_H

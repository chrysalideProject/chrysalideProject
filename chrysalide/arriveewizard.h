#ifndef ARRIVEEWIZARD_H
#define ARRIVEEWIZARD_H

#include <QWizard>
#include "arrivwizardpagepersonne.h"
class arriveeWizard : public QWizard
{
     enum { PagePersonne, PagePatient, PageCuisinier, PageAutre,
            PageConclusion };
     private:

     arrivWizardPagePersonne * pagePersonne;
public:
    arriveeWizard(QWidget* parent);
};

#endif // ARRIVEEWIZARD_H

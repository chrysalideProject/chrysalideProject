#include "arriveewizard.h"
#include "arrivwizardpagepatient.h"
#include "arrivwizardpagesurveillant.h"


arriveeWizard::arriveeWizard(QWidget* parent):QWizard(parent)
{
    //création des pages

    addPage(new arrivWizardPagePersonne());
    addPage(new arrivWizardPagePatient());
    addPage(new arrivWizardPageSurveillant());
    addPage(new arrivWizardPageCuisinier());
    addPage(new arrivWizardPageAutre());
    addPage(new arrivWizardPageConclusion());

}

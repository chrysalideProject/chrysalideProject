#include "arriveewizard.h"
#include "arrivwizardpagepatient.h"
#include "arrivwizardpagesurveillant.h"
#include "arrivwizardpageautre.h"


arriveeWizard::arriveeWizard(QWidget* parent):QWizard(parent)
{
    //création des pages

    addPage(new arrivWizardPagePersonne());
    addPage(new arrivWizardPagePatient());
    addPage(new arrivWizardPageSurveillant());
    addPage(new arrivWizardPageAutre());


}

#include "arriveewizard.h"


arriveeWizard::arriveeWizard(QWidget* parent):QWizard(parent)
{
    //création des pages

    addPage(new arrivWizardPagePersonne());

}

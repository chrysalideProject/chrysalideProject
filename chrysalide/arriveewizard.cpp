#include "arriveewizard.h"
#include "arrivwizardpagepatient.h"
#include "arrivwizardpagesurveillant.h"
#include "arrivwizardpageautre.h"
#include "arrivwizardpagerecapitulatif.h"
#include "personnemodel.h"


arriveeWizard::arriveeWizard(QWidget* parent):QWizard(parent)
{
    //création des pages
    setWizardStyle(QWizard::ModernStyle);
    setPixmap(QWizard::LogoPixmap,QPixmap(":new/prefix1/tallard"));
    setPixmap(QWizard::WatermarkPixmap,QPixmap(":new/prefix1/chrysalide"));
    addPage(new arrivWizardPagePersonne());
    addPage(new arrivWizardPagePatient());
    addPage(new arrivWizardPageSurveillant());
    addPage(new arrivWizardPageAutre());
    addPage(new arrivWizardPageRecapitulatif());


}
void arriveeWizard::enregistre()
{

    QString nom=field("nom").toString();
    QString prenom=field("prenom").toString();
    int numero=personneModel::insert(nom,prenom);

    if(hasVisitedPage(arriveeWizard::PageAutre))
    {
        QString fonction =field("fonction").toString();
        QSqlQuery reqAutre("insert into autre values("+QString::number(numero)+",'"+fonction+"')");
        reqAutre.exec();

    }
    else
    {
        if(hasVisitedPage(arriveeWizard::PagePatient))
        {
            //c'est un patient
            QString regime=field("regime").toString();
            QString surveillance=field("surveillance").toString();
            QString travail=field("travail").toString();
            QSqlQuery reqPatient("insert into patient values("+QString::number(numero)+","+travail+","+regime+","+surveillance+")");
            reqPatient.exec();

        }
        else
        {
            if(hasVisitedPage(arriveeWizard::PageSurveillant))
            {
                //c'est un surveillant
                QString poste=field("poste").toString();
                QSqlQuery reqSurveillant("insert into surveillant values("+QString::number(numero)+","+poste+")");
                reqSurveillant.exec();
            }
            else//c'est un cuisinier
            {
                //rien à faire du tout
                QSqlQuery reqCuisinier("insert into cuisinier values("+QString::number(numero)+")");
                reqCuisinier.exec();

            }

        }
    }
}

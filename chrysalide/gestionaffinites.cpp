#include "gestionaffinites.h"
#include "ui_gestionaffinites.h"

gestionAffinites::gestionAffinites(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::gestionAffinites)
{
    m_ui->setupUi(this);
    //Rempli la liste des patients
    QSqlQuery recupPatient("SELECT id, nom, prenom FROM PATIENT inner join PERSONNE on PATIENT.idPersonne = PERSONNE.id");
    while(recupPatient.next())
    {
        m_ui->comboBox_patient->addItem(recupPatient.value(1).toString()+" "+recupPatient.value(2).toString());
        nom=recupPatient.value(1).toString();
        prenom=recupPatient.value(2).toString();
        idEnCours=recupPatient.value(0).toString();
    }
    //Sélectionne le premier patient si la liste n'est pas vide
    if(m_ui->comboBox_patient->count()>-1)
    {
        m_ui->comboBox_patient->setCurrentIndex(0);
    }
}

gestionAffinites::~gestionAffinites()
{
    delete m_ui;
}

void gestionAffinites::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void gestionAffinites::on_comboBox_patient_currentIndexChanged(int index)
{
    //Récupère l'id du patient sélectionné
    QString LId;
    QString patient = m_ui->comboBox_patient->currentText();
    QStringList lePatient = patient.split(' ');
    QSqlQuery patientSelect("SELECT id FROM PERSONNE WHERE nom = "+lePatient[0]+" AND prenom="+lePatient[1]);
    while(patientSelect.next())
    {
        LId=patientSelect.value(0).toString();
    }
    //Récupère les affinités
    QSqlQuery recupAffinites("SELECT * FROM AFFINITE;");
    while(recupAffinites.next())
    {
        //Parcours les résultats
        if(recupAffinites.value(0).toString()==idEnCours)
        {
            //Récupère les noms et prénoms des affinités
            QSqlQuery recupNomPrenom("SELECT nom, prenom FROM PERSONNE WHERE id = "+LId);
            while(recupNomPrenom.next())
            {
                QString listeAffinites = recupNomPrenom.value(0).toString()+" "+recupNomPrenom.value(1).toString();
                m_ui->listWidget_affinite->addItem(listeAffinites);
            }
        }
    }

    //Récupère les incompatibilités
    //Remplis la liste concerné
}

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

        m_ui->comboBox_patient->addItem(recupPatient.value(1).toString()+" "+recupPatient.value(2).toString(),recupPatient.value(0).toString());
        /*nom=recupPatient.value(1).toString();
        prenom=recupPatient.value(2).toString();
        idEnCours=recupPatient.value(0).toString();*/
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
    qDebug()<<"void gestionAffinites::on_comboBox_patient_currentIndexChanged(int index)";
    QString patient = m_ui->comboBox_patient->currentText();
    QString LId=m_ui->comboBox_patient->itemData(m_ui->comboBox_patient->currentIndex()).toString();
    m_ui->listWidget_affinite->clear();
    m_ui->listWidget_incompatibilite->clear();

    //Récupère les affinités
    QString textReqA="SELECT * FROM AFFINITE where idPersonne1="+LId+ " or idPersonne2="+LId;
    qDebug()<<textReqA;
    QSqlQuery recupAffinites(textReqA);
    while(recupAffinites.next())
    {
        //Parcours les résultats
        QString idDuCopain;
        if(recupAffinites.value(0).toString()!=LId)


             idDuCopain=recupAffinites.value(0).toString();
            else
                idDuCopain=recupAffinites.value(1).toString();
            //Récupère les noms et prénoms des affinités
            QSqlQuery recupNomPrenom("SELECT nom, prenom FROM PERSONNE WHERE id = "+idDuCopain);
            recupNomPrenom.first();

                QString nomPrenomDuCopain = recupNomPrenom.value(0).toString()+" "+recupNomPrenom.value(1).toString();
                QListWidgetItem* listWidgetCopain=new QListWidgetItem();
                listWidgetCopain->setData(32,idDuCopain);
                listWidgetCopain->setText(nomPrenomDuCopain);
                m_ui->listWidget_affinite->addItem(listWidgetCopain);


    }

    //Récupère les incompatibilités
    QSqlQuery recupIncompatibiles("SELECT * FROM INCOMPATIBILITE where idPersonne1="+LId+ " or idPersonne2="+LId);
    while(recupIncompatibiles.next())
    {
        //Parcours les résultats
        QString idDuPasCopain;
        if(recupIncompatibiles.value(0).toString()!=LId)


             idDuPasCopain=recupIncompatibiles.value(0).toString();
            else
                idDuPasCopain=recupIncompatibiles.value(1).toString();
            //Récupère les noms et prénoms des affinités
            QSqlQuery recupNomPrenom("SELECT nom, prenom FROM PERSONNE WHERE id = "+idDuPasCopain);
            recupNomPrenom.first();

                QString nomPrenomDuPasCopain = recupNomPrenom.value(0).toString()+" "+recupNomPrenom.value(1).toString();
                QListWidgetItem* listWidgetPasCopain=new QListWidgetItem();
                listWidgetPasCopain->setData(32,idDuPasCopain);
                listWidgetPasCopain->setText(nomPrenomDuPasCopain);
                m_ui->listWidget_incompatibilite->addItem(listWidgetPasCopain);


    }
    //Remplit la combobox des autres patients ceux qui ne sont ni incompatibles ni copains
    m_ui->comboBox_listePatient->clear();
    QString textReq="SELECT id,nom,prenom from PATIENT inner join PERSONNE on Personne.id=PATIENT.idPersonne  where id<>"+LId;
    qDebug()<<textReq;
    QSqlQuery reqTousPatients(textReq);
    while(reqTousPatients.next())
    {
        //si ni ds l'un ni ds l'autre alors insertion dans la combo
        QString nomPrenom=reqTousPatients.value(1).toString()+" "+reqTousPatients.value(2).toString();
        if((m_ui->listWidget_affinite->findItems(nomPrenom,Qt::MatchExactly).empty()&&(m_ui->listWidget_incompatibilite->findItems(nomPrenom,Qt::MatchExactly).empty())))
        {
            //ajout
            m_ui->comboBox_listePatient->addItem(nomPrenom,reqTousPatients.value(0).toString());
        }
    }
}

void gestionAffinites::on_pushButtonFermer_clicked()
{
    close();
}

void gestionAffinites::on_pushButton_suppAffinite_clicked()
{
    //quelle affinité est à supprimer?
    QListWidgetItem * copain=m_ui->listWidget_affinite->selectedItems()[0];
    QString numeroCopain=copain->data(32).toString();
    QString LId=m_ui->comboBox_patient->itemData(m_ui->comboBox_patient->currentIndex()).toString();
    QString texteRequete="delete from affinite where (idPersonne1="+LId+" and idPersonne2="+numeroCopain+") or (idPersonne1="+numeroCopain+" and idPersonne2="+LId+")";
    QSqlQuery req(texteRequete);
    req.exec();
    //raffraichissement
    on_comboBox_patient_currentIndexChanged(m_ui->comboBox_patient->currentIndex());

}

void gestionAffinites::on_pushButton_supprIncompatibilite_clicked()
{
    //quelle incompatibilite est à supprimer?
    QListWidgetItem * pasCopain=m_ui->listWidget_incompatibilite->selectedItems()[0];
    QString numeroPasCopain=pasCopain->data(32).toString();
    QString LId=m_ui->comboBox_patient->itemData(m_ui->comboBox_patient->currentIndex()).toString();
    QString texteRequete="delete from incompatibilite where (idPersonne1="+LId+" and idPersonne2="+numeroPasCopain+") or (idPersonne1="+numeroPasCopain+" and idPersonne2="+LId+")";
    QSqlQuery req(texteRequete);
    req.exec();
    //raffraichissement
    on_comboBox_patient_currentIndexChanged(m_ui->comboBox_patient->currentIndex());

}

void gestionAffinites::on_pushButton_ajoutAffinite_clicked()
{
    QString LId=m_ui->comboBox_patient->itemData(m_ui->comboBox_patient->currentIndex()).toString();
    QString numeroDeLautre=m_ui->comboBox_listePatient->itemData(m_ui->comboBox_listePatient->currentIndex()).toString();
    QString texteRequete="insert into AFFINITE values("+LId+","+numeroDeLautre+")";
    qDebug()<<texteRequete;
    QSqlQuery req(texteRequete);
    req.exec();
    //raffraichissement
    on_comboBox_patient_currentIndexChanged(m_ui->comboBox_patient->currentIndex());
}

void gestionAffinites::on_pushButton_ajoutIncompatibilite_clicked()
{
    QString LId=m_ui->comboBox_patient->itemData(m_ui->comboBox_patient->currentIndex()).toString();
    QString numeroDeLautre=m_ui->comboBox_listePatient->itemData(m_ui->comboBox_listePatient->currentIndex()).toString();
    QString texteRequete="insert into INCOMPATIBILITE values("+LId+","+numeroDeLautre+")";
    qDebug()<<texteRequete;
    QSqlQuery req(texteRequete);
    req.exec();
    //raffraichissement
    on_comboBox_patient_currentIndexChanged(m_ui->comboBox_patient->currentIndex());

}

#include "tableamangerview.h"
#include <QDebug>
#include <QGraphicsTextItem>
const int HAUTEUR =100;
const int LARGEUR =60;

tableAMangerView::tableAMangerView(QGraphicsScene* pScene,bool patient)
    :QGraphicsRectItem(0,pScene)
{
  affichePatients=patient;

}
void tableAMangerView::setModel(tableAManger* pModele)
{
    qDebug()<<"void tableAMangerView::setModel(tableAManger* pModele)";
    model=pModele; 
    //obtention de l'abscisse et de l'odonnée ainsi que du nombre de place
    int nomBreDePlace=model->getCapacite();
    QPointF pos=model->getPosition();
    setRect(0,0,LARGEUR*nomBreDePlace/2,HAUTEUR);
    setPos(pos);
    //on efface les QGraphicsitem*  du vecteur des personnes(repr graphique) mangeant à la table

    foreach (QGraphicsTextItem* personne,vecteurPersonne)
    {
        delete(personne);
    }
    //on efface le vecteur
    vecteurPersonne.clear();

    qDebug()<<"hauteur"<<rect().height()<<"largeur"<<rect().width();
    if(!affichePatients)
    {
        setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    }
    else
    {
        qDebug()<<"affichage des personnes demandé";
        //affichage des patients
        //boucle pour chaque personne
        int ordonnee=0;
        foreach(surveillantModel* unSurveillant,model->mapSurveillants)
        {
            qDebug("affichage d'un surveillant à la table");
            QGraphicsTextItem * pSurveillant=new QGraphicsTextItem(this);
            pSurveillant->setDefaultTextColor("#0000CC");
            pSurveillant->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
            vecteurPersonne.push_back(pSurveillant);
            pSurveillant->setFont(QFont("Verdana",10,QFont::Bold,false));
            pSurveillant->setHtml(unSurveillant->getPrenom().left(1)+". "+unSurveillant->getNom());
            pSurveillant->setPos(0,ordonnee);
            ordonnee+=pSurveillant->boundingRect().height();
        }
        foreach(patientModel* unPatient,model->mapPatients)
        {
            qDebug("affichage d'un patient à la table");
            QGraphicsTextItem * gpatient=new QGraphicsTextItem(this);
            gpatient->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
            QColor couleurPatient;
            switch(unPatient->getIdSurveillance())
            {
            case 1:couleurPatient=QColor(0,166,0);break;//vert
            case 2:couleurPatient=QColor("#ffcc00");break;//orange
            case 3:couleurPatient=QColor("#cc0000");break;//rouge
            }
            gpatient->setDefaultTextColor(couleurPatient);

            vecteurPersonne.push_back(gpatient);
            gpatient->setFont(QFont("Verdana",10,QFont::Bold,false));
            gpatient->setHtml(unPatient->getPrenom().left(1)+". "+unPatient->getNom());
            gpatient->setPos(0,ordonnee);
            ordonnee+=gpatient->boundingRect().height();
        }
        foreach(personneModel* unePersonne,model->mapAutresPersonnes)
        {
            qDebug("affichage d'une autre personne à la table");
            QGraphicsTextItem * gpersonne=new QGraphicsTextItem(this);
            gpersonne->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
            vecteurPersonne.push_back(gpersonne);
            gpersonne->setFont(QFont("Verdana",10,QFont::Bold,false));
            gpersonne->setHtml(unePersonne->getPrenom().left(1)+". "+unePersonne->getNom());
            gpersonne->setPos(0,ordonnee);
            ordonnee+=gpersonne->boundingRect().height();
        }


    }
}
void tableAMangerView::enregistrePosition()
{
    qDebug()<<"void tableAMangerView::enregistrePosition()";
    model->setPos(pos());
}
void tableAMangerView::supprimeModel()
{
    qDebug()<<"void tableAMangerView::supprimeModel()";
    model->supprime();
}
tableAMangerView::~tableAMangerView()
{
    qDebug()<<"tableAMangerView::~tableAMangerView()";
    if(pos()!=model->getPosition())
    {
        model->setPos(pos());
    }
}


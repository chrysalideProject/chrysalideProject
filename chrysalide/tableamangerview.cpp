#include "tableamangerview.h"
#include <QDebug>
#include <QGraphicsTextItem>
const int HAUTEUR =60;
const int LARGEUR =30;

tableAMangerView::tableAMangerView(QGraphicsScene* pScene,bool patient)
    :QGraphicsRectItem(0,pScene)
{
    affichePatients=patient;
  doitEtreEnregistree=false;
}
void tableAMangerView::setModel(tableAManger* pModele,int NoRepas)
{
    qDebug()<<"void tableAMangerView::setModel(tableAManger* pModele,int NoRepas)";
    model=pModele;
    model->setNoRepas(NoRepas);
    model->remplirLesMaps(NoRepas);
    //obtention de l'abscisse et de l'odonnée ainsi que du nombre de place
    int nomBreDePlace=model->getCapacite();
    QPointF pos=model->getPosition();
    setRect(0,0,LARGEUR*nomBreDePlace/2,HAUTEUR);
    setPos(pos);
    //on efface le vecteur des personnes(repr graphique) mangeant à la table

    foreach (QGraphicsTextItem* personne,vecteurPersonne)
    {
        delete(personne);
    }
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
            vecteurPersonne.push_back(pSurveillant);
            pSurveillant->setFont(QFont("Verdana",10,QFont::Bold,false));
            pSurveillant->setHtml(unSurveillant->getNom());
            pSurveillant->setPos(0,ordonnee);
            ordonnee+=pSurveillant->boundingRect().height();
        }
        foreach(patientModel* unPatient,model->mapPatients)
        {
            qDebug("affichage d'un patient à la table");
            QGraphicsTextItem * gpatient=new QGraphicsTextItem(this);
            vecteurPersonne.push_back(gpatient);
            gpatient->setFont(QFont("Verdana",10,QFont::Bold,false));
            gpatient->setHtml(unPatient->getNom());
            gpatient->setPos(0,ordonnee);
            ordonnee+=gpatient->boundingRect().height();
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
    if(doitEtreEnregistree)
    {
        model->setPos(pos());

    }
    delete(model);
    qDebug()<<"FIN - tableAMangerView::~tableAMangerView()";

}
QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)
{
    qDebug()<<"QVariant tableAMangerView::itemChange(GraphicsItemChange change,const QVariant &value)";
    if (change == QGraphicsItem::ItemPositionHasChanged)
    {
         //model->setPos(pos());
         doitEtreEnregistree=true;
     }
     return value;
}

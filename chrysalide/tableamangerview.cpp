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
    qDebug()<<"void tableAMangerView::setModel(tableAManger* pModele)";
    model=pModele;
    model->setNoRepas(NoRepas);
    model->remplirLesMaps(NoRepas);
    //obtention de l'abscisse et de l'odonnée ainsi que du nombre de place
    int nomBreDePlace=model->getCapacite();
    QPointF pos=model->getPosition();
    setRect(0,0,LARGEUR*nomBreDePlace/2,HAUTEUR);
    setPos(pos);
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
        //affichage des patients
        //boucle pour chaque personne
        int ordonnee=0;
        foreach(surveillantModel* unSurveillant,model->mapSurveillants)
        {
        QGraphicsTextItem * pSurveillant=new QGraphicsTextItem(this);
        vecteurPersonne.push_back(pSurveillant);
        pSurveillant->setFont(QFont("Verdana",10,QFont::Bold,false));
        pSurveillant->setHtml(unSurveillant->getNom());
        pSurveillant->setPos(0,ordonnee);
        ordonnee+=pSurveillant->boundingRect().height();
        }
        foreach(patientModel* unPatient,model->mapPatients)
        {
        QGraphicsTextItem * gpatient=new QGraphicsTextItem(this);
        vecteurPersonne.push_back(gpatient);
        gpatient->setFont(QFont("Verdana",10,QFont::Bold,false));
        gpatient->setHtml(unPatient->getNom());
        gpatient->setPos(0,ordonnee);
        ordonnee+=gpatient->boundingRect().height();
        }
        //finboucle
        /*title=new QGraphicsTextItem(this);
        title->setFont(QFont("Verdana",10,QFont::Bold,false));
        //déterminons la largeur de la table:
        long largeurMaxi=QFontMetrics(title->font()).width(nomTableTronque());
        for(int noChamp=0;noChamp<listeDesChamps.count();noChamp++)
        {
            long largeurDuChamp=QFontMetrics(title->font()).width(listeDesChamps[noChamp]);
            if (largeurDuChamp>largeurMaxi) largeurMaxi=largeurDuChamp;
        }
        //construction du QGraphicsRectItem
        setRect(x,y,largeurMaxi+10,200);
        //création du titre
        setBrush(QColor("#FFFF00"));//jaune
        title->setPos(0,0);//par rapport à son parent
        title->setTextWidth(boundingRect().width());
        title->setHtml("<center>"+nomTableTronque()+"</center>");

        //stockage de quelques infos
        //c'est une table
        title->setData(32,"Table");
        title->setData(34,qVariantFromValue((qlonglong)this));
        //on stocke son nom
        title->setData(33,nomTable);
        setData(32,"Table");
        setData(33,nomTable);
        setData(34,qVariantFromValue((qlonglong)this));

        //ajout d'une ligne sous le titre
        laLigne=new QGraphicsLineItem(0,ordonne,boundingRect().width(),ordonne,this,laScene);
        this->setRect(0,0,largeurMaxi+10,ordonne+10);
        //création des champs dans la table
        for(int noChamp=0;noChamp<listeDesChamps.count();noChamp++)
        {
            vecteurChamps.push_back(new field(maman,false,laScene,listeDesChamps[noChamp],this));
            vecteurChamps[noChamp]->setPos(10,ordonne);
            //sa table c'est moi
            vecteurChamps[noChamp]->laTable=this;
            //les champs d'origine ne peuvent être modifiés
              //vecteurChamps[noChamp]->setTextInteractionFlags(Qt::TextEditable);
            vecteurChamps[noChamp]->setData(32,"Field");
            vecteurChamps[noChamp]->setData(33,nom+"."+listeDesChamps[noChamp]);
            ordonne+=vecteurChamps[noChamp]->boundingRect().height();
            this->setRect(0,0,largeurMaxi+20,ordonne+10);
        }*/
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

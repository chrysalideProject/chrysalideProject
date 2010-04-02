#include "personnemodel.h"
#include <QDebug>
personneModel::personneModel(int pNumPersonne){

    QSqlQuery recupInfos("SELECT * FROM PERSONNE WHERE id = "+QString::number(pNumPersonne));

    if (recupInfos.first()){

        id = recupInfos.value(0).toInt();
        nom = recupInfos.value(1).toString();
        prenom = recupInfos.value(2).toString();

    }
    QSqlQuery monType;
    monType.exec("SELECT * FROM PATIENT WHERE idPersonne="+QString::number(id));
    if(monType.first())
    {
        type="patient";
    }
    else
    {
        monType.exec("SELECT * FROM Cuisinier WHERE idPersonne="+QString::number(id));
        if(monType.first())
        {
            type="cuisinier";
        }
        else
        {
            monType.exec("SELECT * FROM surveillant WHERE idPersonne="+QString::number(id));
            if(monType.first())
            {
                type="surveillant";
            }
            else
            {
                type="personnel";
            }
        }
    }

}

personneModel::personneModel(long pId, QString pNom, QString pPrenom)
{
    id = pId;
    nom = pNom;
    prenom = pPrenom;
}

int personneModel::insert(QString pNom, QString pPrenom)
{
    QSqlQuery max("select ifnull(max(id),0)+1 from PERSONNE");
    max.first();
    QString numero=max.value(0).toString();
    QSqlQuery insert("insert into personne values("+numero+",'"+pNom+"','"+pPrenom+"')");
    insert.exec();
    return numero.toInt();
}

void personneModel::majProfil(){

    QSqlQuery maj("UPDATE PERSONNE SET nom = '"+nom+"', prenom = '"+prenom+"' WHERE id = "+QString::number(id));
    maj.exec();

}

void personneModel::supprimer(){

    QSqlQuery supprimer("DELETE FROM PERSONNE WHERE id = "+QString::number(id));
    supprimer.exec();

}
bool personneModel::estALExterieur(int noRepas)
{
    qDebug()<<"bool personneModel::estALExterieur(int noRepas)";
    QString texteRequete="select * from prendre inner join tableamanger on prendre.idTableamanger=tableamanger.numero inner join  typetable on typetable.numero=tableamanger.typetable where typetable.libelle='"+QObject::tr("Extèrieur")+"' and idPersonne="+QString::number(id)+" and idRepas="+QString::number(noRepas);
    qDebug()<<texteRequete;
    QSqlQuery req(texteRequete);
    return req.first();
}

void personneModel::mangerExterieur(int noRepas,bool exterieur)
{
    qDebug()<<"void personneModel::mangerExterieur(int noRepas,bool exterieur)";
    if(exterieur)//le patient est à l'extérieur
    {
        QString texteRequete="select tableAManger.numero from tableAManger inner join typeTable on typetable.numero=tableamanger.typetable where typetable.libelle='"+QObject::tr("Extèrieur")+"'";
        qDebug()<<texteRequete;
        QSqlQuery reqObtentionNotable(texteRequete);
        reqObtentionNotable.first();//une seule table à l'extérieur
        int noDeLaTable=reqObtentionNotable.value(0).toInt();
        prendreRepas(noRepas,noDeLaTable);//
    }
    else//le patient n'est pas à l'extérieur
    {
        prendreRepas(noRepas,0);
    }
}

void personneModel::prendreRepas(int noRepas,int pNoTable)//si noTable vaux 0 donc faux on efface l'inscription au repas
{   //si noTable vaux 0 donc faux on efface l'inscription au repas
    qDebug()<<"void personneModel::prendreRepas(int noRepas,int pNoTable)";
    QString texteReq;
    //repas des patients et surveillants
    texteReq="delete from prendre where idPersonne="+QString::number(id)+" and idRepas="+QString::number(noRepas);
    QSqlQuery req;
    req.exec(texteReq);
    if(pNoTable!=false)
    {
        texteReq="insert into PRENDRE (idPersonne,idRepas,idTableAManger)values("+QString::number(id)+","+QString::number(noRepas)+","+QString::number(pNoTable)+")";
        req.exec(texteReq);//insertion
    }
}
void personneModel::prendreRepasAvantLHeure(int noRepas)
{
    //repas des cuisiniers et des serveurs uniquement
    QString texteReq1="select numero from tableamanger where typeTable=(select numero from typeTable where libelle='Cuisiniers')";
    QSqlQuery req1(texteReq1);
    req1.first();
    QString numeroTable=req1.value(0).toString();
    QString texteReq="insert into PRENDRE (idPersonne,idRepas,idTableAManger)values("+QString::number(id)+","+QString::number(noRepas)+","+numeroTable+")";
    QSqlQuery req2;
    req2.exec(texteReq);
}
void personneModel::estAbsent(int noRepas, bool absent)
{
    qDebug()<<"void personneModel::estAbsent(int noRepas, bool absent)";
    if(absent)//le patient est absent
    {
        QString texteRequete="select tableAManger.numero from tableAManger inner join typeTable on typetable.numero=tableamanger.typetable where typetable.libelle='"+QObject::tr("Absents")+"'";
        qDebug()<<texteRequete;
        QSqlQuery reqObtentionNotable(texteRequete);
        reqObtentionNotable.first();//une seule table à l'extérieur
        int noDeLaTable=reqObtentionNotable.value(0).toInt();
        //enregistrement de l'absence
        prendreRepas(noRepas,noDeLaTable);//enregistrement de l'absence
    }
    else//le patient n'est pas absent
    {
        prendreRepas(noRepas,0);//on efface tout
    }
}

/***Création des clés primaires***/

alter table PERSONNE add primary key (id);
alter table CUISINIER add primary key (idPersonne);
alter table AUTRE add primary key (idPersonne);
alter table PATIENT add primary key (idPersonne);
alter table SURVEILLANT add primary key (idPersonne);
alter table TRAVAIL add primary key (id);
alter table SURVEILLANCE add primary key (id);
alter table REGIME add primary key (id);
alter table TYPEREPAS add primary key (id);
alter table REPAS add primary key (id);
alter table POSTE add primary key (id);
alter table SERT add primary key (idPersonne,idRepas,idTableAManger);
alter table TABLEAMANGER add primary key (numero);
alter table TYPETABLE add primary key (numero);
alter table PRENDRE add primary key (idRepas,idPersonne);
alter table AFFINITE add primary key (idPersonne1,idPersonne2);
alter table INCOMPATIBILITE add primary key (idPersonne1,idPersonne2);

/****Création clés étrangères****/

alter table CUISINIER add foreign key (idPersonne) references PERSONNE (id);
alter table PATIENT add foreign key (idPersonne) references PERSONNE (id);
alter table AUTRE add foreign key (idPersonne) references PERSONNE (id);
alter table SURVEILLANT add foreign key (idPersonne) references PERSONNE (id);
alter table AFFINITE add foreign key (idPersonne1) references PATIENT (idPersonne);
alter table AFFINITE add foreign key (idPersonne2) references PATIENT (idPersonne);
alter table INCOMPATIBILITE add foreign key (idPersonne1) references PATIENT (idPersonne);
alter table INCOMPATIBILITE add foreign key (idPersonne2) references PATIENT (idPersonne);
alter table PATIENT add foreign key (idRegime) references REGIME (id);
alter table PATIENT add foreign key (idTravail) references TRAVAIL (id);
alter table PATIENT add foreign key (idSurveillance) references SURVEILLANCE (id);
alter table SURVEILLANT add foreign key (idPoste) references POSTE (id);
alter table REPAS add foreign key (idTypeRepas) references TYPEREPAS (id);
alter table PRENDRE add foreign key (idRepas) references REPAS (id);
alter table PRENDRE add foreign key (idPersonne) references PERSONNE (id);
alter table PRENDRE add foreign key (idTableAManger) references TABLEAMANGER (numero);
alter table TABLEAMANGER add foreign key (typeTable) references TYPETABLE (numero);
alter table SERT add foreign key (idPersonne) references PATIENT (idPersonne);
alter table SERT add foreign key (idRepas) references REPAS (id);
alter table SERT add foreign key (idTableAManger) references TABLEAMANGER (numero);

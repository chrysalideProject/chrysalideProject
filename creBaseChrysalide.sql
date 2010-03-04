/*script de création de la base de données de la chrysalide*/

/*supp des tables*/
drop table if exists TYPETABLE;
drop table if exists REGIME;
drop table if exists SURVEILLANCE;
drop table if exists TRAVAIL;
drop table if exists REPAS;
drop table if exists AUTRE;
drop table if exists CUISINIER;
drop table if exists POSTE;
drop table if exists SURVEILLANT;
drop table if exists PATIENT;
drop table if exists INCOMPATIBILITE;
drop table if exists AFFINITE;
drop table if exists TABLEAMANGER;
drop table if exists SERT;
drop table if exists PERSONNE;
drop table if exists PRENDRE;

/*création des tables*/
create table TYPETABLE
(
   	numero integer not null primary key,
	libelle varchar(50) not null
);

create table TABLEAMANGER
(
	numero integer not null primary key,
	capacite integer not null,
	typeTable integer not null references TYPETABLE(numero),
        x integer,
        y integer
);

create table PERSONNE
(
	id integer not null primary key,
	nom varchar(50) not null,
	prenom varchar(50) not null
);

create table PATIENT
(
	idPersonne integer not null references PERSONNE(id),
	idTravail integer not null references TRAVAIL(id),
	idRegime integer not null references REGIME(id),
	idSurveillance integer not null references SURVEILLANCE(id),
	primary key (idPersonne)
);

create table TRAVAIL
(
	id integer not null primary key,
	libelle varchar(50) not null
);

create table SURVEILLANCE
(
	id integer not null primary key,
	libelle varchar(50) not null
);

create table REGIME
(
	id integer not null primary key,
	libelle varchar(50) not null
);

create table AFFINITE
(
	idPersonne1 integer not null references PATIENT(idPersonne),
	idPersonne2 integer not null references PATIENT(idPersonne),
	primary key (idPersonne1, idPersonne2)
);

create table INCOMPATIBILITE
(
	idPersonne1 integer not null references PATIENT(idPersonne),
	idPersonne2 integer not null references PATIENT(idPersonne),
	primary key (idPersonne1, idPersonne2)
);

create table SERT
(
	idPersonne integer not null references PATIENT(idPersonne),
	idRepas integer not null references REPAS(id),
	idTableAManger integer not null references TABLEAMANGER(id),
	primary key(idPersonne, idRepas, idTableAManger)
);

create table REPAS
(
	id integer not null primary key,
	dateRepas date not null,
    quand varchar(4) not null check(quand in('Midi','Soir'))
);

create table PRENDRE
(
	idRepas integer not null references REPAS(id),
	idPersonne integer not null references PERSONNE(id),
	idTableAManger integer not null references TABLEAMANGER(id),
	primary key(idRepas, idPersonne)
);

create table CUISINIER
(
	idPersonne integer not null references PERSONNE(id),
	primary key (idPersonne)
);

create table AUTRE
(
	idPersonne integer not null references PERSONNE(id),
	fonction varchar(50) not null,
	primary key(idPersonne)
);

create table SURVEILLANT 
(
	idPersonne integer not null references PERSONNE(id),
	idPoste integer not null references POSTE(id),
	primary key (idPersonne)
);

create table POSTE
(
	id integer not null primary key,
	libelle varchar not null
);

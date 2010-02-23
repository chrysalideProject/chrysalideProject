/*script de création de la base de données de la chrysalide*/

/*création des tables*/
create table TYPETABLE
(
   	numero integer not null primary key,
	libelle varchar(50) text not null

);

create table TABLEAMANGER
(
	numero integer not null primary key,
	capacite integer not null,
	typeTable integer not null references TYPETABLE(numero)

);

create table PERSONNE
(
	id integer not null,
	nom varchar(50) not null,
	prenom varchar(50) not null
);

create table PATIENT
(
	idPersonne integer not null,
	idTravail integer not null,
	idRegime integer not null,
	idSurveillance integer not null
);

create table TRAVAIL
(
	id integer not null,
	libelle varchar(50) not null
);

create table SURVEILLANCE
(
	id integer not null,
	libelle varchar(50) not null
);

create table REGIME
(
	id integer not null,
	libelle varchar(50) not null
);

create table AFFINITE
(
	idPersonne1 integer not null,
	idPersonne2 integer not null
);

create table INCOMPATIBILITE
(
	idPersonne1 integer not null,
	idPersonne2 integer not null
);

create table SERT
(
	idPersonne integer not null,
	idRepas integer not null,
	idTableAManger integer not null
);

create table REPAS
(
	id integer not null,
	idTypeRepas integer not null,
	dateRepas date not null
);

create table TYPEREPAS
(
	id integer not null,
	libelle varchar(50) not null
);

create table PRENDRE
(
	idRepas integer not null,
	idPersonne integer not null,
	idTableAManger integer not null
);

create table CUISINIER
(
	idPersonne integer not null,
);

create table AUTRE
(
	idPersonne integer not null,
	fonction varchar(50) not null
);

create table SURVEILLANT 
(
	idPersonne integer not null,
	idPoste integer not null,
);

create table POSTE
(
	id integer not null,
	libelle varchar not null
);

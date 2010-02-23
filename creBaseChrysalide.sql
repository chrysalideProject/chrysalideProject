create table TYPETABLE
{
   	numero integer not null primary key,
	libelle varchar(50) not null

}
create table TABLEAMANGER
(
	numero integer not null primary key,
	capacite integer not null,
	typeTable integer not null references TYPETABLE(numero)

);

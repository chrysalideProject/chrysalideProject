create table TABLEAMANGER
(
	numero integer not null primary key,
	capacite integer not null,
	typeTable integer references TYPETABLE(numero)
);

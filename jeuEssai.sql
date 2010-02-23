/*****Création du jeu d'essai*****/

delete from TYPETABLE, TABLEAMANGER, REGIME, TRAVAIL, SURVEILLANCE, PERSONNE, POSTE, SURVEILLANT, AUTRE, PATIENT, CUISINIER, INCOMPATIBILITE, AFFINITE, REPAS, SERT, PRENDRE;

insert into TYPETABLE values (1, 'interieur');
insert into TYPETABLE values (2, 'exterieur');
insert into TYPETABLE values (3, 'sous-sol');
insert into TYPETABLE values (4, 'cuisiniers');
insert into TYPETABLE values (5, 'personnel');


insert into TABLEAMANGER values (1, 6, 1); /* une table a l'interrieur de capacité 6 places */
insert into TABLEAMANGER values (2, 6, 3); /* la table au sous sol de capacité 6 places */
insert into TABLEAMANGER values (3, 12, 4); /* table pour les cuisinier de 12 places */
insert into TABLEAMANGER values (4, 12, 5); /* table pour le personnel de 12 places */

insert into REGIME values (1, 'regime');
insert into REGIME values (2, 'surveillance');
insert into REGIME values (3, 'normal');

insert into TRAVAIL values (1, 'atelier');
insert into TRAVAIL values (2, 'macon');
insert into TRAVAIL values (3, 'espacesVerts');

insert into SURVEILLANCE values (1, 'faible');
insert into SURVEILLANCE values (2, 'moyenne');
insert into SURVEILLANCE values (3, 'forte');

insert into PERSONNE values (1, 'Goret', 'Roger');
insert into PERSONNE values (2, 'Patate', 'Monsieur');
insert into PERSONNE values (3, 'Legrand', 'Julien');
insert into PERSONNE values (4, 'Rey', 'Antony');
insert into PERSONNE values (5, 'Deliancourt', 'Lapin');
insert into PERSONNE values (6, 'Amblard', 'Elsa');
insert into PERSONNE values (7, 'Caradec', 'Mel');
insert into PERSONNE values (8, 'Sanchez', 'Ondine');
insert into PERSONNE values (9, 'Girousse', 'Simeon');

insert into POSTE values(1,'Temp Partiel');
insert into POSTE values(2,'Foyer');
insert into POSTE values(3,'ESAT');


insert into SURVEILLANT values (1,1); /* goret roget est un moniteur du temp partiel */
insert into SURVEILLANT values (4,2); /* rey antony est un moniteur du foyer */
insert into SURVEILLANT values (9,3); /* girousse simeon est un moniteur esat */


insert into AUTRE values (2);

insert into PATIENT values (5, 1, 1, 1); /* deliancourt lapin travaille a l'atelier, est au regime et a un besoin faible de surveillance */
insert into PATIENT values (3, 2, 2, 2); /* legrand julien est macon, est sous surveillance et a besoin d'une surveillance moyenne */
insert into PATIENT values (7, 3, 3, 3); /* caradec mel travaille en tant qu'espaces-verts,n'a pas de régime mais a besoin d'une force surveillance */
insert into PATIENT values (8, 1, 3, 1); /* sanchez ondine travaille a l'atelier,n'a pas de régime et a un besoin faible de surveillance */

insert into CUISINIER values (6);

insert into INCOMPATIBILITE values(3,5);

insert into AFFINITE values (7, 8);

insert into REPAS values (1,'2010-02-17');
insert into REPAS values (2,'2010-02-18');
insert into REPAS values (3,'2010-02-19');

insert into SERT values (5,1,2); /* deliancourt lapin va faire le service pour la table se trouvant au sous-sol le 17 fevrier 2010*/
insert into SERT values (3,2,1); /* julien legrand va faire le service pour la table 1 à l'interieur le 18 fevrier 2010 */
insert into SERT values (7,3,4); /* caradec mel va faire le service pour la table 4 du personnel le 19 fevrier 2010 */

insert into PRENDRE values(1,7,2); /* le 17 fevrier 2010, mel caradec a mangé au sous-sol (table 2)*/
insert into PRENDRE values(1,1,2); /* le 17 fevrier 2010, le surveillant goret roget a mangé au sous sol ( table 2) */
insert into PRENDRE values(1,6,3); /* le 17 fevrier 2010, elsa Amblard la cuisinière a mangé sur sa table (table 3)*/
insert into PRENDRE values(1,2,4); /* le 17 fevrier 2010, monsieur Patate a mangé sur la table 4 reservée pour le personnel */
insert into PRENDRE values(1,8,1); /* le 17 fevrier 2010, ondine Sanchez a mangé à l'interieur sur la table 1 */ 
insert into PRENDRE values(2,7,2); /* le 18 fevrier 2010, mel caradec a mangé au sous-sol (table 2)*/
insert into PRENDRE values(2,8,2); /* le 18 fevrier 2010, ondine Sanchez a mangé au sous-sol ( table 2 )*/
insert into PRENDRE values(2,1,2); /* le 18 fevrier 2010, le surveillant goret roget a manger au sous sol ( table 2) */
insert into PRENDRE values(3,7,1); /* le 19 fevrier 2010, mel Caradec a mangé à l'interieur sur la table 1 */
insert into PRENDRE values(3,8,2); /* le 19 fevrier 2010, ondine Sanchez a mangé au sous-sol table 2 ) */
insert into PRENDRE values(3,1,2); /* le 19 fevrier 2010, goret roget a mangé au sous-sol ( table 2 ) */

/*****Fin du fichier*****/

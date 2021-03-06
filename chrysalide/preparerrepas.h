#ifndef PREPARERREPAS_H
#define PREPARERREPAS_H

#include <QDialog>
#include "patientmodel.h"
#include "surveillantmodel.h"
#include "cuisiniermodel.h"
#include "autrepersonnelmodel.h"
#include "tableamanger.h"
#include <QTreeWidgetItem>

namespace Ui {
    class preparerRepas;
}

class preparerRepas : public QDialog {
    Q_OBJECT

    public:
        preparerRepas(QWidget *parent = 0);
        ~preparerRepas();
        typeTable* typeTableCourant();
        QVector <typeTable*> vectTypesTable;

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::preparerRepas *ui;
        QMap<int, patientModel*> mapPatients;
        QMap<int, surveillantModel*> mapSurveillants;
        QMap <int, cuisinierModel*> mapCuisiniers;
        QMap <int, autrePersonnelModel*> mapAutrePersonnels;
        QVector<tableAManger*> tablesAManger;
        int repasCourant;


    private slots:
        void on_pushButtonRAZ_clicked();
        void on_comboBoxSalle_currentIndexChanged(int index);
        void on_pushButtonValider_clicked();
        void on_pushButtonAjouterAbsent_clicked();
        void on_pushButtonAjouterServeur_clicked();
        void on_treeWidgetPatientsParMetiers_itemChanged(QTreeWidgetItem* item, int column);
        void on_pushButtonFermer_clicked();
        void placerPersonnes();
        void enregistrer();
        void initialiserCuisiniers();
        void initialiserSurveillants();
        void initialiserAutresPersonnels();
        void initialiserTreeWidgetExterieur();
        void initialiserServeurs();
        void initialiserAbsents();
        void initialiseComboTypeSalle();
        void faireTravaillerCuisinier(QListWidgetItem*);
        void faireTravaillerSurveillant(QListWidgetItem*);
        void faireTravaillerAutrePersonnel(QListWidgetItem*);
        void changeRepasCourant();

};

#endif // PREPARERREPAS_H

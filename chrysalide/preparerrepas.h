#ifndef PREPARERREPAS_H
#define PREPARERREPAS_H

#include <QDialog>
#include "patientmodel.h"
#include "surveillantmodel.h"
#include "cuisiniermodel.h"
#include "autrepersonnelmodel.h"
#include "tableamanger.h"
#include "modelarbredespatientsparmetier.h"
#include <QTreeWidgetItem>

namespace Ui {
    class preparerRepas;
}

class preparerRepas : public QDialog {
    Q_OBJECT

    public:
        preparerRepas(QWidget *parent = 0);
        ~preparerRepas();

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
        modelArbreDesPatientsParMetier* lesPatientsParMetier;

    private slots:
        void on_treeWidgetPatientsParMetiers_itemChanged(QTreeWidgetItem* item, int column);
        void on_pushButtonFermer_clicked();
        void placerPersonnes();
        void updateView();
        void initialiserCuisiniers();
        void initialiserSurveillants();
        void initialiserAutresPersonnels();
        void initialiserTreeWidgetExterieur();
        void faireTravaillerCuisinier(QListWidgetItem*);
        void faireTravaillerSurveillant(QListWidgetItem*);
        void faireTravaillerAutrePersonnel(QListWidgetItem*);
        void changeRepasCourant();

};

#endif // PREPARERREPAS_H

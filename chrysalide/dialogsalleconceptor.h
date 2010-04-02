#ifndef DIALOGSALLECONCEPTOR_H
#define DIALOGSALLECONCEPTOR_H

#include <QtGui/QDialog>
#include "typetable.h"

namespace Ui {
    class DialogSalleConceptor;
}

class DialogSalleConceptor : public QDialog {
    Q_OBJECT
public:
    DialogSalleConceptor(QWidget *parent = 0);
    ~DialogSalleConceptor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogSalleConceptor *m_ui;
    void remplirComboTypeDeTable();
    //tous les types de table dispos
    QVector<typeTable*> vectTypesTable;
    //le type de table en cours d'édition
    typeTable* typeTableCourant();
    void viderVecteur();


private slots:
    void on_pushButtonQuitter_clicked();
    void on_actionSupprimerTable_triggered();
    void on_pushButtonNewSalle_clicked();
    void on_comboBoxSalle_currentIndexChanged(int index);
};

#endif // DIALOGSALLECONCEPTOR_H

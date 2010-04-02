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
    typeTable* typeTableInterieur;

private slots:
    void on_pushButtonQuitter_clicked();
    void on_actionSupprimerTable_triggered();
    void remplirLaVue();

};

#endif // DIALOGSALLECONCEPTOR_H

#ifndef GERERTYPESTABLES_H
#define GERERTYPESTABLES_H

/*********************************************************/
/****  Classe permettant de gérer les types de tables ***/
/**** Il s'agit d'un Singleton, cette boite de dialogue */
/*** ne peut etre instanciée qu'une fois pour des raisons */
/*** de performance, d'économie de mémoire ***/
/*******************************************************/

#include <QDialog>
#include "typetable.h"

namespace Ui {
    class gererTypesTables;
}

class gererTypesTables : public QDialog {

    Q_OBJECT

    public:
        static gererTypesTables* getInstance();

    protected:
        void changeEvent(QEvent *e);

    private:
        gererTypesTables(QWidget *parent = 0);
        ~gererTypesTables();

        static gererTypesTables* instance;

        Ui::gererTypesTables *ui;
        QVector<typeTable*> typesTables;

private slots:
    void on_listeTypesTables_currentRowChanged(int currentRow);
    void on_supprimerButton_clicked();
    void on_nouveauTypeTableButton_clicked();
};

#endif // GERERTYPESTABLES_H
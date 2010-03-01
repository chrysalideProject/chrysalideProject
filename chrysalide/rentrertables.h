#ifndef RENTRERTABLES_H
#define RENTRERTABLES_H

#include <QDialog>
#include "tableamanger.h"
#include "tableview.h"

namespace Ui {
    class rentrerTables;
}

class rentrerTables : public QDialog {
    Q_OBJECT
public:
    static rentrerTables* getInstance();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::rentrerTables *ui;
    rentrerTables(QWidget *parent = 0);
    ~rentrerTables();

    static rentrerTables* instance;

    QVector<tableAManger*> tables;
    QVector<typeTable*> typesTables;

    QWidget* zoneTables;

    QVector<tableView*> vuesTables;

private slots:
    void on_gererTypesTablesButton_clicked();
    void on_ajouterTableButton_clicked();
    void updateView();
};

#endif // RENTRERTABLES_H

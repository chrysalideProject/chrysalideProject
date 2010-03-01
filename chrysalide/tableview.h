#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include "tableamanger.h"
#include "gerertypestables.h"

namespace Ui {
    class tableView;
}

class tableView : public QWidget {
    Q_OBJECT

    public:
        tableView(tableAManger* newModel, QWidget *parent = 0);
        ~tableView();
        void setModel(tableAManger*);

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::tableView *ui;
        tableAManger* leModel;

    signals:
        void modelChanged();

    private slots:
        void on_typeComboBox_activated(int index);
        void on_appliquerPushButton_clicked();
        void on_supprimerPushButton_clicked();
        void showThatItHasBeenModified();
        void updateFields();
};

#endif // TABLEVIEW_H

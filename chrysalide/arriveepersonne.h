#ifndef ARRIVEEPERSONNE_H
#define ARRIVEEPERSONNE_H

#include <QtGui/QDialog>

namespace Ui {
    class arriveePersonne;
}

class arriveePersonne : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(arriveePersonne)
public:
    explicit arriveePersonne(QWidget *parent = 0);
    virtual ~arriveePersonne();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::arriveePersonne *m_ui;

private slots:
    void on_pushButton_annuler_clicked();
    void on_pushButton_continuer_clicked();
};

#endif // ARRIVEEPERSONNE_H

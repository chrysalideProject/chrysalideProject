#ifndef GESTIONAFFINITES_H
#define GESTIONAFFINITES_H

#include <QtGui/QDialog>
#include <QtSql>
namespace Ui {
    class gestionAffinites;
}

class gestionAffinites : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(gestionAffinites)
public:
    explicit gestionAffinites(QWidget *parent = 0);
    virtual ~gestionAffinites();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::gestionAffinites *m_ui;
    QString nom;
    QString prenom;
    QString idEnCours;


private slots:
    void on_pushButton_ajoutIncompatibilite_clicked();
    void on_pushButton_ajoutAffinite_clicked();
    void on_pushButton_supprIncompatibilite_clicked();
    void on_pushButton_suppAffinite_clicked();
    void on_pushButtonFermer_clicked();
    void on_comboBox_patient_currentIndexChanged(int index);
};

#endif // GESTIONAFFINITES_H

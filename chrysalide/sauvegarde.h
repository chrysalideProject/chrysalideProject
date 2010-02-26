#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <QtGui/QWidget>
#include <QFileDialog>
#include <QDateTime>

namespace Ui {
    class sauvegarde;
}

class sauvegarde : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(sauvegarde)
public:
    explicit sauvegarde(QWidget *parent = 0);
    virtual ~sauvegarde();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::sauvegarde *m_ui;

private slots:
    void on_pushButtonSauvegarder_clicked();
    void on_pushButtonParcourir_clicked();
};

#endif // SAUVEGARDE_H

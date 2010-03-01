#ifndef DIALOGREPAS_H
#define DIALOGREPAS_H

#include <QtGui/QDialog>

namespace Ui {
    class DialogRepas;
}

class DialogRepas : public QDialog {
    Q_OBJECT
public:
    DialogRepas(QWidget *parent = 0);
    ~DialogRepas();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogRepas *m_ui;
};

#endif // DIALOGREPAS_H

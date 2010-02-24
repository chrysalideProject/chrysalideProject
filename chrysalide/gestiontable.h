#ifndef GESTIONTABLE_H
#define GESTIONTABLE_H

#include <QtGui/QDialog>

namespace Ui {
    class gestionTable;
}

class gestionTable : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(gestionTable)
public:
    explicit gestionTable(QWidget *parent = 0);
    virtual ~gestionTable();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::gestionTable *m_ui;
};

#endif // GESTIONTABLE_H

#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("chrysalide.sqlite");

    MainWindow* w;

    if (database.open()){
        w = new MainWindow(&database);
        w->show();
    }

    else{
        QMessageBox::critical(0, "Erreur", "Impossible de se connecter à la base de données");
        return 1;
    }


    return a.exec();
}

#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow* w;
        w = new MainWindow(&database);
        w->show();

    return a.exec();
}

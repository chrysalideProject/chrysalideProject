#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMessageBox>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow* w;
    w = new MainWindow(&database);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

        w->show();

    return a.exec();
}

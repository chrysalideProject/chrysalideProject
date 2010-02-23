#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QSqlDatabase>

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QSqlDatabase* pDatabase, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    QSqlDatabase* database;
};

#endif // MAINWINDOW_H

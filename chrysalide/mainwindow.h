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

private slots:
    void on_action_Quitter_triggered();
    void on_action_Ouvrir_triggered();
    void onCloseEvent(QCloseEvent* event);
};

#endif // MAINWINDOW_H

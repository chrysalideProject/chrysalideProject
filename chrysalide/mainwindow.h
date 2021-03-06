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
    QSqlDatabase *getDatabase(){return database;}

private:
    Ui::MainWindowClass *ui;
    QSqlDatabase* database;

private slots:
    void on_actionARRIVEEWIZARD_triggered();
    void on_actionRentrerBis_triggered();
    void on_action_Salles_typeTable_triggered();
    void on_action_Sauvegarde_triggered();
    void on_action_Manuel_triggered();
    void on_action_Propos_triggered();
    void on_action_gestion_des_affinit_s_triggered();
    void on_action_Pr_paration_des_tables_triggered();
    void on_action_Nouveau_triggered();
    void on_actionRentrer_les_Tables_triggered();
    void on_actionD_part_triggered();

    void on_action_Quitter_triggered();
    void on_action_Ouvrir_triggered();
    void closeEvent(QCloseEvent* event);
    void activedesactiveMenusNecessitantOuvertureBase(bool);
};

#endif // MAINWINDOW_H

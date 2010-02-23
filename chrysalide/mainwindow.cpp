#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase* pDatabase, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    database = pDatabase;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Ouvrir_triggered()
{

}

void MainWindow::on_action_Quitter_triggered()
{

}

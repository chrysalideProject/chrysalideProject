#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QCloseEvent>

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
    QFileDialog dialogOuvertureBase(this);
    dialogOuvertureBase.setFilter("*.db");
  if(dialogOuvertureBase.exec())
    {
      QString fileName=dialogOuvertureBase.getOpenFileName();
      database->setDatabaseName(fileName);
      if (!database->open())
      {
          QMessageBox::critical(this, windowTitle()+" Erreur", "Impossible d'ouvrir cette base de données");
      }
  }

}

void MainWindow::on_action_Quitter_triggered()
{
  close();
}

void MainWindow::onCloseEvent(QCloseEvent* event)
{
    if (QMessageBox::warning(this,this->windowTitle()+" Quitter?","Etes-vous sûr de vouloir quitter l'application?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No)==QMessageBox::Yes)
    {
        event->accept();
    }
    else
        event->ignore();
}

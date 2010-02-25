/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Feb 25 10:12:59 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *action_Ouvrir;
    QAction *action_Quitter;
    QAction *action_Patients;
    QAction *action_Repas;
    QAction *actionArriv_e;
    QAction *actionD_part;
    QAction *actionRentrer_les_Tables;
    QAction *action_Nouveau;
    QAction *action_Pr_paration_des_tables;
    QAction *action_gestion_des_affinit_s;
    QAction *action_Propos;
    QAction *action_Manuel;
    QAction *action_Sauvegarde;
    QAction *action_Modification_Personne;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menu_Aide;
    QMenu *menuEvenements;
    QMenu *menuConfiguration;
    QMenu *menu_Quotidien;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(445, 75);
        action_Ouvrir = new QAction(MainWindowClass);
        action_Ouvrir->setObjectName(QString::fromUtf8("action_Ouvrir"));
        action_Quitter = new QAction(MainWindowClass);
        action_Quitter->setObjectName(QString::fromUtf8("action_Quitter"));
        action_Patients = new QAction(MainWindowClass);
        action_Patients->setObjectName(QString::fromUtf8("action_Patients"));
        action_Repas = new QAction(MainWindowClass);
        action_Repas->setObjectName(QString::fromUtf8("action_Repas"));
        actionArriv_e = new QAction(MainWindowClass);
        actionArriv_e->setObjectName(QString::fromUtf8("actionArriv_e"));
        actionD_part = new QAction(MainWindowClass);
        actionD_part->setObjectName(QString::fromUtf8("actionD_part"));
        actionRentrer_les_Tables = new QAction(MainWindowClass);
        actionRentrer_les_Tables->setObjectName(QString::fromUtf8("actionRentrer_les_Tables"));
        action_Nouveau = new QAction(MainWindowClass);
        action_Nouveau->setObjectName(QString::fromUtf8("action_Nouveau"));
        action_Pr_paration_des_tables = new QAction(MainWindowClass);
        action_Pr_paration_des_tables->setObjectName(QString::fromUtf8("action_Pr_paration_des_tables"));
        action_gestion_des_affinit_s = new QAction(MainWindowClass);
        action_gestion_des_affinit_s->setObjectName(QString::fromUtf8("action_gestion_des_affinit_s"));
        action_Propos = new QAction(MainWindowClass);
        action_Propos->setObjectName(QString::fromUtf8("action_Propos"));
        action_Manuel = new QAction(MainWindowClass);
        action_Manuel->setObjectName(QString::fromUtf8("action_Manuel"));
        action_Sauvegarde = new QAction(MainWindowClass);
        action_Sauvegarde->setObjectName(QString::fromUtf8("action_Sauvegarde"));
        action_Modification_Personne = new QAction(MainWindowClass);
        action_Modification_Personne->setObjectName(QString::fromUtf8("action_Modification_Personne"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 445, 24));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        menu_Aide = new QMenu(menuBar);
        menu_Aide->setObjectName(QString::fromUtf8("menu_Aide"));
        menuEvenements = new QMenu(menuBar);
        menuEvenements->setObjectName(QString::fromUtf8("menuEvenements"));
        menuConfiguration = new QMenu(menuBar);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        menu_Quotidien = new QMenu(menuBar);
        menu_Quotidien->setObjectName(QString::fromUtf8("menu_Quotidien"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menuEvenements->menuAction());
        menuBar->addAction(menu_Quotidien->menuAction());
        menuBar->addAction(menuConfiguration->menuAction());
        menuBar->addAction(menu_Aide->menuAction());
        menu_Fichier->addAction(action_Nouveau);
        menu_Fichier->addAction(action_Ouvrir);
        menu_Fichier->addAction(action_Quitter);
        menu_Aide->addAction(action_Manuel);
        menu_Aide->addAction(action_Propos);
        menuEvenements->addAction(actionArriv_e);
        menuEvenements->addAction(actionD_part);
        menuEvenements->addAction(action_Modification_Personne);
        menuConfiguration->addAction(actionRentrer_les_Tables);
        menuConfiguration->addAction(action_Sauvegarde);
        menu_Quotidien->addAction(action_Pr_paration_des_tables);
        menu_Quotidien->addAction(action_gestion_des_affinit_s);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Chrysalide", 0, QApplication::UnicodeUTF8));
        action_Ouvrir->setText(QApplication::translate("MainWindowClass", "&Ouvrir", 0, QApplication::UnicodeUTF8));
        action_Quitter->setText(QApplication::translate("MainWindowClass", "&Quitter", 0, QApplication::UnicodeUTF8));
        action_Patients->setText(QApplication::translate("MainWindowClass", "&Patients", 0, QApplication::UnicodeUTF8));
        action_Repas->setText(QApplication::translate("MainWindowClass", "&Repas", 0, QApplication::UnicodeUTF8));
        actionArriv_e->setText(QApplication::translate("MainWindowClass", "&Arriv\303\251e", 0, QApplication::UnicodeUTF8));
        actionD_part->setText(QApplication::translate("MainWindowClass", "&D\303\251part", 0, QApplication::UnicodeUTF8));
        actionRentrer_les_Tables->setText(QApplication::translate("MainWindowClass", "&Rentrer les Tables", 0, QApplication::UnicodeUTF8));
        action_Nouveau->setText(QApplication::translate("MainWindowClass", "&Nouveau", 0, QApplication::UnicodeUTF8));
        action_Pr_paration_des_tables->setText(QApplication::translate("MainWindowClass", "&Pr\303\251paration du repas", 0, QApplication::UnicodeUTF8));
        action_gestion_des_affinit_s->setText(QApplication::translate("MainWindowClass", "&Gestion des affinit\303\251s", 0, QApplication::UnicodeUTF8));
        action_Propos->setText(QApplication::translate("MainWindowClass", "\303\240 &Propos", 0, QApplication::UnicodeUTF8));
        action_Manuel->setText(QApplication::translate("MainWindowClass", "&Manuel", 0, QApplication::UnicodeUTF8));
        action_Sauvegarde->setText(QApplication::translate("MainWindowClass", "&Sauvegarde", 0, QApplication::UnicodeUTF8));
        action_Modification_Personne->setText(QApplication::translate("MainWindowClass", "&Modification Personne", 0, QApplication::UnicodeUTF8));
        menu_Fichier->setTitle(QApplication::translate("MainWindowClass", "&Fichier", 0, QApplication::UnicodeUTF8));
        menu_Aide->setTitle(QApplication::translate("MainWindowClass", "&Aide", 0, QApplication::UnicodeUTF8));
        menuEvenements->setTitle(QApplication::translate("MainWindowClass", "&Evenements", 0, QApplication::UnicodeUTF8));
        menuConfiguration->setTitle(QApplication::translate("MainWindowClass", "&Configuration", 0, QApplication::UnicodeUTF8));
        menu_Quotidien->setTitle(QApplication::translate("MainWindowClass", "&Quotidien", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

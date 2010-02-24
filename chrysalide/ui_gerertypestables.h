/********************************************************************************
** Form generated from reading UI file 'gerertypestables.ui'
**
** Created: Tue Feb 23 21:59:14 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERERTYPESTABLES_H
#define UI_GERERTYPESTABLES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gererTypesTables
{
public:
    QListWidget *listeTypesTables;
    QPushButton *nouveauTypeTableButton;
    QLabel *label;
    QWidget *typeTableView;
    QLabel *numeroLabel;
    QLineEdit *libelleLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *supprimerButton;

    void setupUi(QDialog *gererTypesTables)
    {
        if (gererTypesTables->objectName().isEmpty())
            gererTypesTables->setObjectName(QString::fromUtf8("gererTypesTables"));
        gererTypesTables->resize(553, 389);
        listeTypesTables = new QListWidget(gererTypesTables);
        listeTypesTables->setObjectName(QString::fromUtf8("listeTypesTables"));
        listeTypesTables->setGeometry(QRect(10, 50, 211, 301));
        nouveauTypeTableButton = new QPushButton(gererTypesTables);
        nouveauTypeTableButton->setObjectName(QString::fromUtf8("nouveauTypeTableButton"));
        nouveauTypeTableButton->setGeometry(QRect(30, 360, 166, 27));
        label = new QLabel(gererTypesTables);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 101, 17));
        typeTableView = new QWidget(gererTypesTables);
        typeTableView->setObjectName(QString::fromUtf8("typeTableView"));
        typeTableView->setGeometry(QRect(250, 79, 291, 211));
        numeroLabel = new QLabel(typeTableView);
        numeroLabel->setObjectName(QString::fromUtf8("numeroLabel"));
        numeroLabel->setGeometry(QRect(110, 10, 62, 17));
        libelleLineEdit = new QLineEdit(typeTableView);
        libelleLineEdit->setObjectName(QString::fromUtf8("libelleLineEdit"));
        libelleLineEdit->setGeometry(QRect(100, 40, 113, 27));
        label_2 = new QLabel(typeTableView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 10, 62, 17));
        label_3 = new QLabel(typeTableView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 40, 62, 17));
        pushButton_2 = new QPushButton(typeTableView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 100, 92, 27));
        supprimerButton = new QPushButton(typeTableView);
        supprimerButton->setObjectName(QString::fromUtf8("supprimerButton"));
        supprimerButton->setGeometry(QRect(110, 140, 92, 27));

        retranslateUi(gererTypesTables);

        QMetaObject::connectSlotsByName(gererTypesTables);
    } // setupUi

    void retranslateUi(QDialog *gererTypesTables)
    {
        gererTypesTables->setWindowTitle(QApplication::translate("gererTypesTables", "G\303\251rer les types de tables", 0, QApplication::UnicodeUTF8));
        nouveauTypeTableButton->setText(QApplication::translate("gererTypesTables", "Nouveau type de table", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("gererTypesTables", "Types de tables", 0, QApplication::UnicodeUTF8));
        numeroLabel->setText(QApplication::translate("gererTypesTables", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("gererTypesTables", "Numero", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("gererTypesTables", "Libelle", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("gererTypesTables", "Appliquer", 0, QApplication::UnicodeUTF8));
        supprimerButton->setText(QApplication::translate("gererTypesTables", "Supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gererTypesTables: public Ui_gererTypesTables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERERTYPESTABLES_H

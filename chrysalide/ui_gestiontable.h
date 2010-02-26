/********************************************************************************
** Form generated from reading ui file 'gestiontable.ui'
**
** Created: Thu Feb 25 10:12:59 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GESTIONTABLE_H
#define UI_GESTIONTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_gestionTable
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_table;
    QComboBox *comboBox_table;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_typeRepas;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_serveur;
    QComboBox *comboBox_serveur;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_surveillance;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *spinBox_nombreDePersonne;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidget_2;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *gestionTable)
    {
        if (gestionTable->objectName().isEmpty())
            gestionTable->setObjectName(QString::fromUtf8("gestionTable"));
        gestionTable->resize(503, 469);
        verticalLayout_3 = new QVBoxLayout(gestionTable);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_table = new QLabel(gestionTable);
        label_table->setObjectName(QString::fromUtf8("label_table"));

        horizontalLayout->addWidget(label_table);

        comboBox_table = new QComboBox(gestionTable);
        comboBox_table->setObjectName(QString::fromUtf8("comboBox_table"));

        horizontalLayout->addWidget(comboBox_table);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(gestionTable);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox_typeRepas = new QComboBox(gestionTable);
        comboBox_typeRepas->setObjectName(QString::fromUtf8("comboBox_typeRepas"));

        verticalLayout->addWidget(comboBox_typeRepas);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_serveur = new QLabel(gestionTable);
        label_serveur->setObjectName(QString::fromUtf8("label_serveur"));

        horizontalLayout_4->addWidget(label_serveur);

        comboBox_serveur = new QComboBox(gestionTable);
        comboBox_serveur->setObjectName(QString::fromUtf8("comboBox_serveur"));

        horizontalLayout_4->addWidget(comboBox_serveur);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(gestionTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        comboBox_surveillance = new QComboBox(gestionTable);
        comboBox_surveillance->setObjectName(QString::fromUtf8("comboBox_surveillance"));

        horizontalLayout_5->addWidget(comboBox_surveillance);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(gestionTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBox_nombreDePersonne = new QSpinBox(gestionTable);
        spinBox_nombreDePersonne->setObjectName(QString::fromUtf8("spinBox_nombreDePersonne"));

        horizontalLayout_3->addWidget(spinBox_nombreDePersonne);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_5 = new QLabel(gestionTable);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(gestionTable);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(206, 16777215));

        horizontalLayout_7->addWidget(label_6);

        label_3 = new QLabel(gestionTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        listWidget = new QListWidget(gestionTable);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_6->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(gestionTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(40, 16777215));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(gestionTable);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(40, 16777215));

        verticalLayout_2->addWidget(pushButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_2);

        listWidget_2 = new QListWidget(gestionTable);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        horizontalLayout_6->addWidget(listWidget_2);

        pushButton = new QPushButton(gestionTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        buttonBox = new QDialogButtonBox(gestionTable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(gestionTable);
        QObject::connect(buttonBox, SIGNAL(accepted()), gestionTable, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), gestionTable, SLOT(reject()));

        QMetaObject::connectSlotsByName(gestionTable);
    } // setupUi

    void retranslateUi(QDialog *gestionTable)
    {
        gestionTable->setWindowTitle(QApplication::translate("gestionTable", "Dialog", 0, QApplication::UnicodeUTF8));
        label_table->setText(QApplication::translate("gestionTable", "Table : ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("gestionTable", "Type de repas : ", 0, QApplication::UnicodeUTF8));
        label_serveur->setText(QApplication::translate("gestionTable", "Serveur :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("gestionTable", "Surveillance : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("gestionTable", "Nombre de personne \303\240 cette table : ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("gestionTable", "Gestion des personnes pr\303\251sentes \303\240 la table : ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("gestionTable", "A cette table :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("gestionTable", "Non plac\303\251 : ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("gestionTable", "<<<", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("gestionTable", ">>>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("gestionTable", "Infos personne", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(gestionTable);
    } // retranslateUi

};

namespace Ui {
    class gestionTable: public Ui_gestionTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONTABLE_H

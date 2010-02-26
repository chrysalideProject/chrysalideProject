/********************************************************************************
** Form generated from reading ui file 'dialogsalleconceptor.ui'
**
** Created: Fri Feb 26 10:22:39 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOGSALLECONCEPTOR_H
#define UI_DIALOGSALLECONCEPTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "typetableview.h"

QT_BEGIN_NAMESPACE

class Ui_DialogSalleConceptor
{
public:
    QAction *actionSupprimerTable;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxSalle;
    QPushButton *pushButtonNewSalle;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidgetTable;
    typeTableView *salleViewCourante;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonQuitter;

    void setupUi(QDialog *DialogSalleConceptor)
    {
        if (DialogSalleConceptor->objectName().isEmpty())
            DialogSalleConceptor->setObjectName(QString::fromUtf8("DialogSalleConceptor"));
        DialogSalleConceptor->resize(400, 300);
        actionSupprimerTable = new QAction(DialogSalleConceptor);
        actionSupprimerTable->setObjectName(QString::fromUtf8("actionSupprimerTable"));
        verticalLayout = new QVBoxLayout(DialogSalleConceptor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogSalleConceptor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxSalle = new QComboBox(DialogSalleConceptor);
        comboBoxSalle->setObjectName(QString::fromUtf8("comboBoxSalle"));

        horizontalLayout->addWidget(comboBoxSalle);

        pushButtonNewSalle = new QPushButton(DialogSalleConceptor);
        pushButtonNewSalle->setObjectName(QString::fromUtf8("pushButtonNewSalle"));

        horizontalLayout->addWidget(pushButtonNewSalle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidgetTable = new QListWidget(DialogSalleConceptor);
        new QListWidgetItem(listWidgetTable);
        listWidgetTable->setObjectName(QString::fromUtf8("listWidgetTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidgetTable->sizePolicy().hasHeightForWidth());
        listWidgetTable->setSizePolicy(sizePolicy);
        listWidgetTable->setMinimumSize(QSize(0, 10));
        listWidgetTable->setMaximumSize(QSize(16777215, 30));
        listWidgetTable->setDragDropMode(QAbstractItemView::DragOnly);

        verticalLayout->addWidget(listWidgetTable);

        salleViewCourante = new typeTableView(DialogSalleConceptor);
        salleViewCourante->setObjectName(QString::fromUtf8("salleViewCourante"));

        verticalLayout->addWidget(salleViewCourante);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonQuitter = new QPushButton(DialogSalleConceptor);
        pushButtonQuitter->setObjectName(QString::fromUtf8("pushButtonQuitter"));

        horizontalLayout_2->addWidget(pushButtonQuitter);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogSalleConceptor);

        QMetaObject::connectSlotsByName(DialogSalleConceptor);
    } // setupUi

    void retranslateUi(QDialog *DialogSalleConceptor)
    {
        DialogSalleConceptor->setWindowTitle(QApplication::translate("DialogSalleConceptor", "Dialog", 0, QApplication::UnicodeUTF8));
        actionSupprimerTable->setText(QApplication::translate("DialogSalleConceptor", "SupprimerTable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSupprimerTable->setToolTip(QApplication::translate("DialogSalleConceptor", "supression des tables s\303\251lectionn\303\251es", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSupprimerTable->setShortcut(QApplication::translate("DialogSalleConceptor", "Del", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogSalleConceptor", "Type", 0, QApplication::UnicodeUTF8));
        pushButtonNewSalle->setText(QApplication::translate("DialogSalleConceptor", "&Nouveau Type", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidgetTable->isSortingEnabled();
        listWidgetTable->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetTable->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("DialogSalleConceptor", "Nouvelle Table", 0, QApplication::UnicodeUTF8));
        listWidgetTable->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_STATUSTIP
        salleViewCourante->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonQuitter->setText(QApplication::translate("DialogSalleConceptor", "&Quitter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DialogSalleConceptor);
    } // retranslateUi

};

namespace Ui {
    class DialogSalleConceptor: public Ui_DialogSalleConceptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSALLECONCEPTOR_H

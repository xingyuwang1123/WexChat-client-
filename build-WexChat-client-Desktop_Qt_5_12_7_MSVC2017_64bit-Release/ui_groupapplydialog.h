/********************************************************************************
** Form generated from reading UI file 'groupapplydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPAPPLYDIALOG_H
#define UI_GROUPAPPLYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupApplyDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *GroupApplyDialog)
    {
        if (GroupApplyDialog->objectName().isEmpty())
            GroupApplyDialog->setObjectName(QString::fromUtf8("GroupApplyDialog"));
        GroupApplyDialog->resize(340, 449);
        scrollArea = new QScrollArea(GroupApplyDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 340, 449));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 338, 447));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(GroupApplyDialog);

        QMetaObject::connectSlotsByName(GroupApplyDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupApplyDialog)
    {
        GroupApplyDialog->setWindowTitle(QApplication::translate("GroupApplyDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupApplyDialog: public Ui_GroupApplyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPAPPLYDIALOG_H

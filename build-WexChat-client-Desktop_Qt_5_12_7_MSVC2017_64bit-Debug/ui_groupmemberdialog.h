/********************************************************************************
** Form generated from reading UI file 'groupmemberdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMEMBERDIALOG_H
#define UI_GROUPMEMBERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupMemberDialog
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *GroupMemberDialog)
    {
        if (GroupMemberDialog->objectName().isEmpty())
            GroupMemberDialog->setObjectName(QString::fromUtf8("GroupMemberDialog"));
        GroupMemberDialog->resize(343, 480);
        listWidget = new QListWidget(GroupMemberDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 342, 479));

        retranslateUi(GroupMemberDialog);

        QMetaObject::connectSlotsByName(GroupMemberDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupMemberDialog)
    {
        GroupMemberDialog->setWindowTitle(QApplication::translate("GroupMemberDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupMemberDialog: public Ui_GroupMemberDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMEMBERDIALOG_H

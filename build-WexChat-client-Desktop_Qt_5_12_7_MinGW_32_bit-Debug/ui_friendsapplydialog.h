/********************************************************************************
** Form generated from reading UI file 'friendsapplydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSAPPLYDIALOG_H
#define UI_FRIENDSAPPLYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendsApplyDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *FriendsApplyDialog)
    {
        if (FriendsApplyDialog->objectName().isEmpty())
            FriendsApplyDialog->setObjectName(QString::fromUtf8("FriendsApplyDialog"));
        FriendsApplyDialog->resize(320, 408);
        scrollArea = new QScrollArea(FriendsApplyDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 319, 409));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 317, 407));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(FriendsApplyDialog);

        QMetaObject::connectSlotsByName(FriendsApplyDialog);
    } // setupUi

    void retranslateUi(QDialog *FriendsApplyDialog)
    {
        FriendsApplyDialog->setWindowTitle(QApplication::translate("FriendsApplyDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendsApplyDialog: public Ui_FriendsApplyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSAPPLYDIALOG_H

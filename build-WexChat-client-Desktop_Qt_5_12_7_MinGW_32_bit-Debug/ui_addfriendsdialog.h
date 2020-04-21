/********************************************************************************
** Form generated from reading UI file 'addfriendsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDSDIALOG_H
#define UI_ADDFRIENDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendsDialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *AddFriendsDialog)
    {
        if (AddFriendsDialog->objectName().isEmpty())
            AddFriendsDialog->setObjectName(QString::fromUtf8("AddFriendsDialog"));
        AddFriendsDialog->resize(320, 240);
        widget = new QWidget(AddFriendsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 80, 261, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMaxLength(16);

        horizontalLayout->addWidget(nameEdit);

        pushButton = new QPushButton(AddFriendsDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 170, 101, 31));

        retranslateUi(AddFriendsDialog);

        QMetaObject::connectSlotsByName(AddFriendsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFriendsDialog)
    {
        AddFriendsDialog->setWindowTitle(QApplication::translate("AddFriendsDialog", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        label->setText(QApplication::translate("AddFriendsDialog", "uid:", nullptr));
        pushButton->setText(QApplication::translate("AddFriendsDialog", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendsDialog: public Ui_AddFriendsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDSDIALOG_H

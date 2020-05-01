/********************************************************************************
** Form generated from reading UI file 'creategroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPDIALOG_H
#define UI_CREATEGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupDialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QPushButton *submitButton;

    void setupUi(QDialog *CreateGroupDialog)
    {
        if (CreateGroupDialog->objectName().isEmpty())
            CreateGroupDialog->setObjectName(QString::fromUtf8("CreateGroupDialog"));
        CreateGroupDialog->resize(371, 170);
        widget = new QWidget(CreateGroupDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 271, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        idEdit = new QLineEdit(widget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setMaxLength(16);

        horizontalLayout->addWidget(idEdit);

        submitButton = new QPushButton(CreateGroupDialog);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(120, 100, 91, 31));

        retranslateUi(CreateGroupDialog);

        QMetaObject::connectSlotsByName(CreateGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateGroupDialog)
    {
        CreateGroupDialog->setWindowTitle(QApplication::translate("CreateGroupDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("CreateGroupDialog", "id:", nullptr));
        submitButton->setText(QApplication::translate("CreateGroupDialog", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupDialog: public Ui_CreateGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPDIALOG_H

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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AddFriendsDialog)
    {
        if (AddFriendsDialog->objectName().isEmpty())
            AddFriendsDialog->setObjectName(QString::fromUtf8("AddFriendsDialog"));
        AddFriendsDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(AddFriendsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 181, 301, 51));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(AddFriendsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 80, 261, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(16);

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(AddFriendsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddFriendsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddFriendsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddFriendsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFriendsDialog)
    {
        AddFriendsDialog->setWindowTitle(QApplication::translate("AddFriendsDialog", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        label->setText(QApplication::translate("AddFriendsDialog", "uid/\350\264\246\345\217\267:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendsDialog: public Ui_AddFriendsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDSDIALOG_H

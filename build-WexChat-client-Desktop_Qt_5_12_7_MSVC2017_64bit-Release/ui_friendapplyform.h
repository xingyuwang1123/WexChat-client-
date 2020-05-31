/********************************************************************************
** Form generated from reading UI file 'friendapplyform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDAPPLYFORM_H
#define UI_FRIENDAPPLYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendApplyForm
{
public:
    QLabel *headerlabel;
    QLabel *namelabel;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *FriendApplyForm)
    {
        if (FriendApplyForm->objectName().isEmpty())
            FriendApplyForm->setObjectName(QString::fromUtf8("FriendApplyForm"));
        FriendApplyForm->resize(320, 161);
        headerlabel = new QLabel(FriendApplyForm);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(20, 10, 41, 31));
        namelabel = new QLabel(FriendApplyForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(80, 20, 81, 16));
        plainTextEdit = new QPlainTextEdit(FriendApplyForm);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 60, 281, 81));

        retranslateUi(FriendApplyForm);

        QMetaObject::connectSlotsByName(FriendApplyForm);
    } // setupUi

    void retranslateUi(QWidget *FriendApplyForm)
    {
        FriendApplyForm->setWindowTitle(QApplication::translate("FriendApplyForm", "Form", nullptr));
        headerlabel->setText(QString());
        namelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendApplyForm: public Ui_FriendApplyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDAPPLYFORM_H

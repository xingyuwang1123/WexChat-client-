/********************************************************************************
** Form generated from reading UI file 'groupapplyform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPAPPLYFORM_H
#define UI_GROUPAPPLYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupApplyForm
{
public:
    QLabel *namelabel;
    QLabel *headerlabel;
    QTextBrowser *infoBrowser;
    QPushButton *rejectButton;
    QPushButton *agreeButton;

    void setupUi(QWidget *GroupApplyForm)
    {
        if (GroupApplyForm->objectName().isEmpty())
            GroupApplyForm->setObjectName(QString::fromUtf8("GroupApplyForm"));
        GroupApplyForm->resize(340, 189);
        namelabel = new QLabel(GroupApplyForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(70, 20, 71, 16));
        headerlabel = new QLabel(GroupApplyForm);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(10, 10, 40, 40));
        headerlabel->setPixmap(QPixmap(QString::fromUtf8(":/img/center.svg")));
        headerlabel->setScaledContents(true);
        infoBrowser = new QTextBrowser(GroupApplyForm);
        infoBrowser->setObjectName(QString::fromUtf8("infoBrowser"));
        infoBrowser->setGeometry(QRect(10, 70, 321, 71));
        rejectButton = new QPushButton(GroupApplyForm);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));
        rejectButton->setGeometry(QRect(200, 150, 75, 23));
        agreeButton = new QPushButton(GroupApplyForm);
        agreeButton->setObjectName(QString::fromUtf8("agreeButton"));
        agreeButton->setGeometry(QRect(50, 150, 75, 23));

        retranslateUi(GroupApplyForm);

        QMetaObject::connectSlotsByName(GroupApplyForm);
    } // setupUi

    void retranslateUi(QWidget *GroupApplyForm)
    {
        GroupApplyForm->setWindowTitle(QApplication::translate("GroupApplyForm", "Form", nullptr));
        namelabel->setText(QApplication::translate("GroupApplyForm", "name", nullptr));
        headerlabel->setText(QString());
        rejectButton->setText(QApplication::translate("GroupApplyForm", "\346\213\222\347\273\235", nullptr));
        agreeButton->setText(QApplication::translate("GroupApplyForm", "\345\220\214\346\204\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupApplyForm: public Ui_GroupApplyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPAPPLYFORM_H

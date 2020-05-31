/********************************************************************************
** Form generated from reading UI file 'applyitemform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYITEMFORM_H
#define UI_APPLYITEMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_applyItemForm
{
public:
    QLabel *headerlabel;
    QLabel *namelabel;
    QTextBrowser *infoBrowser;
    QPushButton *rejectButton;
    QPushButton *acceptButton;

    void setupUi(QWidget *applyItemForm)
    {
        if (applyItemForm->objectName().isEmpty())
            applyItemForm->setObjectName(QString::fromUtf8("applyItemForm"));
        applyItemForm->resize(320, 175);
        headerlabel = new QLabel(applyItemForm);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(10, 10, 32, 32));
        namelabel = new QLabel(applyItemForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(60, 20, 81, 16));
        infoBrowser = new QTextBrowser(applyItemForm);
        infoBrowser->setObjectName(QString::fromUtf8("infoBrowser"));
        infoBrowser->setGeometry(QRect(20, 50, 281, 81));
        rejectButton = new QPushButton(applyItemForm);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));
        rejectButton->setGeometry(QRect(210, 140, 75, 23));
        acceptButton = new QPushButton(applyItemForm);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));
        acceptButton->setGeometry(QRect(110, 140, 75, 23));

        retranslateUi(applyItemForm);

        QMetaObject::connectSlotsByName(applyItemForm);
    } // setupUi

    void retranslateUi(QWidget *applyItemForm)
    {
        applyItemForm->setWindowTitle(QApplication::translate("applyItemForm", "Form", nullptr));
        headerlabel->setText(QString());
        namelabel->setText(QString());
        rejectButton->setText(QApplication::translate("applyItemForm", "\346\213\222\347\273\235", nullptr));
        acceptButton->setText(QApplication::translate("applyItemForm", "\345\220\214\346\204\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class applyItemForm: public Ui_applyItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYITEMFORM_H

/********************************************************************************
** Form generated from reading UI file 'messageitemform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEITEMFORM_H
#define UI_MESSAGEITEMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageItemForm
{
public:
    QLabel *headerlabel;
    QLabel *namelabel;
    QLabel *countlabel;

    void setupUi(QWidget *MessageItemForm)
    {
        if (MessageItemForm->objectName().isEmpty())
            MessageItemForm->setObjectName(QString::fromUtf8("MessageItemForm"));
        MessageItemForm->resize(219, 61);
        headerlabel = new QLabel(MessageItemForm);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(10, 5, 50, 50));
        namelabel = new QLabel(MessageItemForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(73, 10, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        namelabel->setFont(font);
        namelabel->setTextFormat(Qt::RichText);
        countlabel = new QLabel(MessageItemForm);
        countlabel->setObjectName(QString::fromUtf8("countlabel"));
        countlabel->setGeometry(QRect(170, 20, 54, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        countlabel->setFont(font1);

        retranslateUi(MessageItemForm);

        QMetaObject::connectSlotsByName(MessageItemForm);
    } // setupUi

    void retranslateUi(QWidget *MessageItemForm)
    {
        MessageItemForm->setWindowTitle(QApplication::translate("MessageItemForm", "Form", nullptr));
        headerlabel->setText(QString());
        namelabel->setText(QApplication::translate("MessageItemForm", "name", nullptr));
        countlabel->setText(QApplication::translate("MessageItemForm", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageItemForm: public Ui_MessageItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEITEMFORM_H

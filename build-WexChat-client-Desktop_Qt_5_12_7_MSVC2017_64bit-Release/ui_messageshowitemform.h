/********************************************************************************
** Form generated from reading UI file 'messageshowitemform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESHOWITEMFORM_H
#define UI_MESSAGESHOWITEMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageShowItemForm
{
public:
    QLabel *namelabel;
    QLabel *headerlabel;
    QLabel *timelabel;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MessageShowItemForm)
    {
        if (MessageShowItemForm->objectName().isEmpty())
            MessageShowItemForm->setObjectName(QString::fromUtf8("MessageShowItemForm"));
        MessageShowItemForm->resize(579, 80);
        namelabel = new QLabel(MessageShowItemForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(60, 50, 71, 16));
        headerlabel = new QLabel(MessageShowItemForm);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(10, 10, 30, 30));
        timelabel = new QLabel(MessageShowItemForm);
        timelabel->setObjectName(QString::fromUtf8("timelabel"));
        timelabel->setGeometry(QRect(60, 10, 71, 21));
        textBrowser = new QTextBrowser(MessageShowItemForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 10, 441, 61));

        retranslateUi(MessageShowItemForm);

        QMetaObject::connectSlotsByName(MessageShowItemForm);
    } // setupUi

    void retranslateUi(QWidget *MessageShowItemForm)
    {
        MessageShowItemForm->setWindowTitle(QApplication::translate("MessageShowItemForm", "Form", nullptr));
        namelabel->setText(QApplication::translate("MessageShowItemForm", "name", nullptr));
        headerlabel->setText(QString());
        timelabel->setText(QApplication::translate("MessageShowItemForm", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageShowItemForm: public Ui_MessageShowItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESHOWITEMFORM_H

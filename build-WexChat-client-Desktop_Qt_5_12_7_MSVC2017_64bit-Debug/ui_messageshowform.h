/********************************************************************************
** Form generated from reading UI file 'messageshowform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESHOWFORM_H
#define UI_MESSAGESHOWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageShowForm
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *MessageShowForm)
    {
        if (MessageShowForm->objectName().isEmpty())
            MessageShowForm->setObjectName(QString::fromUtf8("MessageShowForm"));
        MessageShowForm->resize(579, 361);
        scrollArea = new QScrollArea(MessageShowForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 579, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 577, 359));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(MessageShowForm);

        QMetaObject::connectSlotsByName(MessageShowForm);
    } // setupUi

    void retranslateUi(QWidget *MessageShowForm)
    {
        MessageShowForm->setWindowTitle(QApplication::translate("MessageShowForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageShowForm: public Ui_MessageShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESHOWFORM_H

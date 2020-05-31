/********************************************************************************
** Form generated from reading UI file 'messagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWINDOW_H
#define UI_MESSAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageWindow
{
public:
    QScrollArea *messagescrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *MessageWindow)
    {
        if (MessageWindow->objectName().isEmpty())
            MessageWindow->setObjectName(QString::fromUtf8("MessageWindow"));
        MessageWindow->resize(800, 534);
        messagescrollArea = new QScrollArea(MessageWindow);
        messagescrollArea->setObjectName(QString::fromUtf8("messagescrollArea"));
        messagescrollArea->setGeometry(QRect(0, 0, 220, 534));
        messagescrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 218, 532));
        messagescrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(MessageWindow);

        QMetaObject::connectSlotsByName(MessageWindow);
    } // setupUi

    void retranslateUi(QWidget *MessageWindow)
    {
        MessageWindow->setWindowTitle(QApplication::translate("MessageWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageWindow: public Ui_MessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWINDOW_H

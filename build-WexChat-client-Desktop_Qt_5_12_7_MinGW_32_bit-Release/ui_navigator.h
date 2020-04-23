/********************************************************************************
** Form generated from reading UI file 'navigator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATOR_H
#define UI_NAVIGATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navigator
{
public:
    QFrame *frame;
    QLabel *headerLabel;
    QLabel *usernameLabel;
    QPushButton *centerButton;
    QPushButton *firendsButton;
    QPushButton *messageButton;

    void setupUi(QWidget *Navigator)
    {
        if (Navigator->objectName().isEmpty())
            Navigator->setObjectName(QString::fromUtf8("Navigator"));
        Navigator->resize(800, 56);
        Navigator->setAutoFillBackground(true);
        Navigator->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(Navigator);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 56));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        headerLabel = new QLabel(frame);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        headerLabel->setGeometry(QRect(15, 5, 45, 45));
        headerLabel->setAutoFillBackground(true);
        headerLabel->setStyleSheet(QString::fromUtf8(""));
        usernameLabel = new QLabel(frame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(100, 20, 60, 20));
        usernameLabel->setAutoFillBackground(true);
        centerButton = new QPushButton(frame);
        centerButton->setObjectName(QString::fromUtf8("centerButton"));
        centerButton->setGeometry(QRect(520, 10, 40, 40));
        centerButton->setAutoFillBackground(true);
        centerButton->setStyleSheet(QString::fromUtf8(""));
        centerButton->setFlat(true);
        firendsButton = new QPushButton(frame);
        firendsButton->setObjectName(QString::fromUtf8("firendsButton"));
        firendsButton->setGeometry(QRect(430, 8, 40, 40));
        firendsButton->setAutoFillBackground(true);
        firendsButton->setStyleSheet(QString::fromUtf8(""));
        firendsButton->setFlat(true);
        messageButton = new QPushButton(frame);
        messageButton->setObjectName(QString::fromUtf8("messageButton"));
        messageButton->setGeometry(QRect(340, 8, 40, 40));
        messageButton->setAutoFillBackground(true);
        messageButton->setStyleSheet(QString::fromUtf8(""));
        messageButton->setFlat(true);

        retranslateUi(Navigator);

        QMetaObject::connectSlotsByName(Navigator);
    } // setupUi

    void retranslateUi(QWidget *Navigator)
    {
        Navigator->setWindowTitle(QApplication::translate("Navigator", "Form", nullptr));
        headerLabel->setText(QString());
        usernameLabel->setText(QString());
        centerButton->setText(QString());
        firendsButton->setText(QString());
        messageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Navigator: public Ui_Navigator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATOR_H

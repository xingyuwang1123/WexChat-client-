/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *passwordEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *newuserButton;
    QPushButton *loginButton;
    QLabel *warning;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(417, 318);
        LoginWindow->setMinimumSize(QSize(417, 318));
        LoginWindow->setMaximumSize(QSize(417, 318));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 291, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setMaxLength(16);

        gridLayout->addWidget(usernameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setMaxLength(16);
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 1, 1, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(90, 190, 221, 61));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newuserButton = new QPushButton(widget_2);
        newuserButton->setObjectName(QString::fromUtf8("newuserButton"));

        horizontalLayout->addWidget(newuserButton);

        loginButton = new QPushButton(widget_2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);

        warning = new QLabel(centralwidget);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(140, 160, 101, 16));
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "\347\231\273\351\231\206", nullptr));
        label_2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        label->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordEdit->setInputMask(QString());
        newuserButton->setText(QApplication::translate("LoginWindow", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267", nullptr));
        loginButton->setText(QApplication::translate("LoginWindow", "\347\231\273\351\231\206", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'newuserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERWINDOW_H
#define UI_NEWUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUserWindow
{
public:
    QPushButton *backButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *repasswordEdit;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *phoneEdit;
    QLineEdit *mailEdit;
    QLabel *label_6;
    QLineEdit *nicknameEdit;
    QPushButton *submitButton;
    QLabel *warning;

    void setupUi(QWidget *NewUserWindow)
    {
        if (NewUserWindow->objectName().isEmpty())
            NewUserWindow->setObjectName(QString::fromUtf8("NewUserWindow"));
        NewUserWindow->resize(417, 384);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewUserWindow->sizePolicy().hasHeightForWidth());
        NewUserWindow->setSizePolicy(sizePolicy);
        backButton = new QPushButton(NewUserWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(90, 310, 75, 23));
        widget = new QWidget(NewUserWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 20, 301, 251));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setMaxLength(16);

        gridLayout->addWidget(usernameEdit, 0, 1, 1, 1);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setMaxLength(16);

        gridLayout->addWidget(passwordEdit, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        repasswordEdit = new QLineEdit(widget);
        repasswordEdit->setObjectName(QString::fromUtf8("repasswordEdit"));
        repasswordEdit->setMaxLength(16);

        gridLayout->addWidget(repasswordEdit, 2, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        phoneEdit = new QLineEdit(widget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        phoneEdit->setMaxLength(11);

        gridLayout->addWidget(phoneEdit, 3, 1, 1, 1);

        mailEdit = new QLineEdit(widget);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));
        mailEdit->setMaxLength(100);

        gridLayout->addWidget(mailEdit, 4, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        nicknameEdit = new QLineEdit(widget);
        nicknameEdit->setObjectName(QString::fromUtf8("nicknameEdit"));
        nicknameEdit->setMaxLength(24);

        gridLayout->addWidget(nicknameEdit, 5, 1, 1, 1);

        submitButton = new QPushButton(NewUserWindow);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(230, 310, 75, 23));
        warning = new QLabel(NewUserWindow);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(130, 280, 141, 16));

        retranslateUi(NewUserWindow);

        QMetaObject::connectSlotsByName(NewUserWindow);
    } // setupUi

    void retranslateUi(QWidget *NewUserWindow)
    {
        NewUserWindow->setWindowTitle(QApplication::translate("NewUserWindow", "\346\263\250\345\206\214", nullptr));
        backButton->setText(QApplication::translate("NewUserWindow", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QApplication::translate("NewUserWindow", "\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        label_5->setText(QApplication::translate("NewUserWindow", "\351\202\256\347\256\261", nullptr));
        label_2->setText(QApplication::translate("NewUserWindow", "\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("NewUserWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QApplication::translate("NewUserWindow", "\346\211\213\346\234\272", nullptr));
        label_6->setText(QApplication::translate("NewUserWindow", "\346\230\265\347\247\260", nullptr));
        submitButton->setText(QApplication::translate("NewUserWindow", "\346\217\220\344\272\244", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewUserWindow: public Ui_NewUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERWINDOW_H

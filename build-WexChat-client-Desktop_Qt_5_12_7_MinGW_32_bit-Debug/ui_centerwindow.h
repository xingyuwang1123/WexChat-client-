/********************************************************************************
** Form generated from reading UI file 'centerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERWINDOW_H
#define UI_CENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CenterWindow
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *centerButton;
    QPushButton *swapButton;
    QPushButton *aboutButton;
    QPushButton *backButton;
    QPushButton *quitButton;

    void setupUi(QWidget *CenterWindow)
    {
        if (CenterWindow->objectName().isEmpty())
            CenterWindow->setObjectName(QString::fromUtf8("CenterWindow"));
        CenterWindow->resize(800, 534);
        frame = new QFrame(CenterWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(200, 1, 399, 533));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 60, 60));
        centerButton = new QPushButton(frame);
        centerButton->setObjectName(QString::fromUtf8("centerButton"));
        centerButton->setGeometry(QRect(0, 130, 398, 41));
        centerButton->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        centerButton->setAutoDefault(false);
        centerButton->setFlat(true);
        swapButton = new QPushButton(frame);
        swapButton->setObjectName(QString::fromUtf8("swapButton"));
        swapButton->setGeometry(QRect(0, 170, 398, 41));
        swapButton->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        swapButton->setAutoDefault(false);
        swapButton->setFlat(true);
        aboutButton = new QPushButton(frame);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(0, 210, 398, 41));
        aboutButton->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        aboutButton->setAutoDefault(false);
        aboutButton->setFlat(true);
        backButton = new QPushButton(frame);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(0, 250, 398, 41));
        backButton->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        backButton->setAutoDefault(false);
        backButton->setFlat(true);
        quitButton = new QPushButton(frame);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(0, 290, 398, 41));
        quitButton->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        quitButton->setAutoDefault(false);
        quitButton->setFlat(true);

        retranslateUi(CenterWindow);

        centerButton->setDefault(false);
        swapButton->setDefault(false);
        aboutButton->setDefault(false);
        backButton->setDefault(false);
        quitButton->setDefault(false);


        QMetaObject::connectSlotsByName(CenterWindow);
    } // setupUi

    void retranslateUi(QWidget *CenterWindow)
    {
        CenterWindow->setWindowTitle(QApplication::translate("CenterWindow", "Form", nullptr));
        label->setText(QString());
        centerButton->setText(QApplication::translate("CenterWindow", "\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        swapButton->setText(QApplication::translate("CenterWindow", "\346\270\205\347\220\206\347\274\223\345\255\230", nullptr));
        aboutButton->setText(QApplication::translate("CenterWindow", "\345\205\263\344\272\216", nullptr));
        backButton->setText(QApplication::translate("CenterWindow", "\345\217\215\351\246\210", nullptr));
        quitButton->setText(QApplication::translate("CenterWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CenterWindow: public Ui_CenterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'addgroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPDIALOG_H
#define UI_ADDGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGroupDialog
{
public:
    QFrame *friendInfoFrame;
    QLabel *headerlabel;
    QPushButton *submitButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *nameEdit_2;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QPlainTextEdit *introEdit;
    QPushButton *headerButton;

    void setupUi(QDialog *AddGroupDialog)
    {
        if (AddGroupDialog->objectName().isEmpty())
            AddGroupDialog->setObjectName(QString::fromUtf8("AddGroupDialog"));
        AddGroupDialog->resize(371, 441);
        friendInfoFrame = new QFrame(AddGroupDialog);
        friendInfoFrame->setObjectName(QString::fromUtf8("friendInfoFrame"));
        friendInfoFrame->setGeometry(QRect(0, 0, 371, 441));
        friendInfoFrame->setFrameShape(QFrame::Panel);
        friendInfoFrame->setFrameShadow(QFrame::Raised);
        headerlabel = new QLabel(friendInfoFrame);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(140, 20, 71, 61));
        headerlabel->setPixmap(QPixmap(QString::fromUtf8(":/img/center.svg")));
        headerlabel->setScaledContents(true);
        submitButton = new QPushButton(friendInfoFrame);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(130, 390, 81, 31));
        scrollArea = new QScrollArea(friendInfoFrame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1, 110, 370, 261));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 259));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        nameEdit_2 = new QLineEdit(widget_3);
        nameEdit_2->setObjectName(QString::fromUtf8("nameEdit_2"));
        nameEdit_2->setEnabled(true);
        nameEdit_2->setMaxLength(16);

        horizontalLayout_3->addWidget(nameEdit_2);


        verticalLayout->addWidget(widget_3);

        widget_10 = new QWidget(scrollAreaWidgetContents);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout->addWidget(widget_10);

        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        introEdit = new QPlainTextEdit(widget_9);
        introEdit->setObjectName(QString::fromUtf8("introEdit"));

        horizontalLayout_8->addWidget(introEdit);


        verticalLayout->addWidget(widget_9);

        scrollArea->setWidget(scrollAreaWidgetContents);
        headerButton = new QPushButton(friendInfoFrame);
        headerButton->setObjectName(QString::fromUtf8("headerButton"));
        headerButton->setGeometry(QRect(230, 60, 75, 23));

        retranslateUi(AddGroupDialog);

        QMetaObject::connectSlotsByName(AddGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupDialog)
    {
        AddGroupDialog->setWindowTitle(QApplication::translate("AddGroupDialog", "Dialog", nullptr));
        headerlabel->setText(QString());
        submitButton->setText(QApplication::translate("AddGroupDialog", "\346\217\220\344\272\244", nullptr));
        label_3->setText(QApplication::translate("AddGroupDialog", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("AddGroupDialog", "\347\256\200\344\273\213\357\274\232", nullptr));
        headerButton->setText(QApplication::translate("AddGroupDialog", "\344\270\212\344\274\240\345\244\264\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroupDialog: public Ui_AddGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPDIALOG_H

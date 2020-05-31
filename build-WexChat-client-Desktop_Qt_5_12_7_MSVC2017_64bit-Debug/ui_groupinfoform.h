/********************************************************************************
** Form generated from reading UI file 'groupinfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPINFOFORM_H
#define UI_GROUPINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupInfoForm
{
public:
    QFrame *friendInfoFrame;
    QLabel *headerlabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *uidEdit;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QTextBrowser *textBrowser;
    QWidget *applywidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *submitButton;

    void setupUi(QWidget *GroupInfoForm)
    {
        if (GroupInfoForm->objectName().isEmpty())
            GroupInfoForm->setObjectName(QString::fromUtf8("GroupInfoForm"));
        GroupInfoForm->resize(370, 542);
        friendInfoFrame = new QFrame(GroupInfoForm);
        friendInfoFrame->setObjectName(QString::fromUtf8("friendInfoFrame"));
        friendInfoFrame->setGeometry(QRect(0, 0, 371, 461));
        friendInfoFrame->setFrameShape(QFrame::Panel);
        friendInfoFrame->setFrameShadow(QFrame::Raised);
        headerlabel = new QLabel(friendInfoFrame);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(140, 20, 71, 61));
        headerlabel->setPixmap(QPixmap(QString::fromUtf8(":/img/center.svg")));
        headerlabel->setScaledContents(true);
        scrollArea = new QScrollArea(friendInfoFrame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1, 110, 370, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 349));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nameEdit = new QLineEdit(widget_3);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(false);

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addWidget(widget_3);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        uidEdit = new QLineEdit(widget_8);
        uidEdit->setObjectName(QString::fromUtf8("uidEdit"));
        uidEdit->setEnabled(false);

        horizontalLayout_7->addWidget(uidEdit);


        verticalLayout->addWidget(widget_8);

        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        textBrowser = new QTextBrowser(widget_9);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(false);

        horizontalLayout_8->addWidget(textBrowser);


        verticalLayout->addWidget(widget_9);

        applywidget = new QWidget(scrollAreaWidgetContents);
        applywidget->setObjectName(QString::fromUtf8("applywidget"));
        horizontalLayout_3 = new QHBoxLayout(applywidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(applywidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        plainTextEdit = new QPlainTextEdit(applywidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_3->addWidget(plainTextEdit);


        verticalLayout->addWidget(applywidget);

        scrollArea->setWidget(scrollAreaWidgetContents);
        submitButton = new QPushButton(GroupInfoForm);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(110, 480, 121, 41));

        retranslateUi(GroupInfoForm);

        QMetaObject::connectSlotsByName(GroupInfoForm);
    } // setupUi

    void retranslateUi(QWidget *GroupInfoForm)
    {
        GroupInfoForm->setWindowTitle(QApplication::translate("GroupInfoForm", "Form", nullptr));
        headerlabel->setText(QString());
        label_2->setText(QApplication::translate("GroupInfoForm", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("GroupInfoForm", "id\357\274\232", nullptr));
        label_8->setText(QApplication::translate("GroupInfoForm", "\347\256\200\344\273\213\357\274\232", nullptr));
        label_3->setText(QApplication::translate("GroupInfoForm", "\347\224\263\350\257\267\344\277\241\346\201\257\357\274\232", nullptr));
        submitButton->setText(QApplication::translate("GroupInfoForm", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupInfoForm: public Ui_GroupInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPINFOFORM_H

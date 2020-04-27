/********************************************************************************
** Form generated from reading UI file 'groupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPWINDOW_H
#define UI_GROUPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupWindow
{
public:
    QFrame *frame_2;
    QFrame *groupInfoFrame;
    QLabel *headerlabel;
    QPushButton *deleteFriButton;
    QPushButton *messageButton;
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
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *menberButton;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QTextBrowser *textBrowser;
    QPushButton *addButton;
    QPushButton *createButton;
    QFrame *mgroupinfoframe;
    QLabel *headerlabel_2;
    QPushButton *deleteFriButton_2;
    QPushButton *messageButton_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *nameEdit_2;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *uidEdit_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *menberButton_2;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QPlainTextEdit *plainTextEdit;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *newButton;
    QPushButton *deleteFriButton_3;
    QListWidget *listWidget;

    void setupUi(QWidget *GroupWindow)
    {
        if (GroupWindow->objectName().isEmpty())
            GroupWindow->setObjectName(QString::fromUtf8("GroupWindow"));
        GroupWindow->resize(800, 534);
        frame_2 = new QFrame(GroupWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(230, 0, 571, 541));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupInfoFrame = new QFrame(frame_2);
        groupInfoFrame->setObjectName(QString::fromUtf8("groupInfoFrame"));
        groupInfoFrame->setGeometry(QRect(120, 0, 371, 541));
        groupInfoFrame->setFrameShape(QFrame::Panel);
        groupInfoFrame->setFrameShadow(QFrame::Raised);
        headerlabel = new QLabel(groupInfoFrame);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(140, 20, 71, 61));
        headerlabel->setPixmap(QPixmap(QString::fromUtf8(":/img/center.svg")));
        headerlabel->setScaledContents(true);
        deleteFriButton = new QPushButton(groupInfoFrame);
        deleteFriButton->setObjectName(QString::fromUtf8("deleteFriButton"));
        deleteFriButton->setGeometry(QRect(20, 492, 91, 31));
        messageButton = new QPushButton(groupInfoFrame);
        messageButton->setObjectName(QString::fromUtf8("messageButton"));
        messageButton->setGeometry(QRect(260, 492, 81, 31));
        scrollArea = new QScrollArea(groupInfoFrame);
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

        widget_10 = new QWidget(scrollAreaWidgetContents);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        menberButton = new QPushButton(widget_10);
        menberButton->setObjectName(QString::fromUtf8("menberButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/triangle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menberButton->setIcon(icon);
        menberButton->setAutoDefault(false);
        menberButton->setFlat(false);

        horizontalLayout_9->addWidget(menberButton);


        verticalLayout->addWidget(widget_10);

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

        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(frame_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 480, 51, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);
        addButton->setIconSize(QSize(32, 32));
        addButton->setFlat(true);
        createButton = new QPushButton(frame_2);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(10, 420, 51, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/createg.svg"), QSize(), QIcon::Normal, QIcon::Off);
        createButton->setIcon(icon2);
        createButton->setIconSize(QSize(32, 32));
        createButton->setFlat(true);
        mgroupinfoframe = new QFrame(frame_2);
        mgroupinfoframe->setObjectName(QString::fromUtf8("mgroupinfoframe"));
        mgroupinfoframe->setGeometry(QRect(120, 0, 371, 541));
        mgroupinfoframe->setFrameShape(QFrame::Panel);
        mgroupinfoframe->setFrameShadow(QFrame::Raised);
        headerlabel_2 = new QLabel(mgroupinfoframe);
        headerlabel_2->setObjectName(QString::fromUtf8("headerlabel_2"));
        headerlabel_2->setGeometry(QRect(140, 20, 71, 61));
        headerlabel_2->setPixmap(QPixmap(QString::fromUtf8(":/img/center.svg")));
        headerlabel_2->setScaledContents(true);
        deleteFriButton_2 = new QPushButton(mgroupinfoframe);
        deleteFriButton_2->setObjectName(QString::fromUtf8("deleteFriButton_2"));
        deleteFriButton_2->setGeometry(QRect(20, 492, 91, 31));
        messageButton_2 = new QPushButton(mgroupinfoframe);
        messageButton_2->setObjectName(QString::fromUtf8("messageButton_2"));
        messageButton_2->setGeometry(QRect(260, 492, 81, 31));
        scrollArea_2 = new QScrollArea(mgroupinfoframe);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(1, 110, 370, 351));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 368, 349));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(scrollAreaWidgetContents_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        nameEdit_2 = new QLineEdit(widget_4);
        nameEdit_2->setObjectName(QString::fromUtf8("nameEdit_2"));
        nameEdit_2->setEnabled(false);

        horizontalLayout_3->addWidget(nameEdit_2);


        verticalLayout_2->addWidget(widget_4);

        widget_11 = new QWidget(scrollAreaWidgetContents_2);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_10 = new QHBoxLayout(widget_11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(widget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        uidEdit_2 = new QLineEdit(widget_11);
        uidEdit_2->setObjectName(QString::fromUtf8("uidEdit_2"));
        uidEdit_2->setEnabled(false);

        horizontalLayout_10->addWidget(uidEdit_2);


        verticalLayout_2->addWidget(widget_11);

        widget_12 = new QWidget(scrollAreaWidgetContents_2);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_11 = new QHBoxLayout(widget_12);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        menberButton_2 = new QPushButton(widget_12);
        menberButton_2->setObjectName(QString::fromUtf8("menberButton_2"));
        menberButton_2->setIcon(icon);
        menberButton_2->setAutoDefault(false);
        menberButton_2->setFlat(false);

        horizontalLayout_11->addWidget(menberButton_2);


        verticalLayout_2->addWidget(widget_12);

        widget_13 = new QWidget(scrollAreaWidgetContents_2);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_12 = new QHBoxLayout(widget_13);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(widget_13);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        plainTextEdit = new QPlainTextEdit(widget_13);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(false);

        horizontalLayout_12->addWidget(plainTextEdit);


        verticalLayout_2->addWidget(widget_13);

        widget_14 = new QWidget(scrollAreaWidgetContents_2);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_13 = new QHBoxLayout(widget_14);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        newButton = new QPushButton(widget_14);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        newButton->setIcon(icon);
        newButton->setAutoDefault(false);
        newButton->setFlat(false);

        horizontalLayout_13->addWidget(newButton);


        verticalLayout_2->addWidget(widget_14);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        deleteFriButton_3 = new QPushButton(mgroupinfoframe);
        deleteFriButton_3->setObjectName(QString::fromUtf8("deleteFriButton_3"));
        deleteFriButton_3->setGeometry(QRect(140, 490, 91, 31));
        listWidget = new QListWidget(GroupWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 231, 541));

        retranslateUi(GroupWindow);

        QMetaObject::connectSlotsByName(GroupWindow);
    } // setupUi

    void retranslateUi(QWidget *GroupWindow)
    {
        GroupWindow->setWindowTitle(QApplication::translate("GroupWindow", "Form", nullptr));
        headerlabel->setText(QString());
        deleteFriButton->setText(QApplication::translate("GroupWindow", "\351\200\200\345\207\272", nullptr));
        messageButton->setText(QApplication::translate("GroupWindow", "\345\217\221\346\266\210\346\201\257", nullptr));
        label_2->setText(QApplication::translate("GroupWindow", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("GroupWindow", "id\357\274\232", nullptr));
        menberButton->setText(QApplication::translate("GroupWindow", "\346\210\220\345\221\230\345\210\227\350\241\250", nullptr));
        label_8->setText(QApplication::translate("GroupWindow", "\347\256\200\344\273\213\357\274\232", nullptr));
        addButton->setText(QString());
        createButton->setText(QString());
        headerlabel_2->setText(QString());
        deleteFriButton_2->setText(QApplication::translate("GroupWindow", "\350\247\243\346\225\243\350\257\245\347\276\244", nullptr));
        messageButton_2->setText(QApplication::translate("GroupWindow", "\345\217\221\346\266\210\346\201\257", nullptr));
        label_3->setText(QApplication::translate("GroupWindow", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_9->setText(QApplication::translate("GroupWindow", "id\357\274\232", nullptr));
        menberButton_2->setText(QApplication::translate("GroupWindow", "\346\210\220\345\221\230\345\210\227\350\241\250", nullptr));
        label_10->setText(QApplication::translate("GroupWindow", "\347\256\200\344\273\213\357\274\232", nullptr));
        newButton->setText(QApplication::translate("GroupWindow", "\346\226\260\346\210\220\345\221\230\347\224\263\350\257\267", nullptr));
        deleteFriButton_3->setText(QApplication::translate("GroupWindow", "\347\274\226\350\276\221\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupWindow: public Ui_GroupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPWINDOW_H

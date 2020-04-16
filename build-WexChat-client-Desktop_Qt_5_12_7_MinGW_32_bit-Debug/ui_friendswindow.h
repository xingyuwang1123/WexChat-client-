/********************************************************************************
** Form generated from reading UI file 'friendswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSWINDOW_H
#define UI_FRIENDSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendsWindow
{
public:
    QFrame *frame;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *friendsButton;
    QPushButton *groupButton;
    QTreeWidget *treeWidget;
    QFrame *frame_2;
    QFrame *friendInfoFrame;
    QLabel *headerlabel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nicknameEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *birthtimeEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *mailEdit;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *usernameEdit;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *uidEdit;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLineEdit *provinceEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *cityEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_11;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *noteEdit;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QTextBrowser *introBrowser;
    QPushButton *addButton;

    void setupUi(QWidget *FriendsWindow)
    {
        if (FriendsWindow->objectName().isEmpty())
            FriendsWindow->setObjectName(QString::fromUtf8("FriendsWindow"));
        FriendsWindow->resize(800, 534);
        frame = new QFrame(FriendsWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, 0, 231, 541));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, -1, 231, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        friendsButton = new QPushButton(widget);
        friendsButton->setObjectName(QString::fromUtf8("friendsButton"));
        friendsButton->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout->addWidget(friendsButton);

        groupButton = new QPushButton(widget);
        groupButton->setObjectName(QString::fromUtf8("groupButton"));

        horizontalLayout->addWidget(groupButton);

        treeWidget = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 40, 231, 501));
        treeWidget->setColumnCount(1);
        frame_2 = new QFrame(FriendsWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(229, -1, 571, 541));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        friendInfoFrame = new QFrame(frame_2);
        friendInfoFrame->setObjectName(QString::fromUtf8("friendInfoFrame"));
        friendInfoFrame->setGeometry(QRect(120, 0, 371, 541));
        friendInfoFrame->setFrameShape(QFrame::Panel);
        friendInfoFrame->setFrameShadow(QFrame::Raised);
        headerlabel = new QLabel(friendInfoFrame);
        headerlabel->setObjectName(QString::fromUtf8("headerlabel"));
        headerlabel->setGeometry(QRect(140, 20, 71, 61));
        pushButton = new QPushButton(friendInfoFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 492, 91, 31));
        pushButton_2 = new QPushButton(friendInfoFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 492, 81, 31));
        scrollArea = new QScrollArea(friendInfoFrame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1, 110, 371, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 352, 415));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nicknameEdit = new QLineEdit(widget_3);
        nicknameEdit->setObjectName(QString::fromUtf8("nicknameEdit"));
        nicknameEdit->setEnabled(false);

        horizontalLayout_2->addWidget(nicknameEdit);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        birthtimeEdit = new QDateEdit(widget_4);
        birthtimeEdit->setObjectName(QString::fromUtf8("birthtimeEdit"));
        birthtimeEdit->setEnabled(false);

        horizontalLayout_3->addWidget(birthtimeEdit);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        mailEdit = new QLineEdit(widget_5);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));
        mailEdit->setEnabled(false);

        horizontalLayout_4->addWidget(mailEdit);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        usernameEdit = new QLineEdit(widget_6);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setEnabled(false);

        horizontalLayout_5->addWidget(usernameEdit);


        verticalLayout->addWidget(widget_6);

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

        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        provinceEdit = new QLineEdit(widget_7);
        provinceEdit->setObjectName(QString::fromUtf8("provinceEdit"));
        provinceEdit->setEnabled(false);

        horizontalLayout_6->addWidget(provinceEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        cityEdit = new QLineEdit(widget_7);
        cityEdit->setObjectName(QString::fromUtf8("cityEdit"));
        cityEdit->setEnabled(false);

        horizontalLayout_6->addWidget(cityEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);


        verticalLayout->addWidget(widget_7);

        widget_10 = new QWidget(scrollAreaWidgetContents);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(widget_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        noteEdit = new QLineEdit(widget_10);
        noteEdit->setObjectName(QString::fromUtf8("noteEdit"));
        noteEdit->setEnabled(false);

        horizontalLayout_9->addWidget(noteEdit);


        verticalLayout->addWidget(widget_10);

        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        introBrowser = new QTextBrowser(widget_9);
        introBrowser->setObjectName(QString::fromUtf8("introBrowser"));
        introBrowser->setEnabled(false);

        horizontalLayout_8->addWidget(introBrowser);


        verticalLayout->addWidget(widget_9);

        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(frame_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 480, 51, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 32));
        addButton->setFlat(true);

        retranslateUi(FriendsWindow);

        QMetaObject::connectSlotsByName(FriendsWindow);
    } // setupUi

    void retranslateUi(QWidget *FriendsWindow)
    {
        FriendsWindow->setWindowTitle(QApplication::translate("FriendsWindow", "Form", nullptr));
        friendsButton->setText(QApplication::translate("FriendsWindow", "\345\245\275\345\217\213", nullptr));
        groupButton->setText(QApplication::translate("FriendsWindow", "\347\276\244", nullptr));
        headerlabel->setText(QString());
        pushButton->setText(QApplication::translate("FriendsWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_2->setText(QApplication::translate("FriendsWindow", "\345\217\221\346\266\210\346\201\257", nullptr));
        label_2->setText(QApplication::translate("FriendsWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("FriendsWindow", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_4->setText(QApplication::translate("FriendsWindow", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_5->setText(QApplication::translate("FriendsWindow", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_7->setText(QApplication::translate("FriendsWindow", "uid\357\274\232", nullptr));
        label_6->setText(QApplication::translate("FriendsWindow", "\345\234\260\347\202\271\357\274\232", nullptr));
        label_10->setText(QApplication::translate("FriendsWindow", "\347\234\201", nullptr));
        label_11->setText(QApplication::translate("FriendsWindow", "\345\270\202", nullptr));
        label_9->setText(QApplication::translate("FriendsWindow", "\345\244\207\346\263\250\357\274\232", nullptr));
        label_8->setText(QApplication::translate("FriendsWindow", "\347\256\200\344\273\213\357\274\232", nullptr));
        addButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendsWindow: public Ui_FriendsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSWINDOW_H

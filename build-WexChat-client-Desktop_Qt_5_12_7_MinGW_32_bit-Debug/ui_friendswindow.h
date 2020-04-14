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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
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
    QPushButton *addButton;
    QFrame *frame_2;

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
        treeWidget->setGeometry(QRect(0, 40, 231, 431));
        treeWidget->setColumnCount(1);
        addButton = new QPushButton(frame);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(180, 480, 51, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 32));
        addButton->setFlat(true);
        frame_2 = new QFrame(FriendsWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(229, -1, 571, 541));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);

        retranslateUi(FriendsWindow);

        QMetaObject::connectSlotsByName(FriendsWindow);
    } // setupUi

    void retranslateUi(QWidget *FriendsWindow)
    {
        FriendsWindow->setWindowTitle(QApplication::translate("FriendsWindow", "Form", nullptr));
        friendsButton->setText(QApplication::translate("FriendsWindow", "\345\245\275\345\217\213", nullptr));
        groupButton->setText(QApplication::translate("FriendsWindow", "\347\276\244", nullptr));
        addButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendsWindow: public Ui_FriendsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSWINDOW_H

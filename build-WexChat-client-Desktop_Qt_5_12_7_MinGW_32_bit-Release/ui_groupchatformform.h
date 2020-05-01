/********************************************************************************
** Form generated from reading UI file 'groupchatformform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATFORMFORM_H
#define UI_GROUPCHATFORMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <messageshowform.h>

QT_BEGIN_NAMESPACE

class Ui_GroupChatFormForm
{
public:
    QFrame *topframe;
    QLabel *namelabel;
    QFrame *frame_2;
    QFrame *frame_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *sendButton;
    MessageShowForm *showwidget;

    void setupUi(QWidget *GroupChatFormForm)
    {
        if (GroupChatFormForm->objectName().isEmpty())
            GroupChatFormForm->setObjectName(QString::fromUtf8("GroupChatFormForm"));
        GroupChatFormForm->resize(583, 542);
        topframe = new QFrame(GroupChatFormForm);
        topframe->setObjectName(QString::fromUtf8("topframe"));
        topframe->setGeometry(QRect(0, 0, 581, 41));
        topframe->setFrameShape(QFrame::Panel);
        topframe->setFrameShadow(QFrame::Raised);
        namelabel = new QLabel(topframe);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(13, 11, 81, 21));
        frame_2 = new QFrame(GroupChatFormForm);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 401, 581, 141));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(-1, -1, 581, 31));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 30, 581, 101));
        sendButton = new QPushButton(frame_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(494, 102, 81, 31));
        showwidget = new MessageShowForm(GroupChatFormForm);
        showwidget->setObjectName(QString::fromUtf8("showwidget"));
        showwidget->setGeometry(QRect(-1, 39, 581, 361));

        retranslateUi(GroupChatFormForm);

        QMetaObject::connectSlotsByName(GroupChatFormForm);
    } // setupUi

    void retranslateUi(QWidget *GroupChatFormForm)
    {
        GroupChatFormForm->setWindowTitle(QApplication::translate("GroupChatFormForm", "Form", nullptr));
        namelabel->setText(QString());
        sendButton->setText(QApplication::translate("GroupChatFormForm", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatFormForm: public Ui_GroupChatFormForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATFORMFORM_H

/********************************************************************************
** Form generated from reading UI file 'messagechatform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGECHATFORM_H
#define UI_MESSAGECHATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageChatForm
{
public:
    QFrame *frame;
    QLabel *namelabel;
    QFrame *frame_2;
    QFrame *frame_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *MessageChatForm)
    {
        if (MessageChatForm->objectName().isEmpty())
            MessageChatForm->setObjectName(QString::fromUtf8("MessageChatForm"));
        MessageChatForm->resize(579, 534);
        frame = new QFrame(MessageChatForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, -1, 581, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        namelabel = new QLabel(frame);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(13, 11, 81, 21));
        frame_2 = new QFrame(MessageChatForm);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 400, 581, 141));
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
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(494, 102, 81, 31));

        retranslateUi(MessageChatForm);

        QMetaObject::connectSlotsByName(MessageChatForm);
    } // setupUi

    void retranslateUi(QWidget *MessageChatForm)
    {
        MessageChatForm->setWindowTitle(QApplication::translate("MessageChatForm", "Form", nullptr));
        namelabel->setText(QString());
        pushButton->setText(QApplication::translate("MessageChatForm", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageChatForm: public Ui_MessageChatForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGECHATFORM_H

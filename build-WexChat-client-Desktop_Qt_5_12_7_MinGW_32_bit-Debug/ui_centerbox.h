/********************************************************************************
** Form generated from reading UI file 'centerbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERBOX_H
#define UI_CENTERBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_CenterBox
{
public:
    QFrame *frame;
    QLabel *headerLabel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *nicknameEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *mailEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *usernameEdit;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *uidEdit;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *provinceComboBox;
    QLabel *label_8;
    QComboBox *cityComboBox;
    QLabel *label_9;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *beizhuEdit;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QWidget *widget;

    void setupUi(QWidget *CenterBox)
    {
        if (CenterBox->objectName().isEmpty())
            CenterBox->setObjectName(QString::fromUtf8("CenterBox"));
        CenterBox->resize(399, 533);
        frame = new QFrame(CenterBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -1, 401, 541));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        headerLabel = new QLabel(frame);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        headerLabel->setGeometry(QRect(160, 30, 55, 55));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 450, 75, 23));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 450, 75, 23));
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 110, 341, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -106, 322, 415));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        nicknameEdit = new QLineEdit(widget_2);
        nicknameEdit->setObjectName(QString::fromUtf8("nicknameEdit"));
        nicknameEdit->setEnabled(false);

        horizontalLayout->addWidget(nicknameEdit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateEdit = new QDateEdit(widget_3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setEnabled(false);

        horizontalLayout_2->addWidget(dateEdit);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        mailEdit = new QLineEdit(widget_4);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));
        mailEdit->setEnabled(false);

        horizontalLayout_3->addWidget(mailEdit);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        usernameEdit = new QLineEdit(widget_5);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setEnabled(false);

        horizontalLayout_4->addWidget(usernameEdit);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        uidEdit = new QLineEdit(widget_6);
        uidEdit->setObjectName(QString::fromUtf8("uidEdit"));
        uidEdit->setEnabled(false);

        horizontalLayout_5->addWidget(uidEdit);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        provinceComboBox = new QComboBox(widget_7);
        provinceComboBox->setObjectName(QString::fromUtf8("provinceComboBox"));
        provinceComboBox->setEnabled(false);
        provinceComboBox->setEditable(false);

        horizontalLayout_6->addWidget(provinceComboBox);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        cityComboBox = new QComboBox(widget_7);
        cityComboBox->setObjectName(QString::fromUtf8("cityComboBox"));
        cityComboBox->setEnabled(false);

        horizontalLayout_6->addWidget(cityComboBox);

        label_9 = new QLabel(widget_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);


        verticalLayout->addWidget(widget_7);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        beizhuEdit = new QLineEdit(widget_8);
        beizhuEdit->setObjectName(QString::fromUtf8("beizhuEdit"));
        beizhuEdit->setEnabled(false);

        horizontalLayout_7->addWidget(beizhuEdit);


        verticalLayout->addWidget(widget_8);

        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(widget_9);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        plainTextEdit = new QPlainTextEdit(widget_9);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(false);

        horizontalLayout_8->addWidget(plainTextEdit);


        verticalLayout->addWidget(widget_9);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 470, 120, 80));

        retranslateUi(CenterBox);

        QMetaObject::connectSlotsByName(CenterBox);
    } // setupUi

    void retranslateUi(QWidget *CenterBox)
    {
        CenterBox->setWindowTitle(QApplication::translate("CenterBox", "Form", nullptr));
        headerLabel->setText(QString());
        pushButton->setText(QApplication::translate("CenterBox", "\350\277\224\345\233\236", nullptr));
        pushButton_2->setText(QApplication::translate("CenterBox", "\347\274\226\350\276\221", nullptr));
        label_2->setText(QApplication::translate("CenterBox", "\346\230\265\347\247\260", nullptr));
        label_3->setText(QApplication::translate("CenterBox", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        label_4->setText(QApplication::translate("CenterBox", "\351\202\256\347\256\261", nullptr));
        label_5->setText(QApplication::translate("CenterBox", "\350\264\246\345\217\267", nullptr));
        label_6->setText(QApplication::translate("CenterBox", "uid", nullptr));
        label_7->setText(QApplication::translate("CenterBox", "\345\234\260\347\202\271", nullptr));
        label_8->setText(QApplication::translate("CenterBox", "\347\234\201", nullptr));
        label_9->setText(QApplication::translate("CenterBox", "\345\270\202", nullptr));
        label_10->setText(QApplication::translate("CenterBox", "\345\244\207\346\263\250", nullptr));
        label->setText(QApplication::translate("CenterBox", "\347\256\200\344\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CenterBox: public Ui_CenterBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERBOX_H

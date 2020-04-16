/********************************************************************************
** Form generated from reading UI file 'addcutindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUTINDIALOG_H
#define UI_ADDCUTINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCutinDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;

    void setupUi(QDialog *AddCutinDialog)
    {
        if (AddCutinDialog->objectName().isEmpty())
            AddCutinDialog->setObjectName(QString::fromUtf8("AddCutinDialog"));
        AddCutinDialog->resize(320, 126);
        buttonBox = new QDialogButtonBox(AddCutinDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 70, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(AddCutinDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 20, 223, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMaxLength(16);

        horizontalLayout->addWidget(nameEdit);


        retranslateUi(AddCutinDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddCutinDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddCutinDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddCutinDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCutinDialog)
    {
        AddCutinDialog->setWindowTitle(QApplication::translate("AddCutinDialog", "\346\267\273\345\212\240\345\210\206\347\273\204", nullptr));
        label->setText(QApplication::translate("AddCutinDialog", "\350\276\223\345\205\245\345\210\206\347\273\204\345\220\215:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCutinDialog: public Ui_AddCutinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUTINDIALOG_H

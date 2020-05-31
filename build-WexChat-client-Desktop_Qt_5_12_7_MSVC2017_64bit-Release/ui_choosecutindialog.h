/********************************************************************************
** Form generated from reading UI file 'choosecutindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECUTINDIALOG_H
#define UI_CHOOSECUTINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseCutinDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChooseCutinDialog)
    {
        if (ChooseCutinDialog->objectName().isEmpty())
            ChooseCutinDialog->setObjectName(QString::fromUtf8("ChooseCutinDialog"));
        ChooseCutinDialog->resize(316, 111);
        verticalLayout = new QVBoxLayout(ChooseCutinDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(ChooseCutinDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(ChooseCutinDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChooseCutinDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChooseCutinDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChooseCutinDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChooseCutinDialog);
    } // setupUi

    void retranslateUi(QDialog *ChooseCutinDialog)
    {
        ChooseCutinDialog->setWindowTitle(QApplication::translate("ChooseCutinDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ChooseCutinDialog", "\351\200\211\346\213\251\345\210\206\347\273\204\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseCutinDialog: public Ui_ChooseCutinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECUTINDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'viedodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEDODIALOG_H
#define UI_VIEDODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ViedoDialog
{
public:

    void setupUi(QDialog *ViedoDialog)
    {
        if (ViedoDialog->objectName().isEmpty())
            ViedoDialog->setObjectName(QString::fromUtf8("ViedoDialog"));
        ViedoDialog->resize(643, 420);

        retranslateUi(ViedoDialog);

        QMetaObject::connectSlotsByName(ViedoDialog);
    } // setupUi

    void retranslateUi(QDialog *ViedoDialog)
    {
        ViedoDialog->setWindowTitle(QApplication::translate("ViedoDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViedoDialog: public Ui_ViedoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEDODIALOG_H

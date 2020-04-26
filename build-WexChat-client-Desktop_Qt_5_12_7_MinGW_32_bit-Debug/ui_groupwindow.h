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
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupWindow
{
public:

    void setupUi(QWidget *GroupWindow)
    {
        if (GroupWindow->objectName().isEmpty())
            GroupWindow->setObjectName(QString::fromUtf8("GroupWindow"));
        GroupWindow->resize(800, 534);

        retranslateUi(GroupWindow);

        QMetaObject::connectSlotsByName(GroupWindow);
    } // setupUi

    void retranslateUi(QWidget *GroupWindow)
    {
        GroupWindow->setWindowTitle(QApplication::translate("GroupWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupWindow: public Ui_GroupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPWINDOW_H

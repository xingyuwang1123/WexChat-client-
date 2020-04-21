#ifndef FRIENDSAPPLYDIALOG_H
#define FRIENDSAPPLYDIALOG_H

#include <QDialog>
#include "wexnetwork.h"

namespace Ui {
class FriendsApplyDialog;
}

class FriendsApplyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FriendsApplyDialog(QWidget *parent = nullptr, QStringList list = QStringList());
    ~FriendsApplyDialog();

private:
    Ui::FriendsApplyDialog *ui;
    WexNetwork *network;
    QStringList cutinList;
    void loadItems(QStringList header, QStringList name, QStringList intro, QStringList uid);
};

#endif // FRIENDSAPPLYDIALOG_H

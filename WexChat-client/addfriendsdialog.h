#ifndef ADDFRIENDSDIALOG_H
#define ADDFRIENDSDIALOG_H

#include <QDialog>
#include "wexnetwork.h"
#include "friendapplyform.h"

namespace Ui {
class AddFriendsDialog;
}

class AddFriendsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriendsDialog(QWidget *parent = nullptr, QMap<QString, QString> uidMap={});
    ~AddFriendsDialog();

private:
    Ui::AddFriendsDialog *ui;
    QMap<QString, QString> uidmap;
    FriendApplyForm *form;
    WexNetwork *network;
    bool isChecking;
    QString applyingUid;
};

#endif // ADDFRIENDSDIALOG_H

#ifndef GROUPMEMBERDIALOG_H
#define GROUPMEMBERDIALOG_H

#include <QDialog>
#include "wexftp.h"
#include "wexnetwork.h"
#include <QListWidgetItem>

namespace Ui {
class GroupMemberDialog;
}

class GroupMemberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupMemberDialog(QWidget *parent = nullptr, QString gid = "");
    ~GroupMemberDialog();

private:
    Ui::GroupMemberDialog *ui;
    WexFtp *ftp;
    WexNetwork *network;
    QMap<QString, QListWidgetItem*> idItemMap;
    int imgCount;
};

#endif // GROUPMEMBERDIALOG_H

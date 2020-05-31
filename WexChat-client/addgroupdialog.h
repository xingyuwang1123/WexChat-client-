#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H
 #pragma execution_character_set("utf-8")
#include <QDialog>
#include "wexftp.h"
#include "wexnetwork.h"

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = nullptr);
    ~AddGroupDialog();

private:
    Ui::AddGroupDialog *ui;
    WexFtp *ftp;
    WexNetwork *network;
    QString uploadFilename;
};

#endif // ADDGROUPDIALOG_H

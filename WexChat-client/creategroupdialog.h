#ifndef CREATEGROUPDIALOG_H
#define CREATEGROUPDIALOG_H

#include <QDialog>
#include "wexnetwork.h"

namespace Ui {
class CreateGroupDialog;
}

class CreateGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroupDialog(QWidget *parent = nullptr);
    ~CreateGroupDialog();

private:
    Ui::CreateGroupDialog *ui;
    WexNetwork *network;
};

#endif // CREATEGROUPDIALOG_H

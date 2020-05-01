#ifndef GROUPAPPLYDIALOG_H
#define GROUPAPPLYDIALOG_H

#include <QDialog>
#include "wexnetwork.h"

namespace Ui {
class GroupApplyDialog;
}

class GroupApplyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupApplyDialog(QWidget *parent = nullptr, QString gid = "");
    ~GroupApplyDialog();

private:
    Ui::GroupApplyDialog *ui;
    WexNetwork *network;
    QString gid;
    void loadData(void);
};

#endif // GROUPAPPLYDIALOG_H

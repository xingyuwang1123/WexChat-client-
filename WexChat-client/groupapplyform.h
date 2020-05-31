#ifndef GROUPAPPLYFORM_H
#define GROUPAPPLYFORM_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "wexftp.h"
#include "wexnetwork.h"

namespace Ui {
class GroupApplyForm;
}

class GroupApplyForm : public QWidget
{
    Q_OBJECT

public:
    explicit GroupApplyForm(QWidget *parent = nullptr, QString name = "", QString header = "", QString uid = "", QString appinfo = "", QString gid = "");
    ~GroupApplyForm();

private:
    Ui::GroupApplyForm *ui;
    QString formuid;
    WexFtp *ftp;
    WexNetwork *network;
};

#endif // GROUPAPPLYFORM_H

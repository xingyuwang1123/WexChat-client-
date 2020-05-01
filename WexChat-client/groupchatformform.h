#ifndef GROUPCHATFORMFORM_H
#define GROUPCHATFORMFORM_H

#include <QWidget>
#include "wexnetwork.h"
#include "wexftp.h"

namespace Ui {
class GroupChatFormForm;
}

class GroupChatFormForm : public QWidget
{
    Q_OBJECT

public:
    explicit GroupChatFormForm(QWidget *parent = nullptr, QString gid = "", QString name = "");
    ~GroupChatFormForm();

private:
    Ui::GroupChatFormForm *ui;
    QString gid;
    WexNetwork *network;
    WexFtp *ftp;
};

#endif // GROUPCHATFORMFORM_H

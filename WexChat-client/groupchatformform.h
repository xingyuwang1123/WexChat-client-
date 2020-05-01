#ifndef GROUPCHATFORMFORM_H
#define GROUPCHATFORMFORM_H

#include <QWidget>
#include "wexnetwork.h"
#include "wexftp.h"

typedef struct {
    QString header;
    QString name;
    QString pass;
}gmember_entity;

namespace Ui {
class GroupChatFormForm;
}

class GroupChatFormForm : public QWidget
{
    Q_OBJECT

public:
    explicit GroupChatFormForm(QWidget *parent = nullptr, QString gid = "", QString name = "");
    void addItem(QString uid, QString text, time_t time);
    ~GroupChatFormForm();

private:
    Ui::GroupChatFormForm *ui;
    QString gid;
    WexNetwork *network;
    WexFtp *ftp;
    int imgCount;
    QMap<QString, gmember_entity> idGmemberMap;
};

#endif // GROUPCHATFORMFORM_H

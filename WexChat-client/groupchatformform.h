#ifndef GROUPCHATFORMFORM_H
#define GROUPCHATFORMFORM_H
 #pragma execution_character_set("utf-8")
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
    void sendMsg(QString msg,  QString pass, QString type);
};

#endif // GROUPCHATFORMFORM_H

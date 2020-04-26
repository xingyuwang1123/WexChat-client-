#ifndef MESSAGECHATFORM_H
#define MESSAGECHATFORM_H

#include <QWidget>
#include "wexnetwork.h"
#include "wexftp.h"

namespace Ui {
class MessageChatForm;
}

class MessageChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit MessageChatForm(QWidget *parent = nullptr, QString uid = "", QString name = "", int type = -1);
    ~MessageChatForm();
    QString uid;
    void addMsg(QString msg, time_t time);
private:
    Ui::MessageChatForm *ui;
    WexNetwork *network;
    WexFtp *ftp;
    QString name;
    QString headerpass;
    int type;
};

#endif // MESSAGECHATFORM_H

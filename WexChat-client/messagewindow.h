#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "messagechatform.h"
#include "groupchatformform.h"
#include "messageitemform.h"
#include "wexnetwork.h"
#include <QMap>

namespace Ui {
class MessageWindow;
}

class MessageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWindow(QWidget *parent = nullptr);
    ~MessageWindow();
    void changeChatForm(QString uid, QString name, bool isGroup);

private:
    Ui::MessageWindow *ui;
    void *chatForm;
    WexNetwork *network;
    QMap<QString, MessageChatForm *> idchatMap;
    QMap<QString, GroupChatFormForm *> idgchatMap;
    void addItem(QString uid, QString type, bool ifcreate);
    QMap<QString, MessageItemForm*> iditemMap;

signals:
    void itemLoadok();
};

#endif // MESSAGEWINDOW_H

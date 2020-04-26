#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QWidget>
#include "messagechatform.h"
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
    void changeChatForm(QString uid, QString name);

private:
    Ui::MessageWindow *ui;
    MessageChatForm *chatForm;
    WexNetwork *network;
    QMap<QString, MessageChatForm *> idchatMap;
    void addItem(QString uid, QString type, bool ifcreate);
    QMap<QString, MessageItemForm*> iditemMap;

signals:
    void itemLoadok();
};

#endif // MESSAGEWINDOW_H

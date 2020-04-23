#ifndef MESSAGECHATFORM_H
#define MESSAGECHATFORM_H

#include <QWidget>
#include "wexnetwork.h"

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
private:
    Ui::MessageChatForm *ui;
    WexNetwork *network;
    QString name;
    int type;
};

#endif // MESSAGECHATFORM_H

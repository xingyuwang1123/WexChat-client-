#include "messagechatform.h"
#include "ui_messagechatform.h"
#include "globle_param.h"

MessageChatForm::MessageChatForm(QWidget *parent, QString uid, QString name, int type) :
    QWidget(parent),
    ui(new Ui::MessageChatForm),
    uid(uid),
    name(name),
    type(type)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    ui->namelabel->setText(name);
    //send
    connect(ui->sendButton, &QPushButton::clicked, this, [=](){
        QString msg = ui->plainTextEdit->toPlainText();

        if (!msg.isEmpty()) {
            QDateTime datetime = QDateTime();
            QJsonObject obj;
            obj.insert("text", msg);
            obj.insert("fromuid", GLOUID);
            obj.insert("area", uid);
            obj.insert("type", type);
            obj.insert("msgtime", (int)datetime.toTime_t());
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "sendmessagetouser");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                //do here
            });
        }
    });
}

MessageChatForm::~MessageChatForm()
{
    delete ui;
}

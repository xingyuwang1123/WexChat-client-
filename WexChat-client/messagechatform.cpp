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
    ftp = WexFtp::get_instance();
    ui->namelabel->setText(name);
    //get header
    network->sendPMessage(uid, "getheadername");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonObject obj = doc.object();
        QString header = obj.value("header").toString();
        if (header != "") {
            ftp->fetchFile(header);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                QStringList list = filename.split('/');
                if (list.last() == header) {
                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    headerpass = filename;
                }
            });
        }
    });

    //send
    connect(ui->sendButton, &QPushButton::clicked, this, [=](){
        QString msg = ui->plainTextEdit->toPlainText();

        if (!msg.isEmpty()) {
            QDateTime datetime = QDateTime();
            //datetime.setTime(QTime::currentTime());
            QJsonObject obj;
            obj.insert("text", msg);
            obj.insert("fromuid", GLOUID);
            obj.insert("area", uid);
            obj.insert("type", type);
            obj.insert("msgtime", (int)time(0));
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "sendmessagetouser");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                //do here
                if (res == "failed") {

                }
            });
            ui->chatForm->addItem(HEADERFILEPASS, MYNAME, msg, time(0));
        }
    });
}

void MessageChatForm::addMsg(QString msg, time_t time) {
    ui->chatForm->addItem(headerpass, name, msg, time);
}

MessageChatForm::~MessageChatForm()
{
    delete ui;
}

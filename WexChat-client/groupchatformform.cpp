#include "groupchatformform.h"
#include "ui_groupchatformform.h"
#include <QDateTime>
#include "globle_param.h"
#include <QJsonObject>


GroupChatFormForm::GroupChatFormForm(QWidget *parent,  QString gid, QString name) :
    QWidget(parent),
    ui(new Ui::GroupChatFormForm),
    gid(gid)
{
    ui->setupUi(this);
    ui->namelabel->setText(name);
    network = WexNetwork::get_instance();
    ftp = WexFtp::get_instance();
    //send message
    connect(ui->sendButton, &QPushButton::clicked, this, [=](){
        QString msg = ui->plainTextEdit->toPlainText();
        ui->plainTextEdit->clear();

        if (!msg.isEmpty()) {
            QDateTime datetime = QDateTime();
            //datetime.setTime(QTime::currentTime());
            QJsonObject obj;
            obj.insert("text", msg);
            obj.insert("fromuid", GLOUID);
            obj.insert("area", gid);
            obj.insert("type", 1);
            obj.insert("msgtime", (int)time(0));
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "sendmessagetouser");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                //do here
                if (res == "failed" || res == "warning") {

                }
            });
        }
    });
}

GroupChatFormForm::~GroupChatFormForm()
{
    delete ui;
}

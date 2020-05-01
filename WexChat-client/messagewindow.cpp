#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "messageitemform.h"
#include "groupchatformform.h"
#include <QGridLayout>

MessageWindow::MessageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    chatForm = nullptr;
    network = WexNetwork::get_instance();
    //load chatform
    //changeChatForm("123", "wang");
    //receive message
    connect(network, &WexNetwork::boardArrive, this, [=](WexNetwork::boardType type, QByteArray data){
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        QString text = obj.value("text").toString();
        long msgtime = obj.value("msgtime").toInt();
        QString fromuid = obj.value("fromuid").toString();
        QString area = obj.value("area").toString();
        int mtype = obj.value("type").toInt();
        if (mtype == 0) {
            if (idchatMap.contains(fromuid)) {
                idchatMap.find(fromuid).value()->addMsg(text, msgtime);
            }
            else {
                //create formfirst
                addItem(fromuid, "user", true);
                connect(this, &MessageWindow::itemLoadok, this, [=](){
                    idchatMap.find(fromuid).value()->addMsg(text, msgtime);
                });
            }
        }
        //ui->chatForm->addItem(headerpass, name, text, msgtime);
    });
}

void MessageWindow::addItem(QString uid, QString type, bool ifcreate) {
    if (type == "user") {
        network->sendPMessage(uid, "getheadername");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString res = network->fetchPMessage();
            disconnect(network, &WexNetwork::dataArrive, this, 0);
            QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
            QJsonObject obj = doc.object();
            QString name = obj.value("name").toString();
            QString header = obj.value("header").toString();
            delete ui->messagescrollArea->widget()->layout();
            QGridLayout *playout = new QGridLayout(this);
            foreach(MessageItemForm *form, iditemMap.values()) {
                playout->addWidget(form);
            }
            MessageItemForm *form2 = new MessageItemForm(this, header, "name", 0, uid);
            //add event
            connect(form2, &MessageItemForm::clicked, this, [=](QString uid){
                changeChatForm(uid, "", false);
            });
            playout->addWidget(form2);
            iditemMap.insert(uid, form2);
            ui->messagescrollArea->widget()->setLayout(playout);
            if (ifcreate == true) {
                MessageChatForm *chatform = new MessageChatForm(this, uid, name, 0);
                chatform->hide();
                idchatMap.insert(uid, chatform);
                emit itemLoadok();
            }
        });
    }
    else if (type == "group") {
        network->sendPMessage(uid, "getgroupinfobyid");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString res = network->fetchPMessage();
            disconnect(network, &WexNetwork::dataArrive, this, 0);
            QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
            QJsonObject obj = doc.object();
            QString name = obj.value("name").toString();
            QString header = obj.value("header").toString();
            delete ui->messagescrollArea->widget()->layout();
            QGridLayout *playout = new QGridLayout(this);
            foreach(MessageItemForm *form, iditemMap.values()) {
                playout->addWidget(form);
            }
            MessageItemForm *form2 = new MessageItemForm(this, header, "name", 0, uid);
            //add event
            //todo
            connect(form2, &MessageItemForm::clicked, this, [=](QString uid){
                changeChatForm(uid, "", true);
            });
            playout->addWidget(form2);
            iditemMap.insert(uid, form2);
            ui->messagescrollArea->widget()->setLayout(playout);
            //todo: create chatform
            if (ifcreate == true) {
                GroupChatFormForm *chatform = new GroupChatFormForm(this, uid, name);
                chatform->hide();
                idgchatMap.insert(uid, chatform);
                emit itemLoadok();
            }
        });
    }
}

void MessageWindow::changeChatForm(QString uid, QString name, bool isGroup) {
    if (isGroup == false) {
        MessageChatForm *chatForm = (MessageChatForm*)this->chatForm;
        if (chatForm != nullptr) {
            chatForm->hide();
            //if (chatForm->uid == uid) return;
        }
        if (idchatMap.contains(uid)) {
            MessageChatForm *form = idchatMap.value(uid);
            form->show();
            form->move(221, 0);
            this->chatForm = form;
        }
        else {
            this->chatForm = new MessageChatForm(this, uid, name, 0);
            MessageChatForm *chatForm = (MessageChatForm*)this->chatForm;
            chatForm->show();
            chatForm->move(221, 0);
            idchatMap.insert(uid, chatForm);
        }
        if (!iditemMap.contains(uid)) {
            addItem(uid, "user", false);
        }
    }
    else {
        GroupChatFormForm *chatForm = (GroupChatFormForm *)this->chatForm;
        if (chatForm != nullptr) {
            chatForm->hide();
            //if (chatForm->uid == uid) return;
        }
        if (idgchatMap.contains(uid)) {
            GroupChatFormForm *form = idgchatMap.value(uid);
            form->show();
            form->move(221, 0);
            this->chatForm = form;
        }
        else {
            this->chatForm = new GroupChatFormForm(this, uid, name);
            GroupChatFormForm *chatForm = (GroupChatFormForm*)this->chatForm;
            chatForm->show();
            chatForm->move(221, 0);
            idgchatMap.insert(uid, chatForm);
        }
        if (!iditemMap.contains(uid)) {
            addItem(uid, "group", false);
        }
    }
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "messageitemform.h"
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

}

void MessageWindow::addItem(QString uid, QString type) {
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
                changeChatForm(uid, "");
            });
            playout->addWidget(form2);
            iditemMap.insert(uid, form2);
            ui->messagescrollArea->widget()->setLayout(playout);

        });

    }
}

void MessageWindow::changeChatForm(QString uid, QString name) {
    if (chatForm != nullptr) {
        chatForm->hide();
        //if (chatForm->uid == uid) return;
    }
    if (idchatMap.contains(uid)) {
        MessageChatForm *form = idchatMap.value(uid);
        form->show();
        form->move(221, 0);
        chatForm = form;
    }
    else {
        chatForm = new MessageChatForm(this, uid, name, 0);
        chatForm->show();
        chatForm->move(221, 0);
        idchatMap.insert(uid, chatForm);
    }
    if (!iditemMap.contains(uid)) {
        addItem(uid, "user");
    }
}

MessageWindow::~MessageWindow()
{
    delete ui;
}
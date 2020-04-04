#include "centerbox.h"
#include "ui_centerbox.h"
#include "globle_param.h"
#include <QJsonObject>
#include <QDate>
#include <QDateEdit>
#include <QDateTime>

CenterBox::CenterBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterBox)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    loadData();
}

void CenterBox::loadData() {
    QImage map(HEADERFILEPASS);
    map = map.scaled(ui->headerLabel->width(), ui->headerLabel->height());
    ui->headerLabel->setPixmap(QPixmap::fromImage(map));
    network->sendPMessage(GLOUID, "getalluserinfo");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonObject obj = doc.object();
        QString username = obj.value("username").toString();
        QString nickname = obj.value("nickname").toString();
        QString header = obj.value("header").toString();
        time_t birthtime = obj.value("birthtime").toInt();
        QString introduction = obj.value("introduction").toString();
        QString email = obj.value("email").toString();
        QString phonenumber = obj.value("phone_number").toString();
        QString address_p = obj.value("address_p").toString();
        QString address_c = obj.value("address_c").toString();
        QString note = obj.value("note").toString();
        ui->usernameEdit->setText(username);
        ui->nicknameEdit->setText(nickname);
        QDateTime dt = QDateTime::fromTime_t(birthtime);
        ui->plainTextEdit->setPlainText(introduction);
        ui->mailEdit->setText(email);
        ui->beizhuEdit->setText(note);
        ui->uidEdit->setText(GLOUID);
        ui->dateEdit->setDate(dt.date());

        disconnect(network, &WexNetwork::dataArrive, this, 0);
    });
}


CenterBox::~CenterBox()
{
    delete ui;
}

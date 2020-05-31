#include "centerbox.h"
#include "ui_centerbox.h"
#include "globle_param.h"
#include <QJsonObject>
#include <QDate>
#include <QDateEdit>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QComboBox>
 #pragma execution_character_set("utf-8")
CenterBox::CenterBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterBox)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    loadData();
    isEditabel = false;
    connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){
        //设置为可编辑状态
        if (isEditabel == false) {
            //ui->usernameEdit->setEnabled(true);
            ui->nicknameEdit->setEnabled(true);
            ui->dateEdit->setEnabled(true);
            ui->plainTextEdit->setEnabled(true);
            ui->beizhuEdit->setEnabled(true);
            ui->mailEdit->setEnabled(true);
            ui->provinceComboBox->setEnabled(true);
            ui->cityComboBox->setEnabled(true);
            ui->pushButton_2->setText("提交");
            //获取省份城市数据并加载
            QFile file(":/json/pc.json");
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug()<<"fail to open "<<"pc.json";
            }
            else {
                if (ui->provinceComboBox->count() > 0) {
                    ui->provinceComboBox->removeItem(0);
                }
                if (ui->cityComboBox->count() > 0) {
                    ui->cityComboBox->removeItem(0);
                }
                QTextStream in(&file);
                in.setCodec("UTF-8");
                QString str;
                in>>str;
                file.close();
                QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
                //qDebug()<<"json:"<<doc.isArray()<<" and "<<doc.isObject();
                QJsonObject obj = doc.object();
                QStringList keys = obj.keys();
                for (int i = 0; i < ui->provinceComboBox->count(); i++) {
                    ui->provinceComboBox->removeItem(i);
                }
                ui->provinceComboBox->addItems(keys);

                void (QComboBox::*ptr)(const QString&) = &QComboBox::currentIndexChanged;
                connect(ui->provinceComboBox, ptr, this, [=](const QString &text){
                    int count = ui->cityComboBox->count();
                    for (int i = 0; i < count; i++) {
                        ui->cityComboBox->removeItem(i);
                    }
                    QJsonValue val = obj.value(text);
                    QJsonArray arr = val.toArray();
                    QJsonArray::iterator it;
                    for (it = arr.begin(); it !=arr.end(); it++) {
                        QString str2 = it->toString();
                        ui->cityComboBox->addItem(str2);
                    }
                });
            }
            isEditabel = true;
        }
        else {
            //提交数据
            QString nickname = ui->nicknameEdit->text();
            QDate birthtime = ui->dateEdit->date();
            QDateTime dt(birthtime);
            time_t birthtime2 = dt.toTime_t();
            QString mail = ui->mailEdit->text();
            QString address_p = ui->provinceComboBox->currentText();
            QString address_c = ui->cityComboBox->currentText();
            QString note = ui->beizhuEdit->text();
            QString introduction = ui->plainTextEdit->toPlainText();
            QString uid = ui->uidEdit->text();
            QJsonObject obj;
            obj.insert("nickname", nickname);
            obj.insert("birthtime", QJsonValue((int)birthtime2));
            obj.insert("mail", mail);
            obj.insert("address_p", address_p);
            obj.insert("address_c", address_c);
            obj.insert("note", note);
            obj.insert("introduction", introduction);
            obj.insert("uid", uid);
            QJsonDocument doc(obj);
            network->sendPMessage(QString(doc.toJson()), "updateinfobyuid");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString str = network->fetchPMessage();
                if (str == "ok") {
                    QMessageBox::information(this, "提示", "修改成功");
                    //block修改项目
                    ui->nicknameEdit->setEnabled(false);
                    ui->dateEdit->setEnabled(false);
                    ui->beizhuEdit->setEnabled(false);
                    ui->plainTextEdit->setEnabled(false);
                    ui->mailEdit->setEnabled(false);
                    ui->provinceComboBox->setEnabled(false);
                    ui->cityComboBox->setEnabled(false);
                    isEditabel = false;
                    ui->pushButton_2->setText("编辑");

                }
                else if (str == "failed") {
                    QMessageBox::warning(this, "提示", "修改失败");
                }
                disconnect(network, &WexNetwork::dataArrive, this, 0);
            });


        }
    });
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
        ui->provinceComboBox->addItem(address_p);
        ui->cityComboBox->addItem(address_c);
        disconnect(network, &WexNetwork::dataArrive, this, 0);
    });
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        emit goBack();
    });
}


CenterBox::~CenterBox()
{
    delete ui;
}

#include "groupchatformform.h"
#include "ui_groupchatformform.h"
#include <QDateTime>
#include "globle_param.h"
#include <QJsonObject>
#include <QMessageBox>
#include <QFileDialog>
 #pragma execution_character_set("utf-8")

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
           sendMsg(msg, "", "");
        }
    });
    //send image
    connect(ui->pictureButton, &QPushButton::clicked, this, [=](){
        QString curPath=QDir::currentPath();//获取系统当前目录
        //获取应用程序的路径
        QString dlgTitle="选择一个文件"; //对话框标题
        QString filter="图片文件(*.jpg *.gif *.png);;"; //文件过滤器
        QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if (!aFileName.isEmpty()) {
            QString filename = ftp->uploadFile(aFileName);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString name){
                if (name == aFileName) {
                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    //do here
                    QString temp = "<img>";
                    temp.append(filename);
                    sendMsg(temp, aFileName, "img");
                }
            });
        }
    });
    //send file
    connect(ui->fileButton, &QPushButton::clicked, this, [=](){
        QString curPath=QDir::currentPath();//获取系统当前目录
        //获取应用程序的路径
        QString dlgTitle="选择一个文件"; //对话框标题
        QString filter="文本文档(*.txt);;所有文件(*.*)"; //文件过滤器
        QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if (!aFileName.isEmpty()) {
            QString filename = ftp->uploadFile(aFileName);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString name){
                if (name == aFileName) {
                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    //do here
                    QString temp = "<fil>";
                    temp.append(filename);
                    sendMsg(temp, aFileName, "fil");
                }
            });
        }
    });

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        disconnect(timer, &QTimer::timeout, this, 0);
        timer->stop();
        if (idGmemberMap.count() == 0) {
            //get member header and name
            imgCount = 0;
            network->sendPMessage(gid, "getallgroupmemberbugid");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                if (res == "failed") {
                    QMessageBox::information(this, "提示", "读取失败");
                }
                else {
                    QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
                    QJsonArray arr = doc.array();
                    for (QJsonArray::iterator it = arr.begin(); it != arr.end(); it++) {
                        QJsonObject obj = it->toObject();
                        gmember_entity entity;
                        QString uid = obj.value("uid").toString();
                        entity.name = obj.value("name").toString();
                        entity.header = obj.value("header").toString();
                        idGmemberMap.insert(uid, entity);
                        if (entity.header != "") {
                            ftp->fetchFile(entity.header);
                            imgCount++;
                            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                                QStringList list  =filename.split('/');
                                if (list.last() == entity.header) {
                                    imgCount--;
                                    gmember_entity ent = idGmemberMap.find(uid).value();
                                    ent.pass = filename;
                                    idGmemberMap.insert(uid, ent);
                                }
                                if (imgCount == 0) {
                                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                                }
                            });
                        }

                    }
                }
            });

        }
    });

    timer->start(1000);

}

void GroupChatFormForm::sendMsg(QString msg,  QString pass, QString type) {
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
        else if (res == "ok") {
           // addItem(GLOUID, msg, time(0));
            if (pass == "") {
               addItem(GLOUID, msg, time(0));
            }
            else {
                if (type == "img") {
                    QString temp = "<iig>";
                    temp.append(pass);
                    addItem(GLOUID, msg, time(0));
                }
                else if (type == "fil") {
                    QString temp = "<iil>";
                    temp.append(pass);
                    addItem(GLOUID, msg, time(0));
                }
            }
        }
    });
}

void GroupChatFormForm::addItem(QString uid, QString text, time_t time) {
    if (idGmemberMap.contains(uid)){
        gmember_entity ent = idGmemberMap.find(uid).value();
        ui->showwidget->addItem(ent.pass, ent.name, text, time);
    }
}

GroupChatFormForm::~GroupChatFormForm()
{
    delete ui;
}

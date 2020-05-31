#include "messagechatform.h"
#include "ui_messagechatform.h"
#include "globle_param.h"
#include "viedodialog.h"
#include "WexConfig.h"
#include <QMessageBox>
#include <QFileDialog>

 #pragma execution_character_set("utf-8")
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
            sendMessage(msg);
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
                    sendMessage(temp, aFileName, "img");
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
                    sendMessage(temp, aFileName, "fil");
                }
            });
        }
    });
    //video button
    connect(ui->videoButton, &QPushButton::clicked, this, [this]() {
        //send inform
        int num = qrand()%1000;
        QString temp = "<vid>" + QString::number(num);
        sendMessage(temp, "aaa", "aaa");
        ViedoDialog *dia = new ViedoDialog(this, ViedoServerPass + QString(num));
        dia->show();
    });
}

void MessageChatForm::sendMessage(QString text, QString pass, QString type) {
    QDateTime datetime = QDateTime();
    //datetime.setTime(QTime::currentTime());
    QJsonObject obj;
    obj.insert("text", text);
    obj.insert("fromuid", GLOUID);
    obj.insert("area", uid);
    obj.insert("type", 0);
    obj.insert("msgtime", (int)time(0));
    QJsonDocument doc(obj);
    network->sendPMessage(doc.toJson(), "sendmessagetouser");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        //do here
        if (res == "failed") {
            QMessageBox::information(this, "提示", "消息发送失败");
        }
    });
    if (pass == "") {
        ui->chatForm->addItem(HEADERFILEPASS, MYNAME, text, time(0));
    }
    else {
        if (type == "img") {
            QString temp = "<iig>";
            temp.append(pass);
            ui->chatForm->addItem(HEADERFILEPASS, MYNAME, temp, time(0));
        }
        else if (type == "fil") {
            QString temp = "<iil>";
            temp.append(pass);
            ui->chatForm->addItem(HEADERFILEPASS, MYNAME, temp, time(0));
        }
    }
}

void MessageChatForm::addMsg(QString msg, time_t time) {
    ui->chatForm->addItem(headerpass, name, msg, time);
}

MessageChatForm::~MessageChatForm()
{
    delete ui;
}

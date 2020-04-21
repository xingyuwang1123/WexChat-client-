#include "addfriendsdialog.h"
#include "ui_addfriendsdialog.h"
#include "globle_param.h"
#include <QJsonObject>
#include <QMessageBox>

AddFriendsDialog::AddFriendsDialog(QWidget *parent, QMap<QString, QString> uidMap) :
    QDialog(parent),
    ui(new Ui::AddFriendsDialog)
{
    ui->setupUi(this);
    uidmap = uidMap;
    network = WexNetwork::get_instance();
    isChecking = true;
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
       if (isChecking) {
           QString uid = ui->nameEdit->text();
           network->sendPMessage(uid, "getheadername");
           connect(network, &WexNetwork::dataArrive, this, [=](){
               QString res = network->fetchPMessage();
               disconnect(network, &WexNetwork::dataArrive, this, 0);
               QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
               QJsonObject obj = doc.object();
               QString name = obj.value("name").toString();
               QString header = obj.value("header").toString();
               if (name =="" && header == "") {
                   QMessageBox::information(this, "提示", "用户不存在");
                   return;
               }
               else if (this->uidmap.values().contains(uid) || GLOUID == uid) {
                   QMessageBox::information(this, "提示", "uid"+uid+"是您或者您的好友");
                   return;
               }
               else {
                   applyingUid = uid;
                   delete ui->label;
                   delete ui->nameEdit;
                   form = new FriendApplyForm(this, header, name);
                   form->show();
                   form->move(0,0);
                   ui->pushButton->setText("申请");
                   isChecking = false;
               }
           });
       }
       else {
            QString appinfo = form->fetchText();
            //qDebug()<<appinfo;
            //network->sendPMessage()
            QJsonObject obj;
            obj.insert("fromuid", GLOUID);
            obj.insert("touid", applyingUid);
            obj.insert("information", appinfo);
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "applyfriend");
            connect(network, &WexNetwork::dataArrive, this, [=](){
               QString res = network->fetchPMessage();
               disconnect(network, &WexNetwork::dataArrive, this, 0);
               if (res == "ok") {
                   QMessageBox::information(this, "提示", "申请成功");
                   accept();
               }
               else if (res == "failed") {
                   QMessageBox::information(this, "提示", "申请失败");
                   reject();
               }
               else {
                   reject();
               }

            });
       }
    });
}

AddFriendsDialog::~AddFriendsDialog()
{
    delete ui;
}

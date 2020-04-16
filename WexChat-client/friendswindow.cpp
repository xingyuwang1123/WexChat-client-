#include "friendswindow.h"
#include "ui_friendswindow.h"
#include "globle_param.h"
#include "addcutindialog.h"
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

FriendsWindow::FriendsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendsWindow)
{
    ui->setupUi(this);
    addDia = nullptr;
    imageCount = 0;
    network = WexNetwork::get_instance();
    ftp = WexFtp::get_instance();
    loadData();
    connect(ui->addButton, &QPushButton::clicked, this, [=](){
        int ret;
        if (addDia == nullptr) {
            addDia = new AddFriendsDialog(this);
            ret = addDia->exec();
        }
        else {
            ret = addDia->exec();
        }
        if (ret == QDialog::Accepted) {
            //reload data
            loadData();
        }
    });
    //好友详细信息
    QImage himage(":/img/center.svg");
    himage = himage.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(himage));
    ui->friendInfoFrame->hide();
    isfrihidden = true;
    //好友项目的点击事件
    connect(ui->treeWidget, &QTreeWidget::itemPressed, this, [=](QTreeWidgetItem *item, int colume){
        //qDebug()<<"pressed:"<<colume;
        if (!frimap.values().contains(item)) {
            QString clickedUid = uidMap.find(item->text(1)).value();
            if(isfrihidden) {
                ui->friendInfoFrame->show();
            }
            //load data
            loadFriData(clickedUid);
        }
        //点击添加分组
        else if (item->text(0) == "添加分组") {
            AddCutinDialog *dialog = new AddCutinDialog(this);
            if (dialog->exec() == QDialog::Accepted) {
                QString newCutin = dialog->fetchNewCutin();
                //qDebug()<<newCutin;
                //提交修改
                QString cutin = "";
                QList<QString> list = frimap.keys();
                foreach (QString str, list) {
                    if (str != "添加分组" && str != "未分组") {
                        cutin.append(str);
                        cutin.append('/');
                    }
                }
                cutin.append(newCutin);
                //qDebug()<<cutin;
                QJsonObject obj;
                obj.insert("uid", GLOUID);
                obj.insert("cutin", cutin);
                QJsonDocument doc(obj);
                network->sendPMessage(doc.toJson(), "updatecutinbyuid");
                connect(network, &WexNetwork::dataArrive, this, [=](){
                    QString res = network->fetchPMessage();
                    disconnect(network, &WexNetwork::dataArrive, this, 0);
                    if (res == "ok") {
                        loadData();
                    }
                    else if (res == "failed") {
                        QMessageBox::information(this, "添加分组", "添加失败");
                    }
                });
            }
            delete dialog;
        }
        else if (item->text(0) != "未分组" && colume == 1) {
            //删除分组
            QMessageBox::StandardButton res = QMessageBox::question(this, "删除分组", "确认要删除分组吗？", QMessageBox::Yes|QMessageBox::No);
            if (res == QMessageBox::Yes) {
                QString cutin = "";
                QList<QString> list = frimap.keys();
                foreach (QString str, list) {
                    if (str != "添加分组" && str != "未分组" && str != item->text(0)) {
                        cutin.append(str);
                        cutin.append('/');
                    }
                }
                cutin.remove(cutin.length()-1, 1);
                //qDebug()<<cutin;
                //network->sendPMessage()
                QJsonObject obj;
                obj.insert("uid", GLOUID);
                obj.insert("cutin", cutin);
                QJsonDocument doc(obj);
                network->sendPMessage(doc.toJson(), "updatecutinbyuid");
                connect(network, &WexNetwork::dataArrive, this, [=](){
                    QString res = network->fetchPMessage();
                    disconnect(network, &WexNetwork::dataArrive, this, 0);
                    if (res == "ok") {
                        loadData();
                    }
                    else if (res == "failed") {
                        QMessageBox::information(this, "添加分组", "添加失败");
                    }
                });
            }
        }
    });
}

void FriendsWindow::loadFriData(QString uid) {
    network->sendPMessage(uid, "getalluserinfo");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonObject obj = doc.object();
        QString username = obj.value("username").toString();
        QString nickname = obj.value("nickname").toString();
        QString header = obj.value("header").toString();
        time_t birthtime = obj.value("birthtime").toInt();
        QString intro = obj.value("introduction").toString();
        QString mail = obj.value("email").toString();
        QString address_p = obj.value("address_p").toString();
        QString address_c = obj.value("address_c").toString();
        QString note = obj.value("note").toString();
        ui->usernameEdit->setText(username);
        ui->nicknameEdit->setText(nickname);
        if (header != "") {

        }
        QDateTime time = QDateTime::fromTime_t(birthtime);
        ui->birthtimeEdit->setDate(time.date());
        ui->introBrowser->setPlainText(intro);
        ui->mailEdit->setText(mail);
        ui->provinceEdit->setText(address_p);
        ui->cityEdit->setText(address_c);
        ui->noteEdit->setText(note);
        ui->uidEdit->setText(uid);
        disconnect(network, &WexNetwork::dataArrive, this, 0);
    });
}

void FriendsWindow::loadData() {
    //删除已有信息
    ui->treeWidget->clear();
    frimap.clear();
    uidMap.clear();
   //先获取分组信息
    network->sendPMessage(GLOUID, "getcutinbyuid");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        if (res == "failed") {
            qDebug()<<"wrong in loading cutin";
        }
        else {
            QStringList list = res.split('/');
            //ui->treeWidget->setHeaderLabels(list);
            ui->treeWidget->setHeaderHidden(true);
            ui->treeWidget->setColumnCount(2);
            foreach(QString str, list) {
                QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<str);
                frimap.insert(str, item);
                item->setIcon(1, QIcon(":/img/delete.svg"));
                ui->treeWidget->addTopLevelItem(item);
            }
            QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"未分组");
            frimap.insert("未分组", item);
            ui->treeWidget->addTopLevelItem(item);
            QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"添加分组");
            frimap.insert("添加分组", item2);
            ui->treeWidget->addTopLevelItem(item2);
        }
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        //再 获取好友列表
        network->sendPMessage(GLOUID, "getallfriendsbyuid");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString res = network->fetchPMessage();
            QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
            QJsonArray arr = doc.array();
            QJsonArray::iterator it = arr.begin();
            for (; it != arr.end(); it++) {
                QJsonObject obj = it->toObject();
                QString uid = obj.value("uid").toString();
                QString username = obj.value("username").toString();
                QString header = obj.value("header").toString();
                QString cutin = obj.value("cutin").toString();
                uidMap.insert(username, uid);
                QTreeWidgetItem *fatherItem;
                //获取对应的表头
                if (frimap.contains(cutin)){
                    fatherItem = frimap.find(cutin).value();
                }
                else {
                    fatherItem = frimap.find("未分组").value();
                }
                QTreeWidgetItem *item = new QTreeWidgetItem();

                item->setIcon(0,QIcon(":/img/center.svg"));
                item->setText(1, username);
                fatherItem->addChild(item);
                //load pic
                if (header != "") {
                    ftp->fetchFile(header);
                    imageCount++;
                    connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                        //get filename
                        QStringList list = filename.split('/');
                        if (list.last() == header) {
                             QImage image(filename);
                             image = image.scaled(16, 16);
                             QIcon icon(QPixmap::fromImage(image));
                             item->setIcon(0, icon);
                             imageCount--;
                        }
                        if (imageCount == 0) {
                            disconnect(ftp, &WexFtp::fileFinished, this, 0);
                        }
                    });
                }
            }
            disconnect(network, &WexNetwork::dataArrive, this, 0);
        });
    });

}

FriendsWindow::~FriendsWindow()
{
    delete ui;
}

#include "friendswindow.h"
#include "ui_friendswindow.h"
#include "globle_param.h"
#include <QJsonObject>
#include <QDebug>

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
}

void FriendsWindow::loadData() {
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
                ui->treeWidget->addTopLevelItem(item);
            }
            QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"未分组");
            frimap.insert("未分组", item);
            ui->treeWidget->addTopLevelItem(item);
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

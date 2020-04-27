#include "groupwindow.h"
#include "ui_groupwindow.h"
#include "creategroupdialog.h"
#include "addgroupdialog.h"
#include "globle_param.h"

GroupWindow::GroupWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupWindow)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    ui->mgroupinfoframe->hide();
    ui->groupInfoFrame->hide();
    //创建群组
    connect(ui->createButton, &QPushButton::clicked, this, [=](){
        AddGroupDialog dia;
        if (dia.exec() == QDialog::Accepted) {
            //do here
            loadData();
        }

    });
    //加入群组
    connect(ui->addButton, &QPushButton::clicked, this, [=](){
        CreateGroupDialog dia;
        if (dia.exec() == QDialog::Accepted) {
            //do here

        }
    });
    //点击事件
    connect(ui->listWidget, &QListWidget::itemClicked, this, [=](QListWidgetItem *item){
        ui->mgroupinfoframe->hide();
        ui->groupInfoFrame->hide();
        QString gid = itemMap2.find(item).value();
        //qDebug()<<gid;
        currentGid = gid;
        group_entity entity = groupMap.find(gid).value();
        if (entity.tip == false) {
            //group master window
            ui->mgroupinfoframe->show();
            ui->uidEdit_2->setText(gid);
            ui->nameEdit_2->setText(entity.name);
            ui->plainTextEdit->setPlainText(entity.intro);
            if (entity.header != "") {
                QImage img(iconMap.find(gid).value());
                img = img.scaled(ui->headerlabel_2->width(), ui->headerlabel_2->height());
                ui->headerlabel_2->setPixmap(QPixmap::fromImage(img));
            }
        }
        else {
            ui->groupInfoFrame->show();
            ui->uidEdit->setText(gid);
            ui->nameEdit->setText(entity.name);
            ui->textBrowser->setPlainText(entity.intro);
            if (entity.header != "") {
                QImage img(iconMap.find(gid).value());
                img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
                ui->headerlabel->setPixmap(QPixmap::fromImage(img));
            }

        }
    });
    loadData();
}

void GroupWindow::loadData() {
    network->sendPMessage(GLOUID, "getallgroupsbyuid");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonArray arr = doc.array();
        for (QJsonArray::iterator it = arr.begin(); it != arr.end(); it++) {
            group_entity entity;
            QJsonObject obj = it->toObject();
            entity.name = obj.value("name").toString();
            entity.header = obj.value("header").toString();
            entity.intro = obj.value("intro").toString();
            entity.tip = obj.value("tip").toBool();
            groupMap.insert(obj.value("gid").toString(), entity);
        }

        //load image
        imageResting = 0;
        QMap<QString, group_entity>::const_iterator i;
        for(i = groupMap.constBegin(); i != groupMap.constEnd(); i++) {
            QString header = i.value().header;
            QString gid  =i.key();
            QIcon icon(":/img/center.svg");
            QListWidgetItem *item = new QListWidgetItem(icon, i.value().name);
            ui->listWidget->addItem(item);
            itemMap.insert(i.key(), item);
            itemMap2.insert(item, i.key());
            //get image
            if (header != "") {
                ftp->fetchFile(header);
                imageResting++;
                connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                    QStringList list = filename.split('/');
                    if (list.last() == header) {
                        imageResting--;
                        iconMap.insert(gid, filename);
                        QListWidgetItem *item = itemMap.find(gid).value();
                        QIcon icon(filename);
                        item->setIcon(icon);
                    }
                    if (imageResting == 0) {
                        disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    }
                });
            }
        }
    });
}

GroupWindow::~GroupWindow()
{
    delete ui;
}

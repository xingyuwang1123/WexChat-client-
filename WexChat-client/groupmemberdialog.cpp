#include "groupmemberdialog.h"
#include "ui_groupmemberdialog.h"
#include <QListWidget>

GroupMemberDialog::GroupMemberDialog(QWidget *parent, QString gid) :
    QDialog(parent),
    ui(new Ui::GroupMemberDialog)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    //load data
    imgCount = 0;
    network->sendPMessage(gid, "getallgroupmemberbugid");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonArray arr = doc.array();
        for (QJsonArray::iterator it = arr.begin(); it != arr.end(); it++) {
            QJsonObject obj = it->toObject();
            QString uid = obj.value("uid").toString();
            QString name = obj.value("name").toString();
            QString header = obj.value("header").toString();
            QIcon icon(":/img/center.svg");
            QListWidgetItem *item = new QListWidgetItem(icon, name);
            ui->listWidget->addItem(item);

            //load img
            if (header != "") {
                ftp->fetchFile(header);
                imgCount++;
                connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                    QStringList list = filename.split('/');
                    if (list.last() == header) {
                        imgCount--;
                        QIcon icon(filename);
                        item->setIcon(icon);

                    }
                    if (imgCount == 0) {
                        disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    }
                });
            }
        }
    });
}

GroupMemberDialog::~GroupMemberDialog()
{
    delete ui;
}

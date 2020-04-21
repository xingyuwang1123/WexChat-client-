#include "friendsapplydialog.h"
#include "ui_friendsapplydialog.h"
#include "globle_param.h"
#include "applyitemform.h"
#include <QLayout>

FriendsApplyDialog::FriendsApplyDialog(QWidget *parent, QStringList list) :
    QDialog(parent),
    ui(new Ui::FriendsApplyDialog)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    cutinList = list;
    //loadItems(QStringList()<<""<<"", QStringList()<<"111"<<"222", QStringList()<<"111"<<"222");
    network->sendPMessage(GLOUID, "getallapply");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        QStringList headerList, nameList, infoList, uidList;
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonArray arr = doc.array();
        for (QJsonArray::iterator item = arr.begin(); item != arr.end(); item++) {
           // QString uid = item.value;
            QJsonObject obj = item->toObject();
            QString uid = obj.value("uid").toString();
            QString name = obj.value("name").toString();
            QString header = obj.value("header").toString();
            QString applyinfo = obj.value("applyinfo").toString();
            headerList<<header;
            nameList<<name;
            infoList<<applyinfo;
            uidList<<uid;
        }
        loadItems(headerList, nameList, infoList, uidList);
    });
}

void FriendsApplyDialog::loadItems(QStringList header, QStringList name, QStringList intro, QStringList uid) {
    QGridLayout *playout = new QGridLayout(this);
    for (int i = 0; i < header.length(); i++) {
        applyItemForm *form = new applyItemForm(this, header[i], name[i], intro[i], uid[i], cutinList);
        playout->addWidget(form);
    }
    ui->scrollArea->widget()->setLayout(playout);
}

FriendsApplyDialog::~FriendsApplyDialog()
{
    delete ui;
}

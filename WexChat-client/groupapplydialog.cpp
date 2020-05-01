#include "groupapplydialog.h"
#include "ui_groupapplydialog.h"
#include "groupapplyform.h"
#include <QGridLayout>

GroupApplyDialog::GroupApplyDialog(QWidget *parent, QString gid) :
    QDialog(parent),
    ui(new Ui::GroupApplyDialog),
    gid(gid)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    loadData();
}

void GroupApplyDialog::loadData() {
    network->sendPMessage(gid, "getallgroupapplyuserbygid");
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        disconnect(network, &WexNetwork::dataArrive, this, 0);
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        QJsonArray arr = doc.array();
        QGridLayout *playout = new QGridLayout(this);


        for (QJsonArray::iterator it = arr.begin(); it != arr.end(); it++) {
            QJsonObject obj = it->toObject();
            QString uid = obj.value("uid").toString();
            QString name = obj.value("name").toString();
            QString header = obj.value("header").toString();
            QString appinfo = obj.value("appinfo").toString();
            GroupApplyForm *form = new GroupApplyForm(this, name, header, uid, appinfo, gid);
            form->setMinimumSize(340, 175);
            playout->addWidget(form);
        }
        ui->scrollArea->widget()->setLayout(playout);
    });
}

GroupApplyDialog::~GroupApplyDialog()
{
    delete ui;
}

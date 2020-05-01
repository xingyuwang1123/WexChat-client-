#include "groupapplyform.h"
#include "ui_groupapplyform.h"
#include <QMessageBox>

GroupApplyForm::GroupApplyForm(QWidget *parent, QString name, QString header, QString uid, QString appinfo, QString gid) :
    QWidget(parent),
    ui(new Ui::GroupApplyForm),
    formuid(uid)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    ui->namelabel->setText(name);
    ui->infoBrowser->setPlainText(appinfo);
    //load img
    if (header != "") {
        ftp->fetchFile(header);
        connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
            QStringList list = filename.split('/');
            if (list.last() == header) {
                disconnect(ftp, &WexFtp::fileFinished, this, 0);
                QImage img(filename);
                img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
                ui->headerlabel->setPixmap(QPixmap::fromImage(img));
            }
        });
    }
    //reject
    connect(ui->rejectButton, &QPushButton::clicked, this, [=](){
        ui->rejectButton->setEnabled(false);
        ui->agreeButton->setEnabled(false);
        QJsonObject obj;
        obj.insert("uid", formuid);
        obj.insert("gid", gid);
        QJsonDocument doc(obj);
        network->sendPMessage(doc.toJson(), "rejectgroupapply");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString  res = network->fetchPMessage();
            disconnect(network, &WexNetwork::dataArrive, this, 0);
            if (res == "failed") {
                QMessageBox::information(this, "提示", "提交失败");
            }
         });
    });
    //accept
    connect(ui->agreeButton, &QPushButton::clicked, this, [=](){
        ui->rejectButton->setEnabled(false);
        ui->agreeButton->setEnabled(false);
        QJsonObject obj;
        obj.insert("uid", formuid);
        obj.insert("gid", gid);
        QJsonDocument doc(obj);
        network->sendPMessage(doc.toJson(), "acceptgroupapply");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString  res = network->fetchPMessage();
            disconnect(network, &WexNetwork::dataArrive, this, 0);
            if (res == "failed") {
                QMessageBox::information(this, "提示", "提交失败");
            }
        });
    });
}

GroupApplyForm::~GroupApplyForm()
{
    delete ui;
}

#include "groupinfoform.h"
#include "ui_groupinfoform.h"
#include "globle_param.h"
#include <QMessageBox>

GroupInfoForm::GroupInfoForm(QWidget *parent, QString name, QString header, QString intro, QString id) :
    QWidget(parent),
    ui(new Ui::GroupInfoForm)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    ftp = WexFtp::get_instance();
    ui->nameEdit->setText(name);
    ui->uidEdit->setText(id);
    ui->textBrowser->setPlainText(intro);
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
    //submit
    connect(ui->submitButton, &QPushButton::clicked, this, [=](){
        QString appinfo = ui->plainTextEdit->toPlainText();
        if (!appinfo.isEmpty()) {
            QJsonObject obj;
            obj.insert("uid", GLOUID);
            obj.insert("gid", id);
            obj.insert("appinfo", appinfo);
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "doapplygroup");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                if (res == "failed") {
                    QMessageBox::information(this, "提示", "申请失败");
                    emit canceled();
                }
                else {
                    QMessageBox::information(this, "提示", "申请成功");
                    emit  applyok();
                }
            });
        }
    });
}

GroupInfoForm::~GroupInfoForm()
{
    delete ui;
}

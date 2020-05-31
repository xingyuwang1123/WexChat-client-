#include "applyitemform.h"
#include "ui_applyitemform.h"
#include "globle_param.h"
#include "choosecutindialog.h"
#include <QMessageBox>
 #pragma execution_character_set("utf-8")
applyItemForm::applyItemForm(QWidget *parent, QString header, QString name, QString info,  QString uid, QStringList list) :
    QWidget(parent),
    ui(new Ui::applyItemForm)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    QImage img(":/img/center.svg");
    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    ui->namelabel->setText(name);
    ui->infoBrowser->setPlainText(info);
    //load image
    if (header != "") {
        ftp->fetchFile(header);
        connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
            QStringList list = filename.split('/');
            if (list.last() == header) {
                disconnect(ftp, &WexFtp::fileFinished, this, 0);
                 QImage image(filename);
                 image = image.scaled(ui->headerlabel->width(), ui->headerlabel->height());
                 //QIcon icon(QPixmap::fromImage(image));
                 ui->headerlabel->setPixmap(QPixmap::fromImage(image));
            }
        });
    }
    connect(ui->acceptButton, &QPushButton::clicked, this, [=](){

        ChooseCutinDialog dia(this, list);
        if (dia.exec() == QDialog::Accepted) {
            QString cutin = dia.fetchChosen();
            //qDebug() << cutin;
            ui->acceptButton->setEnabled(false);
            ui->rejectButton->setEnabled(false);
            QJsonObject obj;
            obj.insert("fromuid", uid);
            obj.insert("touid", GLOUID);
            obj.insert("cutin", cutin);
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "acceptapply");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                if (res == "failed") {
                     QMessageBox::information(this, "添加好友", "添加失败");
                }
            });
        }


    });
    connect(ui->rejectButton, &QPushButton::clicked, this, [=](){
        ui->acceptButton->setEnabled(false);
        ui->rejectButton->setEnabled(false);
        QJsonObject obj;
        obj.insert("fromuid", uid);
        obj.insert("touid", GLOUID);
        QJsonDocument doc(obj);
        network->sendPMessage(doc.toJson(), "rejectapply");
        connect(network, &WexNetwork::dataArrive, this, [=](){
            QString res = network->fetchPMessage();
            disconnect(network, &WexNetwork::dataArrive, this, 0);
            if (res == "failed") {
                 QMessageBox::information(this, "添加好友", "拒绝失败");
            }
        });
    });
}

applyItemForm::~applyItemForm()
{
    delete ui;
}

#include "navigator.h"
#include "ui_navigator.h"
#include <QPushButton>
#include "globle_param.h"
#include <QJsonObject>
#include <qftp.h>

Navigator::Navigator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Navigator)
{
    ui->setupUi(this);

//    QPalette palette(this->palette());
//    palette.setColor(QPalette::Background, Qt::black);
//    this->setPalette(palette);
    QIcon icon1(":/img/center.svg");
    ui->centerButton->setIcon(icon1);
    QIcon icon2(":/img/firends.svg");
    ui->firendsButton->setIcon(icon2);
    QIcon icon3(":/img/message.svg");
    ui->messageButton->setIcon(icon3);
    network = WexNetwork::get_instance();
    ftp = WexFtp::get_instance();
    connect(ui->messageButton, &QPushButton::clicked, this, [=](){
        emit messageClicked();
    });
    connect(ui->firendsButton, &QPushButton::clicked, this, [=](){
        emit friendsClicked();
    });
    connect(ui->centerButton, &QPushButton::clicked, this, [=](){
        emit centerClicked();
    });
    loadData();
}

void Navigator::loadData() {
    network->sendPMessage(GLOUID, "getheadername");
    //qDebug()<<GLOUID;
    connect(network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        QJsonDocument jsondoc = QJsonDocument::fromJson(res.toUtf8());
        QJsonObject obj = jsondoc.object();
        QString nickname = obj.value("name").toString();
        QString header = obj.value("header").toString();
        ui->usernameLabel->setText(nickname);
        if (header != "") {
            //do here load image
            //下载文件
            ftp->fetchFile(header);
            //下载完成后载图
            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                HEADERFILEPASS = filename;
                QStringList list = filename.split('/');
                if (list.last() == header) {
                    QImage image(filename);
                    image = image.scaled(ui->headerLabel->width(), ui->headerLabel->height());
                    ui->headerLabel->setPixmap(QPixmap::fromImage(image));
                }
                emit headerImgFinished();
                disconnect(ftp, &WexFtp::fileFinished, this, 0);
            });
        }
        disconnect(network, &WexNetwork::dataArrive, this, 0);
    });
}

Navigator::~Navigator()
{
    delete ui;
}

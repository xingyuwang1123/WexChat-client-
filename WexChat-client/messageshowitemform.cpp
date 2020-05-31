#include "messageshowitemform.h"
#include "ui_messageshowitemform.h"
#include <QDateTime>
#include <QPushButton>
#include <QDebug>
#include <QDesktopServices>
#include "viedodialog.h"
#include "globle_param.h"
#include "WexConfig.h"

 #pragma execution_character_set("utf-8")
MessageShowItemForm::MessageShowItemForm(QWidget *parent,  QString header, QString name, time_t time, QString text) :
    QWidget(parent),
    ui(new Ui::MessageShowItemForm)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    ui->namelabel->setText(name);
    QDateTime timed = QDateTime::fromTime_t(time);
    QString timestr = timed.toString("MM月dd日hh:mm");
    ui->timelabel->setText(timestr);
    QImage img(":/img/center.svg");
    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    if (header != "") {
        QImage img(header);
        img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
        ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    }
    //parse text
    QString temp = text.left(5);
    if (temp == "<iig>") {
        QString pass = text.right(text.length() - 5);
        delete ui->textBrowser;
        QLabel *piclabel = new QLabel(this);
        piclabel->move(130,10);
        piclabel->resize(61,61);
        piclabel->show();
        QImage img(pass);
        img = img.scaled(61, 61);
        piclabel->setPixmap(QPixmap::fromImage(img));
    }
    else if(temp == "<iil>") {
        QString pass = text.right(text.length() - 5);
        delete ui->textBrowser;
        QLabel *label = new QLabel(this);
        label->setText("文件已上传...");
        label->move(130, 10);
        label->show();
        QPushButton *button = new QPushButton(this);
        button->setText("打开文件夹");
        button->move(130, 30);
        button->show();
        connect(button, &QPushButton::clicked, this, [=](){
            QString dirPass = pass.section('/', 0, -2);
            //qDebug()<<dirPass;
            bool res = QDesktopServices::openUrl("file:///" + dirPass);
           // qDebug()<<res;
        });
    }
    else if (temp == "<img>") {
        //distance image
        QString pass = text.right(text.length() - 5);
        delete ui->textBrowser;
        QLabel *piclabel = new QLabel(this);
        piclabel->move(130,10);
        piclabel->resize(61,61);
        piclabel->show();
        QImage img(":/img/center.svg");
        img = img.scaled(61, 61);
        piclabel->setPixmap(QPixmap::fromImage(img));
        //download image
        ftp->fetchFile(pass);
        connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
            QStringList list = filename.split('/');
            if (list.last() == pass) {
                disconnect(ftp, &WexFtp::fileFinished, this, 0);
                QImage img(filename);
                img = img.scaled(61, 61);
                piclabel->setPixmap(QPixmap::fromImage(img));
            }
        });
    }
    else if (temp == "<fil>") {
        QString pass = text.right(text.length() - 5);
        delete ui->textBrowser;
        QLabel *label = new QLabel(this);
        label->setText("收到文件：" + pass);
        label->move(130, 10);
        label->show();
        QPushButton *button = new QPushButton(this);
        button->setText("接收");
        button->move(130, 30);
        button->show();
        connect(button, &QPushButton::clicked, this, [=](){
//            QString dirPass = pass.section('/', 0, -2);
//            qDebug()<<dirPass;
//            bool res = QDesktopServices::openUrl("file:///" + dirPass);
//            qDebug()<<res;
            button->setEnabled(false);
            label->setText("接收中...");
            disconnect(button, &QPushButton::clicked, this, 0);
            ftp->fetchFile(pass);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                QStringList list = filename.split('/');
                if (list.last() == pass) {
                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    label->setText("接收成功");
                    button->setText("打开文件夹");
                    button->setEnabled(true);
                    connect(button, &QPushButton::clicked, this, [=](){

                        QDesktopServices::openUrl("file:///" + TEMPDIRPASS);
                    });
                }
           });
        });
    }
    else if (temp == "<vid>") {
        QString pass = text.right(text.length() - 5);
        delete ui->textBrowser;
        QLabel *label = new QLabel(this);
        label->setText("视频通话请求...");
        label->move(130, 10);
        label->show();
        QPushButton *button = new QPushButton(this);
        button->setText("接受");
        button->move(130, 30);
        button->show();
        connect(button, &QPushButton::clicked, this, [=](){
            ViedoDialog *dia = new ViedoDialog(this, ViedoServerPass + pass);
            dia->show();
        });
    }
    else {
        ui->textBrowser->setPlainText(text);
    }
}

MessageShowItemForm::~MessageShowItemForm()
{
    delete ui;
}

#include "centerwindow.h"
#include "ui_centerwindow.h"
#include "globle_param.h"
#include "WexConfig.h"
#include <QDebug>
#include <QPushButton>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
 #pragma execution_character_set("utf-8")
CenterWindow::CenterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterWindow)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    box = new CenterBox(this);
    box->hide();
    //connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
    loadImg(HEADERFILEPASS);
        //disconnect(ftp, &WexFtp::fileFinished, this, 0);
    //});
    //点击个人中心按钮
    connect(ui->centerButton, &QPushButton::clicked, this, [=](){
        ui->frame->hide();
        box->show();
        box->move(200, 1);
    });
    //个人中心会弹
    connect(box, &CenterBox::goBack, this, [=](){
        box->hide();
        ui->frame->show();
    });
    //点击关于，反馈按钮
    connect(ui->backButton, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl::fromUserInput(PROJECT_ADDRESS));
    });
    connect(ui->aboutButton, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl::fromUserInput(PROJECT_ADDRESS));
    });

    //推出登陆
    connect(ui->quitButton, &QPushButton::clicked, this, [=](){
        emit quitLogin();
    });
    //改头像
    connect(ui->changeHeaderButton, &QPushButton::clicked, this, [=](){
        QString curPath=QDir::currentPath();//获取系统当前目录
        //获取应用程序的路径
        QString dlgTitle="选择一个文件"; //对话框标题
        QString filter="图片文件(*.jpg *.gif *.png);;"; //文件过滤器
        QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if (!aFileName.isEmpty()) {
            qDebug()<<aFileName;
            QString md5 = ftp->uploadFile(aFileName);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                //QStringList list = filename.split('/');
                if (filename == aFileName) {
                    disconnect(ftp, &WexFtp::fileFinished, this, 0);
                    QJsonObject obj;
                    obj.insert("uid", GLOUID);
                    obj.insert("header", md5);
                    QJsonDocument doc(obj);
                    network->sendPMessage(doc.toJson(), "changeheaderbyuid");
                    connect(network, &WexNetwork::dataArrive, this, [=](){
                        QString res = network->fetchPMessage();
                        if (res == "ok") {
                            QMessageBox::information(this, "提示", "上传头像成功");
                            loadImg(aFileName);
                            emit headerChanged(md5);
                        }
                        else if (res == "failed") {
                            QMessageBox::information(this, "提示", "上传头像失败");
                        }
                    });
                }
            });
        }
    });
}

void CenterWindow::loadImg(QString pass) {
    if (pass == "" || !QFile::exists(pass)) {
        QImage img(":/img/center/svg");
        img = img.scaled(ui->label->width(), ui->label->height());
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
    else {
        QImage img(pass);
        img = img.scaled(ui->label->width(), ui->label->height());
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
}

CenterWindow::~CenterWindow()
{
    delete ui;
}

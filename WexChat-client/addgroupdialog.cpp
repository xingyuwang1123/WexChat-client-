#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"
#include "globle_param.h"
#include <QFileDialog>
#include <QMessageBox>

AddGroupDialog::AddGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    network = WexNetwork::get_instance();
    //上穿头像
    connect(ui->headerButton, &QPushButton::clicked, this, [=](){
        QString curPath=QDir::currentPath();//获取系统当前目录
        //获取应用程序的路径
        QString dlgTitle="选择一个文件"; //对话框标题
        QString filter="图片文件(*.jpg *.gif *.png);;"; //文件过滤器
        QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if (!aFileName.isEmpty()) {
            uploadFilename = ftp->uploadFile(aFileName);
            connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
                if (filename == aFileName) {
                    QMessageBox::information(this, "提示", "上传成功");
                    QImage img(aFileName);
                    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
                    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
                }
            });
        }
    });
    //提交
    connect(ui->submitButton, &QPushButton::clicked, this, [=](){
        QString name = ui->nameEdit_2->text();
        QString intro = ui->introEdit->toPlainText();
        if (!name.isEmpty() && !intro.isEmpty()) {
            QJsonObject obj;
            obj.insert("name", name);
            obj.insert("intro", intro);
            obj.insert("header", uploadFilename);
            obj.insert("masteruid", GLOUID);
            QJsonDocument doc(obj);
            network->sendPMessage(doc.toJson(), "creategroupbyuid");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
                //do here
                if (res == "ok") {
                    QMessageBox::information(this, "创建群", "创建成功");
                    accept();
                }
                else if (res == "failed") {
                    QMessageBox::information(this, "创建群", "创建失败");
                    reject();
                }
            });
        }
        else {
            QMessageBox::information(this, "提示", "名称或者介绍不能为空");
        }
    });
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

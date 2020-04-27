#include "creategroupdialog.h"
#include "ui_creategroupdialog.h"
#include "groupinfoform.h"
#include <QMessageBox>

CreateGroupDialog::CreateGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGroupDialog)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    connect(ui->submitButton, &QPushButton::clicked, this, [=](){
        QString gid = ui->idEdit->text();
        if (!gid.isEmpty() ) {
            network->sendPMessage(gid, "getgroupinfobyid");
            connect(network, &WexNetwork::dataArrive, this, [=](){
                QString res = network->fetchPMessage();
                disconnect(network, &WexNetwork::dataArrive, this, 0);
               if (res == "failed") {
                   QMessageBox::information(this, "提示", "群组不存在");
               }
               else {
                   //do here
                   QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
                   QJsonObject obj = doc.object();
                   QString name = obj.value("name").toString();
                   QString intro = obj.value("intro").toString();
                   QString header = obj.value("header").toString();
                   QString masteruid = obj.value("masteruid").toString();
                   if (name == "0" || masteruid == "0") {
                       QMessageBox::information(this, "提示", "群组不存在");

                   }
                   else {
                       ui->widget->setParent(NULL);
                       delete ui->widget;
                       ui->submitButton->setParent(NULL);
                       delete ui->submitButton;
                       GroupInfoForm *form = new GroupInfoForm(this, name, header, intro, gid);
                       form->show();
                       form->move(0,0);
                       this->resize(form->width(), form->height());
                       connect(form, &GroupInfoForm::canceled, this, [=](){
                           reject();
                       });
                       connect(form, &GroupInfoForm::applyok, this, [=](){
                           accept();
                       });
                   }
                   //clear all contents
   //                QLayoutItem *child;
   //                 while ((child = this->layout()->takeAt(0)) != 0)
   //                 {
   //                        //setParent为NULL，防止删除之后界面不消失
   //                        if(child->widget())
   //                        {
   //                            child->widget()->setParent(NULL);
   //                        }

   //                        delete child;
   //                 }

               }
            });
        }
        else {
            QMessageBox::information(this, "提示", "不能为空");
        }
    });
}

CreateGroupDialog::~CreateGroupDialog()
{
    delete ui;
}

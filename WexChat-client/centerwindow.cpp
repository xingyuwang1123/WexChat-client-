#include "centerwindow.h"
#include "ui_centerwindow.h"
#include "globle_param.h"
#include <QDebug>
#include <QPushButton>

CenterWindow::CenterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterWindow)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    box = new CenterBox(this);
    box->hide();
    //connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
        QImage img(HEADERFILEPASS);
        img = img.scaled(ui->label->width(), ui->label->height());
        ui->label->setPixmap(QPixmap::fromImage(img));
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
}

CenterWindow::~CenterWindow()
{
    delete ui;
}

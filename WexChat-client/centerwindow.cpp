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
    connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
        QImage img(filename);
        img = img.scaled(ui->label->width(), ui->label->height());
        ui->label->setPixmap(QPixmap::fromImage(img));
        disconnect(ftp, &WexFtp::fileFinished, this, 0);
    });
    connect(ui->centerButton, &QPushButton::clicked, this, [=](){
        box = new CenterBox(this);
        box->hide();
        ui->frame->hide();
        box->show();
        box->move(200, 1);
    });
}

CenterWindow::~CenterWindow()
{
    delete ui;
}

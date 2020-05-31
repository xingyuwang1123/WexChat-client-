#include "friendapplyform.h"
#include "ui_friendapplyform.h"
 #pragma execution_character_set("utf-8")
FriendApplyForm::FriendApplyForm(QWidget *parent, QString header, QString name) :
    QWidget(parent),
    ui(new Ui::FriendApplyForm)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    ui->namelabel->setText(name);
    QImage img(":/img/center.svg");
    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    if (header != "") {
        ftp->fetchFile(header);
        connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
            disconnect(ftp, &WexFtp::fileFinished, this, 0);
            QImage img(filename);
            img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
            ui->headerlabel->setPixmap(QPixmap::fromImage(img));
        });
    }
}

QString FriendApplyForm::fetchText() {
    return ui->plainTextEdit->toPlainText();
}

FriendApplyForm::~FriendApplyForm()
{
    delete ui;
}

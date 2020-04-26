#include "messageshowitemform.h"
#include "ui_messageshowitemform.h"
#include <QDateTime>

MessageShowItemForm::MessageShowItemForm(QWidget *parent,  QString header, QString name, time_t time, QString text) :
    QWidget(parent),
    ui(new Ui::MessageShowItemForm)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    ui->namelabel->setText(name);
    ui->textBrowser->setPlainText(text);
    QDateTime timed = QDateTime::fromTime_t(time);
    QString timestr = timed.toString("MM-dd-hh-mm");
    ui->timelabel->setText(timestr);
    QImage img(":/img/center.svg");
    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    if (header != "") {
        QImage img(header);
        img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
        ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    }
}

MessageShowItemForm::~MessageShowItemForm()
{
    delete ui;
}

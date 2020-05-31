#include "messageitemform.h"
#include "ui_messageitemform.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
 #pragma execution_character_set("utf-8")
MessageItemForm::MessageItemForm(QWidget *parent, QString header, QString name, qint32 count, QString uid) :
    QWidget(parent),
    ui(new Ui::MessageItemForm),
    uid(uid)
{
    ui->setupUi(this);
    ftp = WexFtp::get_instance();
    QImage img(":/img/center.svg");
    img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
    ui->headerlabel->setPixmap(QPixmap::fromImage(img));
    ui->namelabel->setText(name);
    ui->countlabel->setText(QString::number(count));
    if (header != "") {
        ftp->fetchFile(header);
        connect(ftp, &WexFtp::fileFinished, this, [=](QString filename){
            QStringList list = filename.split('/');
            if (list.last() == header) {
                disconnect(ftp, &WexFtp::fileFinished, this, 0);
                QImage img(filename);
                img = img.scaled(ui->headerlabel->width(), ui->headerlabel->height());
                ui->headerlabel->setPixmap(QPixmap::fromImage(img));
            }
        });
    }

}

//rewrite mouse click
//bool QWidget::event(QEvent *event) {
//    if (event->type() == QEvent::MouseButtonPress) {
//        QMouseEvent *mousEvent = static_cast<QMouseEvent*>(event);
//        if(mousEvent->button() == Qt::LeftButton)
//        {
//            QMessageBox::information(NULL,"单击","单击了我",
//                                     QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
//            return true;
//        }
//    }
//    return QWidget::event(event);
//};

void MessageItemForm::mousePressEvent(QMouseEvent *ev) {
    mousePos = QPoint(ev->x(), ev->y());
}

void MessageItemForm::mouseReleaseEvent(QMouseEvent *ev) {
    if(mousePos == QPoint(ev->x(), ev->y())) emit clicked(uid);
}

MessageItemForm::~MessageItemForm()
{
    delete ui;
}

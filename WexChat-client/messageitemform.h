#ifndef MESSAGEITEMFORM_H
#define MESSAGEITEMFORM_H

#include <QWidget>
#include "wexftp.h"

namespace Ui {
class MessageItemForm;
}

class MessageItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit MessageItemForm(QWidget *parent = nullptr, QString header = "", QString name = "", qint32 count = 0, QString uid = "");
    ~MessageItemForm();

private:
    Ui::MessageItemForm *ui;
    QPoint mousePos;
    WexFtp *ftp;
    QString uid;
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void clicked(QString uid);
};

#endif // MESSAGEITEMFORM_H

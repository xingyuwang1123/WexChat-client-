#ifndef MESSAGESHOWITEMFORM_H
#define MESSAGESHOWITEMFORM_H

#include <QWidget>
#include "wexftp.h"

namespace Ui {
class MessageShowItemForm;
}

class MessageShowItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit MessageShowItemForm(QWidget *parent = nullptr, QString header = "", QString name = "", time_t time = -1, QString text = "");
    ~MessageShowItemForm();

private:
    Ui::MessageShowItemForm *ui;
    WexFtp *ftp;
};

#endif // MESSAGESHOWITEMFORM_H

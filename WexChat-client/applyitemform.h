#ifndef APPLYITEMFORM_H
#define APPLYITEMFORM_H

#include <QWidget>
#include "wexftp.h"
#include "wexnetwork.h"

namespace Ui {
class applyItemForm;
}

class applyItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit applyItemForm(QWidget *parent = nullptr, QString header = "", QString name = "", QString info = "", QString uid = "", QStringList list = QStringList());
    ~applyItemForm();

private:
    Ui::applyItemForm *ui;
    WexNetwork *network;
    WexFtp *ftp;
};

#endif // APPLYITEMFORM_H

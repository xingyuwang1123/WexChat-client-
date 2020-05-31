#ifndef APPLYITEMFORM_H
#define APPLYITEMFORM_H
 #pragma execution_character_set("utf-8")
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

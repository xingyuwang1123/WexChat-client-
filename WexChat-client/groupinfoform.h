#ifndef GROUPINFOFORM_H
#define GROUPINFOFORM_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "wexnetwork.h"
#include "wexftp.h"

namespace Ui {
class GroupInfoForm;
}

class GroupInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit GroupInfoForm(QWidget *parent = nullptr, QString name = "", QString header = "", QString intro = "", QString id = "");
    ~GroupInfoForm();

private:
    Ui::GroupInfoForm *ui;
    WexNetwork *network;
    WexFtp *ftp;

signals:
    void applyok();
    void canceled();
};

#endif // GROUPINFOFORM_H

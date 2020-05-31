#ifndef FRIENDAPPLYFORM_H
#define FRIENDAPPLYFORM_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "wexftp.h"

namespace Ui {
class FriendApplyForm;
}

class FriendApplyForm : public QWidget
{
    Q_OBJECT

public:
    explicit FriendApplyForm(QWidget *parent = nullptr, QString header = "", QString name = "");
    ~FriendApplyForm();
    QString fetchText();
private:
    Ui::FriendApplyForm *ui;
    WexFtp *ftp;
};

#endif // FRIENDAPPLYFORM_H

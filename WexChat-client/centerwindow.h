#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include <QWidget>
#include "wexftp.h"
#include "wexnetwork.h"
#include "centerbox.h"

namespace Ui {
class CenterWindow;
}

class CenterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CenterWindow(QWidget *parent = nullptr);
    ~CenterWindow();

private:
    Ui::CenterWindow *ui;
    CenterBox *box;
    WexFtp *ftp;
    WexNetwork *network;
    void loadImg(QString pass);
signals:
    void quitLogin();
    void headerChanged(QString header);
};

#endif // CENTERWINDOW_H

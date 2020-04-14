#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include <QWidget>
#include "wexftp.h"
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

signals:
    void quitLogin();
};

#endif // CENTERWINDOW_H

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QWidget>
#include "wexnetwork.h"
#include "wexftp.h"

namespace Ui {
class Navigator;
}

class Navigator : public QWidget
{
    Q_OBJECT

public:
    explicit Navigator(QWidget *parent = nullptr);
    void changeHeader(QString pass);
    ~Navigator();

private:
    Ui::Navigator *ui;
    WexNetwork *network;
    WexFtp *ftp;
    void loadData();
signals:
    void messageClicked();
    void friendsClicked();
    void centerClicked();
    void headerImgFinished();
};

#endif // NAVIGATOR_H

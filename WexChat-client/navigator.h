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
};

#endif // NAVIGATOR_H

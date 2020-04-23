#ifndef FRIENDSWINDOW_H
#define FRIENDSWINDOW_H

#include <QWidget>
#include "addfriendsdialog.h"
#include "wexnetwork.h"
#include "wexftp.h"
#include <QMap>
#include <QTreeWidgetItem>

namespace Ui {
class FriendsWindow;
}

class FriendsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsWindow(QWidget *parent = nullptr);

    ~FriendsWindow();

private:
    Ui::FriendsWindow *ui;
    WexNetwork *network;
    WexFtp *ftp;
    int imageCount;
    AddFriendsDialog *addDia;
    QMap<QString, QTreeWidgetItem*> frimap;
    QMap<QString, QString> uidMap;
    bool isfrihidden;
    QString currentUid;
    void loadData();
    void loadFriData(QString uid);

signals:
    void sendMessageChat(QString uid, QString name);
};

#endif // FRIENDSWINDOW_H

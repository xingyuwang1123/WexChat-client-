#ifndef GROUPWINDOW_H
#define GROUPWINDOW_H

#include <QWidget>
#include "wexftp.h"
#include "wexnetwork.h"
#include <QListWidgetItem>

typedef struct {
    QString name;
    QString intro;
    QString header;
    bool tip;
}group_entity;

namespace Ui {
class GroupWindow;
}

class GroupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GroupWindow(QWidget *parent = nullptr);
    ~GroupWindow();

private:
    Ui::GroupWindow *ui;
    WexFtp *ftp;
    WexNetwork *network;
    void loadData();
    QString currentGid;
    QMap<QString, group_entity> groupMap;
    QMap<QString,QString> iconMap;
    QMap<QString, QListWidgetItem*> itemMap;
    QMap<QListWidgetItem*, QString> itemMap2;
    int imageResting;
};

#endif // GROUPWINDOW_H

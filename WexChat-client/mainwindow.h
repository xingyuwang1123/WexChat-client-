#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "navigator.h"
#include "centerwindow.h"
#include "friendswindow.h"
#include "messagewindow.h"
#include "groupwindow.h"
#include "wexnetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Navigator *nav;
    CenterWindow *center;
    FriendsWindow *friends;
    MessageWindow *message;
    GroupWindow *group;
    WexNetwork *network;
    int shownWindow;
    void doHide();
};

#endif // MAINWINDOW_H

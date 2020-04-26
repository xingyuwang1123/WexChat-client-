#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QPushButton>
#include "navigator.h"
#include "centerwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shownWindow = -1;
    nav = new Navigator(this);
    nav->show();
    center = nullptr;
    friends = nullptr;
    message  = nullptr;
    group = nullptr;
    connect(nav, &Navigator::centerClicked, this, [=](){
        if (center == nullptr) {
            center = new CenterWindow(this);
            center->hide();
            //change img
            connect(center, &CenterWindow::headerChanged, this, [=](QString md5){
                nav->changeHeader(md5);
            });
        }
        if (shownWindow != 3) {
            doHide();
            center->show();
            center->move(0, 56);
            shownWindow = 3;
        }
    });
    connect(nav, &Navigator::friendsClicked, this, [=](){
        if (friends == nullptr) {
            friends = new FriendsWindow(this);
            friends->hide();
            //切换发消息窗口
            connect(friends, &FriendsWindow::sendMessageChat, this, [=](QString uid, QString name){
                message->changeChatForm(uid, name);
                doHide();
                message->show();
                message->move(0,56);
                shownWindow = 1;
            });
        }
        if (shownWindow != 2) {
            doHide();
            friends->show();
            friends->move(0,56);
            shownWindow = 2;
        }
    });
    connect(nav, &Navigator::messageClicked, this, [=](){
        if (message == nullptr) {
            message = new MessageWindow(this);
            message->hide();
        }
        if (shownWindow != 1) {
            doHide();
            message->show();
            message->move(0,56);
            shownWindow = 1;
        }
    });
    connect(nav, &Navigator::groupClicked, this, [=](){
        if (group == nullptr) {
            group = new GroupWindow(this);
            group->hide();
        }
        if (shownWindow != 4) {
            doHide();
            group->show();
            group->move(0, 56);
            shownWindow = 4;
        }
    });
    //直接显示消息窗口
    message = new MessageWindow(this);
    message->show();
    message->move(0,56);
    shownWindow = 1;
}

void MainWindow::doHide() {
    if (shownWindow == 3) {
        center->hide();
    }
    else if (shownWindow == 2) {
        friends->hide();
    }
    else if (shownWindow == 1) {
        message->hide();
    }
    else if (shownWindow == 4){
        group->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

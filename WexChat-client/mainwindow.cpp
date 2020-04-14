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
    connect(nav, &Navigator::centerClicked, this, [=](){
        if (center == nullptr) {
            center = new CenterWindow(this);
            center->hide();
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
        }
        if (shownWindow != 2) {
            doHide();
            friends->show();
            friends->move(0,56);
            shownWindow = 2;
        }
    });
}

void MainWindow::doHide() {
    if (shownWindow == 3) {
        center->hide();
    }
    else if (shownWindow == 2) {
        friends->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

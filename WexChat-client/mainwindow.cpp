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
    center = new CenterWindow(this);
    center->hide();
    connect(nav, &Navigator::centerClicked, this, [=](){
        if (shownWindow != 3) {
            center->show();
            center->move(0, 56);
            shownWindow = 3;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

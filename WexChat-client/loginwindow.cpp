#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPushButton>
#include <QJsonObject>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->subwindow = new NewUserWindow();
    this->network = WexNetwork::get_instance();
    subwindow->hide();
    connect(ui->newuserButton, &QPushButton::clicked, this, &LoginWindow::tosubSlot);
    connect(this->subwindow, &NewUserWindow::changeSignal, this, &LoginWindow::tomainSlot);
    connect(ui->loginButton, &QPushButton::clicked, this, [=](){
        QString username = ui->usernameEdit->text();
        QString password = ui->passwordEdit->text();
        if (username.isEmpty() || password.isEmpty()) {
            ui->warning->setText("空用户名或者密码！");
            return;
        }
        //封装json
        QJsonObject obj;
        obj.insert("username", username);
        obj.insert("password", password);
        //qDebug()<<obj;
        QJsonDocument jsonDoc(obj);
        this->network->sendPMessage(QString(jsonDoc.toJson()), "login");
    });
    connect(this->network, &WexNetwork::dataArrive, this, [=](){
        QString res = network->fetchPMessage();
        //qDebug()<<res;
        if (res == "ok") {
            //do here
        }
        else {
            ui->warning->setText("用户名或者密码错误！");
        }
    });
}

void LoginWindow::tosubSlot() {
    this->hide();
    subwindow->show();
}

void LoginWindow::tomainSlot() {
    subwindow->hide();
    this->show();
}

LoginWindow::~LoginWindow()
{
    network->disconnect();
    delete ui;
}


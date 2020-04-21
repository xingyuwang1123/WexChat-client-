#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPushButton>
#include <QJsonObject>
#include <globle_param.h>

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
        connect(this->network, &WexNetwork::dataArrive, this, [=](){
            QString res = network->fetchPMessage();
            //断开网路监听
            disconnect(this->network, &WexNetwork::dataArrive, this, 0);
            //qDebug()<<res;
            if (res == "loginwrongup"){
                ui->warning->setText("用户名或者密码错误！");
            }
            else if (res == "loginfailed") {
                ui->warning->setText("后台错误");
            }
            else {
                //do here
                ui->warning->setText("");
                QJsonDocument jsondoc = QJsonDocument::fromJson(res.toUtf8());
                QJsonObject obj = jsondoc.object();
                //QJsonObject::iterator objit = obj.find("uid");
                QJsonValue value = obj.value("uid");
                GLOUID = value.toString();
                qDebug()<< GLOUID;
                //消除新用户窗口
                delete this->subwindow;

                this->nextWindow = new MainWindow();
                this->hide();
                nextWindow->show();
                //监听推出登陆事件
                //connect(nextWindow)
            }
        });
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


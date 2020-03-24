#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include <QPushButton>
#include <qjsonobject.h>

NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
    network = WexNetwork::get_instance();
    connect(ui->backButton, &QPushButton::clicked, this, [=](){
        emit changeSignal();
    });

    connect(ui->submitButton, &QPushButton::clicked, this, [=](){
        QString username = ui->usernameEdit->text();
        QString password = ui->passwordEdit->text();
        QString repassword = ui->repasswordEdit->text();
        QString phone = ui->phoneEdit->text();
        QString mail = ui->mailEdit->text();
        QString nickname = ui->nicknameEdit->text();
        //输入检验
        if (username.isEmpty() || password.isEmpty() || repassword.isEmpty() || phone.isEmpty() || mail.isEmpty() || nickname.isEmpty()) {
            ui->warning->setText("存在空项目");
            return ;
        }
        if (password != repassword) {
            ui->warning->setText("输入密码不一致");
            return ;
        }

        QJsonObject obj;
        obj.insert("username", username);
        obj.insert("password", password);
        obj.insert("phone", phone);
        obj.insert("mail", mail);
        obj.insert("nickname", nickname);
        QJsonDocument doc(obj);
        network->sendPMessage(doc.toJson(), "register");
    });
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}

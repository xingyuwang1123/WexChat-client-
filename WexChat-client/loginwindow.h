#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
 #pragma execution_character_set("utf-8")
#include <QMainWindow>
#include "newuserwindow.h"
#include "wexnetwork.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    NewUserWindow *subwindow;
    MainWindow *nextWindow;
    WexNetwork *network;
    void tomainSlot();
    void tosubSlot();
};
#endif // LOGINWINDOW_H

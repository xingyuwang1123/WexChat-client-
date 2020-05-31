#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H
 #pragma execution_character_set("utf-8")
#include <QWidget>
#include "wexnetwork.h"

namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();

private:
    Ui::NewUserWindow *ui;
    WexNetwork *network;
signals:
    void changeSignal();
};

#endif // NEWUSERWINDOW_H

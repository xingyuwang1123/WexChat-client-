#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "navigator.h"
#include "centerwindow.h"
#include "friendswindow.h"

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
    int shownWindow;
    void doHide();
};

#endif // MAINWINDOW_H

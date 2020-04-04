#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "navigator.h"
#include "centerwindow.h"

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
    int shownWindow;
};

#endif // MAINWINDOW_H

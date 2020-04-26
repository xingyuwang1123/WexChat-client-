#ifndef GROUPWINDOW_H
#define GROUPWINDOW_H

#include <QWidget>

namespace Ui {
class GroupWindow;
}

class GroupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GroupWindow(QWidget *parent = nullptr);
    ~GroupWindow();

private:
    Ui::GroupWindow *ui;
};

#endif // GROUPWINDOW_H

#ifndef CENTERBOX_H
#define CENTERBOX_H

#include <QWidget>
#include "wexnetwork.h"

namespace Ui {
class CenterBox;
}

class CenterBox : public QWidget
{
    Q_OBJECT

public:
    explicit CenterBox(QWidget *parent = nullptr);
    ~CenterBox();

private:
    Ui::CenterBox *ui;
    WexNetwork *network;
    void loadData();
signals:
    void goBack();
};

#endif // CENTERBOX_H

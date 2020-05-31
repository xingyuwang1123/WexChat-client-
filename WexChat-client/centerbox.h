#ifndef CENTERBOX_H
#define CENTERBOX_H
 #pragma execution_character_set("utf-8")
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
    bool isEditabel;
signals:
    void goBack();
};

#endif // CENTERBOX_H

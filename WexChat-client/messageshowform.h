#ifndef MESSAGESHOWFORM_H
#define MESSAGESHOWFORM_H

#include <QWidget>
#include "messageshowitemform.h"

namespace Ui {
class MessageShowForm;
}

class MessageShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit MessageShowForm(QWidget *parent = nullptr);
    ~MessageShowForm();
    void addItem(QString header, QString name, QString text, time_t time);
private:
    Ui::MessageShowForm *ui;
    QList <MessageShowItemForm *> itemList;
};

#endif // MESSAGESHOWFORM_H

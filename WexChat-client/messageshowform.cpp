#include "messageshowform.h"
#include "ui_messageshowform.h"
#include <QGridLayout>
 #pragma execution_character_set("utf-8")
MessageShowForm::MessageShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageShowForm)
{
    ui->setupUi(this);
    QGridLayout *playout = new QGridLayout(this);
    ui->scrollArea->widget()->setLayout(playout);
}

void MessageShowForm::addItem(QString header, QString name, QString text, time_t time) {
    delete ui->scrollArea->widget()->layout();
    QGridLayout *playout = new QGridLayout(this);
    foreach(MessageShowItemForm *form, itemList) {
        playout->addWidget(form);
        form->setMinimumSize(579, 80);
    }
    MessageShowItemForm *form2 = new MessageShowItemForm(this, header, name, time, text);
    form2->setMinimumSize(579, 80);
    playout->addWidget(form2);
    itemList.append(form2);
    ui->scrollArea->widget()->setLayout(playout);
}

MessageShowForm::~MessageShowForm()
{
    delete ui;
}

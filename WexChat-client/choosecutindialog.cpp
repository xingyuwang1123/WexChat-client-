#include "choosecutindialog.h"
#include "ui_choosecutindialog.h"
#include <QComboBox>

ChooseCutinDialog::ChooseCutinDialog(QWidget *parent,  QStringList list) :
    QDialog(parent),
    ui(new Ui::ChooseCutinDialog)
{
    ui->setupUi(this);
    foreach (QString str, list) {
        if (str != "添加分组") {
            ui->comboBox->addItem(str);
        }
    }
}

QString ChooseCutinDialog::fetchChosen() {
    return ui->comboBox->currentText();
}

ChooseCutinDialog::~ChooseCutinDialog()
{
    delete ui;
}

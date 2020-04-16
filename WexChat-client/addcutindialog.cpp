#include "addcutindialog.h"
#include "ui_addcutindialog.h"
#include <QLineEdit>

AddCutinDialog::AddCutinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCutinDialog)
{
    ui->setupUi(this);
    connect(ui->nameEdit, &QLineEdit::textChanged, this, [=](const QString &text){
        newCutin = text;
    });
}

QString AddCutinDialog::fetchNewCutin() {
    return newCutin;
}

AddCutinDialog::~AddCutinDialog()
{
    delete ui;
}

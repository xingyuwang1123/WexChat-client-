#include "addfriendsdialog.h"
#include "ui_addfriendsdialog.h"

AddFriendsDialog::AddFriendsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriendsDialog)
{
    ui->setupUi(this);
}

AddFriendsDialog::~AddFriendsDialog()
{
    delete ui;
}

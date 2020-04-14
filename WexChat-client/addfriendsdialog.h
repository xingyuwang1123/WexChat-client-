#ifndef ADDFRIENDSDIALOG_H
#define ADDFRIENDSDIALOG_H

#include <QDialog>

namespace Ui {
class AddFriendsDialog;
}

class AddFriendsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriendsDialog(QWidget *parent = nullptr);
    ~AddFriendsDialog();

private:
    Ui::AddFriendsDialog *ui;
};

#endif // ADDFRIENDSDIALOG_H

#ifndef ADDCUTINDIALOG_H
#define ADDCUTINDIALOG_H
 #pragma execution_character_set("utf-8")
#include <QDialog>

namespace Ui {
class AddCutinDialog;
}

class AddCutinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCutinDialog(QWidget *parent = nullptr);
    ~AddCutinDialog();
    QString fetchNewCutin();
private:
    Ui::AddCutinDialog *ui;
    QString newCutin;
};

#endif // ADDCUTINDIALOG_H

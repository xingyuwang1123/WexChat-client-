#ifndef CHOOSECUTINDIALOG_H
#define CHOOSECUTINDIALOG_H
 #pragma execution_character_set("utf-8")
#include <QDialog>

namespace Ui {
class ChooseCutinDialog;
}

class ChooseCutinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCutinDialog(QWidget *parent = nullptr, QStringList list = QStringList());
    ~ChooseCutinDialog();
    QString fetchChosen();
private:
    Ui::ChooseCutinDialog *ui;
};

#endif // CHOOSECUTINDIALOG_H

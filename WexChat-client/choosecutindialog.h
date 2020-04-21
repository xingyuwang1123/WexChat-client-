#ifndef CHOOSECUTINDIALOG_H
#define CHOOSECUTINDIALOG_H

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

#ifndef VIEDODIALOG_H
#define VIEDODIALOG_H

#include <QDialog>
#include "swebengineview.h"

namespace Ui {
class ViedoDialog;
}

class ViedoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViedoDialog(QWidget *parent = nullptr, QString pass = "");
    ~ViedoDialog();

private:
    Ui::ViedoDialog *ui;
    SWebEngineView *m_webView;
};

#endif // VIEDODIALOG_H

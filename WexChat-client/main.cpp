#include "loginwindow.h"

#include <QApplication>
#include "wexnetwork.h"
#include "wexftp.h"

WexNetwork* WexNetwork::m_instance_ptr = nullptr;
WexFtp *WexFtp::m_instance_ptr2 = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}

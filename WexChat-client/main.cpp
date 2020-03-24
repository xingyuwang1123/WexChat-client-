#include "loginwindow.h"

#include <QApplication>
#include "wexnetwork.h"

WexNetwork* WexNetwork::m_instance_ptr = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}

#include "storage.h"
#include "loginwindow.h"
#include "loginadmin.h"

#include <QApplication>
#include <QString>


int main(int argc, char *argv[])
{
    bool AdminLogin=false;

    QApplication a(argc, argv);
    LoginWindow LogWin(AdminLogin);
    LogWin.exec();



    Storage w(AdminLogin);
    w.show();
    return a.exec();
}

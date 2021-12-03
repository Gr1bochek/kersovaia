#include "storage.h"
#include "loginwindow.h"
#include "loginadmin.h"

#include <QApplication>
#include <QString>


int main(int argc, char *argv[])
{
    QString AdminLogin="NotLogined";

    QApplication a(argc, argv);
    LoginWindow LogWin(AdminLogin);
    LogWin.exec();


    if(AdminLogin!="NotLogined")
    {
        Storage w(AdminLogin);
        w.show();
        return a.exec();
    }
}

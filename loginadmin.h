#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>
#include <QPainter>

namespace Ui
{
class LoginAdmin;
}

class LoginAdmin : public QDialog
{
    Q_OBJECT

public:

    void paintEvent(QPaintEvent *);
    explicit LoginAdmin(QString&,QWidget *parent = nullptr);
    ~LoginAdmin();
private slots:
    void on_ButtonAdminAutorization_clicked();

private:
   QString*ADMLog;
    Ui::LoginAdmin *ui;
};

#endif // LOGINADMIN_H

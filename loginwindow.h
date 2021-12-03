#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    explicit LoginWindow(QString&,QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_ButtonAdmin_clicked();

    void on_ButtonUser_clicked();

private:
    QString *loginADM;
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H

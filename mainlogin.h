#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QMainWindow>
#include <register.h>

namespace Ui {
class Mainlogin;
}

class Mainlogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainlogin(QWidget *parent = 0);
    ~Mainlogin();

private slots:
    void on_pushButton_exit_clicked();

    void on_actionRegister_triggered();

    void on_pushButton_ok_clicked();

    void moveMain();

private:
    Ui::Mainlogin *ui;
    Register registerpage;
};

#endif // MAINLOGIN_H

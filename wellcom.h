#ifndef WELLCOM_H
#define WELLCOM_H

#include <QWidget>
#include "game.h"
/*
 * This is the wellcome penale
 * class header file
 * it contains slots and public variable
 * and functions
*/

namespace Ui {
class wellcom;
}

class wellcom : public QWidget
{
    Q_OBJECT

public:
    explicit wellcom(QWidget *parent = 0);
    ~wellcom();

private slots:
    void on_pushButton_start_clicked();
    void showuname(QString uname);
    void backtowelcom();

    void on_pushButton_exit_clicked();
    void readytoplay();

private:
    Ui::wellcom *ui;
    game play;
};

#endif // WELLCOM_H

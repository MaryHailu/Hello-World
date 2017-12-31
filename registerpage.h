#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QWidget>
#include "game.h"

/*
  This header file is for the register class
  contains slots, signals, private, and public
  varibles and functions
*/
namespace Ui {
class registerpage;
}

class registerpage : public QWidget
{
    Q_OBJECT

public:
    explicit registerpage(QWidget *parent = 0);
    ~registerpage();
    QHash<QString, QByteArray>hash;


private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_cancle_clicked();

private:
    Ui::registerpage *ui;
    game accessGame;

signals:
    void gohome();
    void sendColorTogame(QString txt);
};

#endif // REGISTERPAGE_H

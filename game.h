#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QString>
#include <QList>
/*
  This class is agame header file
  contains slots, signals, public, and private
  varible and function declartion
*/

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    static int count0, count1, count2, count3, count4, count5, count6, count7, count8, winerwin, compwin, drowin;
    static bool s0, s1, s2, s3, s4, s5, s6, s7, s8;

private slots:
    void getmeColor(QString txt);
    void Mouse_Pressed0();
    void Mouse_Pressed1();
    void Mouse_Pressed2();
    void Mouse_Pressed3();
    void Mouse_Pressed4();
    void Mouse_Pressed5();
    void Mouse_Pressed6();
    void Mouse_Pressed7();
    void Mouse_Pressed8();

    void on_pushButton_Endgame_clicked();


private:
    Ui::game *ui;
    QString color_choise;
    QString value;


signals:
    void gowelcom();


};

#endif // GAME_H

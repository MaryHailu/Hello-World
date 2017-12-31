#include <QDebug>
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <algorithm>
#include <QMessageBox>
#include "game.h"
#include "ui_game.h"
#include "clickable.h"

QList<QString>hold_color;
QList<int>random_num;
int game::count0 =0;
int game::count1 =0;
int game::count2 =0;
int game::count3 =0;
int game::count4 =0;
int game::count5 =0;
int game::count6 =0;
int game::count7 =0;
int game::count8 =0;
int game::winerwin =0;
int game::drowin =0;
int game::compwin =0;
bool game::s0 = false;
bool game::s1 = false; bool game::s2 = false;
bool game::s3 = false; bool game::s4 = false;
bool game::s5 = false; bool game::s6 = false;
bool game::s7 = false; bool game::s8 = false;


//game class constructor
game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    // signal/slot to connect the qlable
    connect(ui->p0, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed0()));
    connect(ui->p1, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed1()));
    connect(ui->p2, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed2()));
    connect(ui->p3, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed3()));
    connect(ui->p4, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed4()));
    connect(ui->p5, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed5()));
    connect(ui->p6, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed6()));
    connect(ui->p7, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed7()));
    connect(ui->p8, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed8()));
}

game::~game()
{
    delete ui;
}

void game::getmeColor(QString txt){ 
    hold_color.push_back(txt);
}
/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed0()
{
   QString user_color;
   QPixmap pix_user, pix_comp;
   if(hold_color.isEmpty()){
       user_color = "Red";
   }
   else{
   user_color = hold_color.front();
   }

   if(user_color == "Red"){
     pix_user.load(":/img/rx.png");
     pix_comp.load(":/img/ro.png");
   }
   else if(user_color == "Blue"){
     pix_user.load(":/img/bx.png");
     pix_comp.load(":/img/bo.png");
   }
   else{
     pix_user.load(":/img/gx.png");
     pix_comp.load(":/img/go.png");
   }

   if(s0!= true && !count0){
       ui->p0->setPixmap(pix_user);
       count0 = 1;

       if(count1 != 1 && !s1){
          ui->p1->setPixmap(pix_comp);
          s1 = true;
       }
       else if(count2 != 1 && !s1){
          ui->p2->setPixmap(pix_comp);
          s2 = true;
       }
       else if(count3 != 1 && !s2){
          ui->p3->setPixmap(pix_comp);
          s3 = true;
       }
       else if(count4 != 1 && !s3){
          ui->p4->setPixmap(pix_comp);
          s4 = true;
       }
       else if(count5 != 1 && !s4){
          ui->p5->setPixmap(pix_comp);
          s5 = true;
       }
       else if(count6 != 1 && !s5){
          ui->p6->setPixmap(pix_comp);
          s6 = true;
       }
       else if(count7 != 1 && !s6){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
       }
       else if(count8 != 1 && !s7){
         ui->p8->setPixmap(pix_comp);
         s8 = true;
       }
       else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
             (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
             (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
             (count0==1 && count4==1 && count8==1) ||
             (count2==1 && count4==1 && count6==1) ||
             (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
             (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
             (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
             (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
             (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
              winerwin++;
              ui->player_score->setText(QString::number(winerwin));
              ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
              ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
              ui->p8->clear();
              count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
              s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
              QMessageBox msgBox;
              msgBox.setWindowTitle("Tic-Tac-Toe");
              msgBox.setText("Congratulations you win");
              msgBox.addButton(QMessageBox::Ok);
              msgBox.exec();
          }
       else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
              (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
              (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
              (s0==1 && s4==1 && s8==1) ||
              (s2==1 && s4==1 && s6==1) ||
              (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
              compwin++;
              ui->compuer_score->setText(QString::number(compwin));
              ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
              ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
              ui->p8->clear();
              count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
              s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
              QMessageBox msgBox;
              msgBox.setWindowTitle("Tic-Tac-Toe");
              msgBox.setText("sorry, you lost. Better luck next time");
              msgBox.addButton(QMessageBox::Ok);
              msgBox.exec();
           }
      else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
               (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
               (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
               (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
               (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
               (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
               (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
               (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
               (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
               (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
               (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
               (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
               (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
               drowin++;
               ui->draw_score->setText(QString::number(drowin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Game Drawn");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
         }
       else{
           drowin++;
           ui->draw_score->setText(QString::number(drowin));
           ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
           ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
           ui->p8->clear();
           count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
           s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
           QMessageBox msgBox;
           msgBox.setWindowTitle("Tic-Tac-Toe");
           msgBox.setText("Game Drawn");
           msgBox.addButton(QMessageBox::Ok);
           msgBox.exec();
       }
   }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed1()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }


    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s1 != true && !count1){
        ui->p1->setPixmap(pix_user);
        count1 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count6 != 1 && !s6){
           ui->p6->setPixmap(pix_comp);
           s6 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=1; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(compwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=1; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=1; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
        else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed2()
{

    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }


    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s2 != true && !count2){
        ui->p2->setPixmap(pix_user);
        count2 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count6 != 1 && !s6){
           ui->p6->setPixmap(pix_comp);
           s6 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
       else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed3()
{

    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }

    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }


    if(s3 != true && !count3){
        ui->p3->setPixmap(pix_user);
        count3 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count6 != 1 && !s6){
           ui->p6->setPixmap(pix_comp);
           s6 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(compwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
       else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed4()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }

    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s4 != true && !count4){
        ui->p4->setPixmap(pix_user);
        count4 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count6 != 1 && !s6){
           ui->p6->setPixmap(pix_comp);
           s6 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(compwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
        else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed5()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }

    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s5 != true && !count5){
        ui->p5->setPixmap(pix_user);
        count5 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count6 != 1 && !s6){
           ui->p6->setPixmap(pix_comp);
           s6 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(compwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
        else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed6()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }

    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s6 != true && !count6){
        ui->p6->setPixmap(pix_user);
        count6 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count7 != 1 && !s7){
          ui->p7->setPixmap(pix_comp);
          s7 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
        else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }

}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed7()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }

    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s7 != true && !count7){
        ui->p7->setPixmap(pix_user);
        count7 = 1;

        if(count0 != 1 && !s0){
           ui->p0->setPixmap(pix_comp);
           s0 = true;
        }
        else if(count1 != 1 && !s1){
           ui->p1->setPixmap(pix_comp);
           s1 = true;
        }
        else if(count2 != 1 && !s2){
           ui->p2->setPixmap(pix_comp);
           s2 = true;
        }
        else if(count3 != 1 && !s3){
           ui->p3->setPixmap(pix_comp);
           s3 = true;
        }
        else if(count4 != 1 && !s4){
           ui->p4->setPixmap(pix_comp);
           s4 = true;
        }
        else if(count5 != 1 && !s5){
           ui->p5->setPixmap(pix_comp);
           s5 = true;
        }
        else if(count6 != 1 && !s6){
          ui->p6->setPixmap(pix_comp);
          s6 = true;
        }
        else if(count8 != 1 && !s8){
          ui->p8->setPixmap(pix_comp);
          s8 = true;
        }
        else if((count0==1 && count1==1 && count2==1 && (s6!=1 && s7!=1 && s8!=1)) ||
              (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
              (count6==1 && count7==1 && count8==1 && (s3!=1 && s4!=1 && s5!=1)) ||
              (count0==1 && count4==1 && count8==1) ||
              (count2==1 && count4==1 && count6==1) ||
              (count1==1 && count4==1 && count7==1 && (s2!=1 && s5!=1 && s8!=1)) ||
              (count2==1 && count5==1 && count8==1 && (s0!=1 && s3!=1 && s6!=1)) ||
              (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
              (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
               winerwin++;
               ui->player_score->setText(QString::number(winerwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("Congratulations you win");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
           }
        else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
               (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
               (s0==1 && s4==1 && s8==1) ||
               (s2==1 && s4==1 && s6==1) ||
               (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
               compwin++;
               ui->compuer_score->setText(QString::number(compwin));
               ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
               ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
               ui->p8->clear();
               count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
               s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
               QMessageBox msgBox;
               msgBox.setWindowTitle("Tic-Tac-Toe");
               msgBox.setText("sorry, you lost. Better luck next time");
               msgBox.addButton(QMessageBox::Ok);
               msgBox.exec();
            }
       else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
                (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
                (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
                (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
                (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
                (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
                (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
                (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
                (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
                (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
          }
        else{
            drowin++;
            ui->draw_score->setText(QString::number(drowin));
            ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
            ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
            ui->p8->clear();
            count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
            s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
            QMessageBox msgBox;
            msgBox.setWindowTitle("Tic-Tac-Toe");
            msgBox.setText("Game Drawn");
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::Mouse_Pressed8()
{
    QString user_color;
    QPixmap pix_user, pix_comp;
    if(hold_color.isEmpty()){
        user_color = "Red";
    }
    else{
    user_color = hold_color.front();
    }
    if(user_color == "Red"){
      pix_user.load(":/img/rx.png");
      pix_comp.load(":/img/ro.png");
    }
    else if(user_color == "Blue"){
      pix_user.load(":/img/bx.png");
      pix_comp.load(":/img/bo.png");
    }
    else{
      pix_user.load(":/img/gx.png");
      pix_comp.load(":/img/go.png");
    }

    if(s8 != true && count8 != 1){
            ui->p8->setPixmap(pix_user);
            count8 = 1;

            if(count0 != 1 && !s0){
               ui->p0->setPixmap(pix_comp);
               s0 = true;
            }
            else if(count1 != 1 && !s1){
               ui->p1->setPixmap(pix_comp);
               s1 = true;
            }
            else if(count2 != 1 && !s2){
               ui->p2->setPixmap(pix_comp);
               s2 = true;
            }
            else if(count3 != 1 && !s3){
               ui->p3->setPixmap(pix_comp);
               s3 = true;
            }
            else if(count4 != 1 && !s4){
               ui->p4->setPixmap(pix_comp);
               s4 = true;
            }
            else if(count5 != 1 && !s5){
               ui->p5->setPixmap(pix_comp);
               s5 = true;
            }
            else if(count6 != 1 && !s6){
              ui->p6->setPixmap(pix_comp);
              s6 = true;
            }
            else if(count7 != 1 && !s7){
              ui->p7->setPixmap(pix_comp);
              s7 = true;
            }

      else if((count0==1 && count1==1 && count2==1 && (s0!=1 && s1!=1 && s2!=1)) ||
            (count3==1 && count4==1 && count5==1 && (s0!=1 || s6!=1)) ||
            (count6==1 && count7==1 && count8==1 && (s6!=1 && s7!=1 && s8!=1)) ||
            (count0==1 && count4==1 && count8==1) ||
            (count2==1 && count4==1 && count6==1) ||
            (count1==1 && count4==1 && count7==1 && (s0!=1 || s3!=1 || s6!=1)) ||
            (count2==1 && count5==1 && count8==1 && (s2!=1 && s5!=1 && s8!=1)) ||
            (count2==1 && count5==1 && count6==1 && count7==1 && count8==1) ||
            (count0==1 && count3==1 && count6==1 && count7==1 && count8==1) ||
            (count1==1 && count4==1 && count6==1 && count7==1 && count8==1)){
             winerwin++;
             ui->player_score->setText(QString::number(winerwin));
             ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
             ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
             ui->p8->clear();
             count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
             s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
             QMessageBox msgBox;
             msgBox.setWindowTitle("Tic-Tac-Toe");
             msgBox.setText("Congratulations you win");
             msgBox.addButton(QMessageBox::Ok);
             msgBox.exec();
         }
      else if((s0==1 && s1==1 && s2==1 && (count6!=1 && count7!=1 && count8!=1)) ||
             (s3==1 && s4==1 && s5==1 && (count6!=1 && count7!=1 && count8!=1)) ||
             (s6==1 && s7==1 && s8==1 && (count0!=1 && count1!=1 && count2!=1)) ||
             (s0==1 && s4==1 && s8==1) ||
             (s2==1 && s4==1 && s6==1) ||
             (s1==1 && s4==1 && s7==1 && (count2!=1 && count5!=1 && count8!=1))){
             compwin++;
             ui->compuer_score->setText(QString::number(compwin));
             ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
             ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
             ui->p8->clear();
             count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
             s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
             QMessageBox msgBox;
             msgBox.setWindowTitle("Tic-Tac-Toe");
             msgBox.setText("sorry, you lost. Better luck next time");
             msgBox.addButton(QMessageBox::Ok);
             msgBox.exec();
          }
     else if((s0==1 && s1==1 && s2==1 && count6==1 && count7==1 && count8==1) ||
              (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
              (count0==1 && count1==1 && count2==1 && s6==1 && s7==1 && s8==1) ||
              (s0==1 && s3==1 && s6==1 && count1==1 && count4==1 && count7==1) ||
              (count0==1 && count3==1 && count6==1 && s1==1 && s4==1 && s7==1) ||
              (count1==1 && count4==1 && count7==1 && s2==1 && s5==1 && s8==1) ||
              (s1==1 && s4==1 && s7==1 && count2==1 && count5==1 && count8==1) ||
              (s0==1 && s1==1 && s2==1 && count3==1 && count4==1 && count5==1) ||
              (count0==1 && count1==1 && count2==1 && s3==1 && s4==1 && s5==1) ||
              (s3==1 && s4==1 && s5==1 && count6==1 && count7==1 && count8==1) ||
              (count3==1 && count4==1 && count5==1 && s6==1 && s7==1 && s8==1) ||
              (s0==1 && s3==1 && s6==1 && count2==1 && count5==1 && count8==1) ||
              (count0==1 && count3==1 && count6==1 && s2==1 && s5==1 && s8==1)){
              drowin++;
              ui->draw_score->setText(QString::number(drowin));
              ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
              ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
              ui->p8->clear();
              count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
              s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
              QMessageBox msgBox;
              msgBox.setWindowTitle("Tic-Tac-Toe");
              msgBox.setText("Game Drawn");
              msgBox.addButton(QMessageBox::Ok);
              msgBox.exec();
        }
      else{
                drowin++;
                ui->draw_score->setText(QString::number(drowin));
                ui->p0->clear(); ui->p1->clear(); ui->p2->clear(); ui->p3->clear();
                ui->p4->clear(); ui->p5->clear(); ui->p6->clear(); ui->p7->clear();
                ui->p8->clear();
                count0 = 0; count1=0; count2=0; count3=0; count4=0; count5=0; count6=0; count7=0; count8=0;
                s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; s7=0; s8=0;
                QMessageBox msgBox;
                msgBox.setWindowTitle("Tic-Tac-Toe");
                msgBox.setText("Game Drawn");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
            }
    }

}

/* this functoin gets the mouse pressed
*  and set the color and winer*/
void game::on_pushButton_Endgame_clicked()
{
    emit gowelcom();
}

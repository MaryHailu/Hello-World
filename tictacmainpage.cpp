#include <QDebug>
#include <QCryptographicHash>
#include <QHash>
#include <QVariant>
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <qhash.h>
#include <QString>
#include <QMessageBox>
#include "tictacmainpage.h"
#include "ui_tictacmainpage.h"


/*
 * Main page diffinetion
 * this consturctor connect the pages
*/

TicTacMainPage::TicTacMainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacMainPage)
{

    ui->setupUi(this);
    ui->stackedWidget->addWidget(&regpage);
    ui->stackedWidget->addWidget(&wellcomepage);
    connect(&regpage, SIGNAL(gohome()), this, SLOT(moveMainpage()));
    connect(this, SIGNAL(showme(QString)),&wellcomepage, SLOT(showuname(QString)));
    connect(this, SIGNAL(logout()), this, SLOT(returnhome()));
    connect(this, SIGNAL(playgame()), &wellcomepage, SLOT(readytoplay()));
}

/*
 * Destructor
*/
TicTacMainPage::~TicTacMainPage()
{
    delete ui;
}

/*
 * exit
*/
void TicTacMainPage::on_pushButton_exit_clicked()
{
    this->close();
}

/*
 * go to register page
*/
void TicTacMainPage::on_actionRegister_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->actionRegister->setDisabled(true);
}

/*
 *cheack if  user is new or alrady in file
*/
void TicTacMainPage::on_pushButton_ok_clicked()
{
   //QFile binaryFile("/home/mary/Desktop/Mary_Hailu_HW5/GameApp/password.dat");
   QFile binaryFile("password.dat");
   QHash<QString, QByteArray>hash;
   QString username = ui->lineEdit_Uname->text();
   QString password = ui->lineEdit_Pword->text();
   QHash<QString, QByteArray>::iterator iter;
   bool cheack = false;

   QByteArray digest_pword = QByteArray(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1).toHex());
   if(binaryFile.open(QIODevice::ReadOnly)){

       QTextStream in(&binaryFile); QString name; QByteArray password_infile;
       while(!in.atEnd()){
           in >> name >> password_infile;
           hash.insert(name,password_infile);
       }
       binaryFile.close();
   }

   for(iter=hash.begin(); iter != hash.end(); ++iter){
      if(username == iter.key() && digest_pword == iter.value()){
              ui->stackedWidget->setCurrentIndex(2);
              ui->actionRegister->setDisabled(true);
              ui->actionNew_Game->setEnabled(true);
              ui->actionLogout->setEnabled(true);
              cheack = true;
      }
   }
   if(cheack == true){
       emit showme(ui->lineEdit_Uname->text());
    }
   else{

     QMessageBox::critical(this,"Invalid Login","The user/password combination"
                                  "dose not match an existing user/password combination");
   }
}

/*
 * go to main page
*/
void TicTacMainPage::moveMainpage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * logout
*/
void TicTacMainPage::on_actionLogout_triggered()
{
    emit logout();
}

/*
 * return to home page
*/
void TicTacMainPage::returnhome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * start game from penal
*/
void TicTacMainPage::on_actionNew_Game_triggered()
{
    emit playgame();
    ui->actionNew_Game->setDisabled(true);
    ui->actionEnd_Game->setEnabled(true);
}

/*
 * exit
*/
void TicTacMainPage::on_actionEnd_Game_triggered()
{
    QApplication::exit();
}

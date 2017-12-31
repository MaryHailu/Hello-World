#include <QDebug>
#include <QCryptographicHash>
#include <QHash>
#include <QVariant>
#include <QDataStream>
#include <QFile>
#include <qhash.h>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include "registerpage.h"
#include "ui_registerpage.h"
#include "game.h"


/*
 * register class defintion
 * constructor connect signals and slots
*/
registerpage::registerpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerpage)
{
    ui->setupUi(this);
    connect(this, SIGNAL(sendColorTogame(QString)),&accessGame, SLOT(getmeColor(QString)));
}

/*
 * destructor
*/
registerpage::~registerpage()
{
    delete ui;
}

/*
 * allow the resgster to create user name and password
 * hash the passowrd and store it in file
 * using qhash
*/
void registerpage::on_pushButton_ok_clicked()
{
    //QFile binaryFile("/home/mary/Desktop/Mary_Hailu_HW5/GameApp/password.dat");
    QFile binaryFile("password.dat");
    bool check=false;
    QString username = ui->lineEdit_uname->text();
    QString password = ui->lineEdit_pword->text();
    QString password_again = ui->lineEdit_pagin->text();

    emit sendColorTogame(ui->comboBox_color->currentText());
    if(binaryFile.open(QIODevice::ReadOnly)){

        QTextStream in(&binaryFile); QString name, pass;
        while(!in.atEnd()){
            in >> name >> pass;

             if(username == name){
                QMessageBox::critical(this,"Username Already Exists","A user name with that name already exists");
                check = true;
             break;
            }
            else {
                check = false;
            }
        }
        binaryFile.close();
      }

    if(check == false ){

        QByteArray digest_pword = QByteArray(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1).toHex());
        hash.insert(username, digest_pword);
        QTextStream dataStream;

        if(password != password_again){
           QMessageBox::critical(this,"Password Do Not Match","The password fileds do not match each other");
         }

        else {
           if(binaryFile.open(QIODevice::WriteOnly | QIODevice::Append)){
           dataStream.setDevice(&binaryFile);
           QHashIterator<QString, QByteArray>i(hash);

           while(i.hasNext()){
                  i.next();
              dataStream<<i.key()<<" "<<i.value()<<endl;
             }
          }
         binaryFile.close();
         emit gohome();
    }
  }
}

/*
 * Return to home panal if button clicked
*/
void registerpage::on_pushButton_cancle_clicked()
{
   emit gohome();
}

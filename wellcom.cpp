#include <QDebug>
#include "wellcom.h"
#include "ui_wellcom.h"
#include "tictacmainpage.h"

/*
 *constructor
*/

wellcom::wellcom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wellcom)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&play);
    connect(&play, SIGNAL(gowelcom()), this, SLOT(backtowelcom()));
}

/*
 * destructor
*/
wellcom::~wellcom()
{
    delete ui;
}

/*
 * start game
*/
void wellcom::on_pushButton_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*
 * send the name to be dispalayes on penal
*/
void wellcom::showuname(QString uname)
{
     ui->label_showUname->setText(uname);
}

/*
 * return to welcome page
*/
void wellcom::backtowelcom(){
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * quit the program
*/
void wellcom::on_pushButton_exit_clicked()
{
    QApplication::quit();
}

/*
 * play the game
*/
void wellcom::readytoplay()
{
    ui->stackedWidget->setCurrentIndex(1);
}

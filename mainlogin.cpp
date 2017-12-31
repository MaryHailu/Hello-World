#include <QDebug>
#include "mainlogin.h"
#include "ui_mainlogin.h"

Mainlogin::Mainlogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainlogin)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&registerpage);
    connect(&registerpage, SIGNAL(mainpageClicked()), this, SLOT(moveMain()));

   // ui->stackedWidget->insertWidget(1, registerpage);
}

Mainlogin::~Mainlogin()
{
    delete ui;
}

void Mainlogin::on_pushButton_exit_clicked()
{
    this->close();
}

void Mainlogin::on_actionRegister_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->actionRegister->setDisabled(true);
}

void Mainlogin::on_pushButton_ok_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    qDebug()<<username<<" "<<password;
}

void Mainlogin::moveMain()
{
    ui->stackedWidget->setCurrentIndex(0);
}

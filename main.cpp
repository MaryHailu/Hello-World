#include "mainlogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainlogin w;
    w.show();

    return a.exec();
}

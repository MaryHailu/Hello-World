#include "tictacmainpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTacMainPage w;
    w.show();

    return a.exec();
}

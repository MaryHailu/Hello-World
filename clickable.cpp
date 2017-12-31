#include <QDebug>
#include "clickable.h"
/*
 * This is the clickable class defintion cpp file
 * it emits mouse pressed evenet
*/
Clickable::Clickable(QWidget* parent) : QLabel(parent)
{
}
Clickable::~Clickable(){}
void Clickable::mousePressEvent(QMouseEvent *)
{
    emit Mouse_Pressed();
}


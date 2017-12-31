#ifndef CLICKABLE_H
#define CLICKABLE_H
#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

/* This class is implenentd to prvide
   a clickable QLable*/

class Clickable : public QLabel
{
    Q_OBJECT
public:
    explicit Clickable(QWidget *parent = 0);
    ~Clickable();


protected:
    void mousePressEvent(QMouseEvent *);

signals:
    void Mouse_Pressed();

public slots:
};

#endif // CLICKABLE_H

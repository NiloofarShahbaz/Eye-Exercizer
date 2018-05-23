#ifndef SHAPE_H
#define SHAPE_H

#include <QKeyEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QDesktopWidget>
#include <QTimer>
#include <QGraphicsObject>


class Shape :public QGraphicsObject
{
    Q_OBJECT
public:
    Shape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void moveRightLeft();
    void moveUpDown();
    void moveflip();
    void bigandsmall();
    void randomPlace();
private:
    QTimer *timer;
    QRect *b;
};

#endif // SHAPE_H

#include "shape.h"

Shape::Shape()
{

    srand(time(NULL));
    QDesktopWidget dw;
    int startx=rand()%(dw.width()-520)+260;
    int starty=rand()%(dw.height()-320)+160;
    setPos(mapToParent(startx,starty));
    prepareGeometryChange();

}

QRectF Shape::boundingRect() const
{
    return QRectF(0,0,30,30);
}
bool start=true;
void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF circle=boundingRect();
    QBrush brush(QColor(Qt::darkGreen));
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawRect(circle);
}
int f=0;
void Shape::keyPressEvent(QKeyEvent *event)
{

        if(event->key()==Qt::Key_1){
            if(!start){
                timer->stop();
                timer=NULL;
            }
            setScale(1);
            timer=new QTimer(scene());
            connect(timer,SIGNAL(timeout()),this,SLOT(moveRightLeft()));
            timer->start(2);
            start=false;
        }

        else if(event->key()==Qt::Key_2){
            if(!start){
                timer->stop();
                timer=NULL;
            }
            setScale(1);
            timer=new QTimer(scene());
            connect(timer,SIGNAL(timeout()),this,SLOT(moveUpDown()));
            timer->start(2);
            start=false;
        }

        else if(event->key()==Qt::Key_3){
            if(!start){
                timer->stop();
                timer=NULL;
            }
            setScale(1);
            if(f==1){
                setPos((int)x(),(int)y());
            }
            timer=new QTimer(scene());
            connect(timer,SIGNAL(timeout()),this,SLOT(moveflip()));
            timer->start(2.5);
            start=false;
        }
        else if(event->key()==Qt::Key_4){
            QDesktopWidget dw;
            setPos(dw.width()/2-15,dw.height()/2-15);
            f=1;
            if(!start){
                timer->stop();
                timer=NULL;
            }
            timer=new QTimer(scene());
            connect(timer,SIGNAL(timeout()),this,SLOT(bigandsmall()));
            timer->start(1);
            start=false;
        }

        else if(event->key()==Qt::Key_5){
            if(!start){
                timer->stop();
                timer=NULL;
            }

            setScale(1);
            timer=new QTimer(scene());
            connect(timer,SIGNAL(timeout()),this,SLOT(randomPlace()));
            timer->start(2);
            start=false;
        }
}
int dir=1;

void Shape::moveRightLeft()
{
    if(scene()->collidingItems(this).isEmpty()==true){//no collision

        setPos(x()+dir,y());

    }
    else{

        dir=-(dir);
        setPos(x()+dir,y());
    }

}
void Shape::moveUpDown()
{
    if(scene()->collidingItems(this).isEmpty()==true){//no collision
        setPos(x(),y()+dir);
    }
    else{
        dir=-(dir);
        setPos(x(),y()+dir);
    }

}
float dir2=0.25;
void Shape::moveflip(){
        if(y()==scene()->sceneRect().topLeft().y() || y()+30==scene()->sceneRect().bottomLeft().y()){

            dir2=-(dir2);
            setPos(x()+dir,y()+dir2);

        }
        else if((x()==scene()->sceneRect().topLeft().x()) || (x()+30==scene()->sceneRect().topRight().x())){

            dir=-(dir);
            setPos(x()+dir,y()+dir2);
        }
        else {

            setPos(x()+dir,y()+dir2);
        }

}
int flag=0;
void Shape::bigandsmall(){
    if(scale()<=4 && flag==0){
        setScale(scale()+0.001);
        setPos(x()-0.015,y()-0.01);
                 return;
    }
    flag=1;
    if(flag==1){
        setScale(scale()-0.001);
        setPos(x()+0.015,y()+0.01);
    }
    if(scale()<1 && scale()>=0){
        flag=0;
    }
}
void Shape::randomPlace(){
    srand(time(NULL));
    QDesktopWidget dw;
    setPos(rand()%(dw.width()-520)+260,rand()%(dw.height()-320)+160);
}

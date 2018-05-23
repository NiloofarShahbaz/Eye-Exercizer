#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "shape.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("/home/niloo/Qtprojects/EyeExerciser/Circle-icons-eye.svg.png"));
    this->setWindowTitle("Eye Exerciser");

    QDesktopWidget dw;
    this->setFixedSize(dw.width(),dw.height());

    QRectF sceneRect(QPointF(200,100),QPointF(dw.width()-200,dw.height()-100));

    scene=new QGraphicsScene(this);
    scene->setSceneRect(sceneRect);

    QGraphicsView *gv=new QGraphicsView(this);
    gv->setFixedSize(dw.width(),dw.height());
    gv->setScene(scene);
    gv->setRenderHint(QPainter::Antialiasing);


    QPen mypen = QPen(Qt::darkGreen);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    Shape *circle=new Shape();
    scene->addItem(circle);

    QGraphicsTextItem *describtion=new QGraphicsTextItem("1-->horizontal movement    2-->vertical movement   3-->free movement   4-->shrink and grow   5-->random places ");
    describtion->setFont(QFont("times",16));
    describtion->setPos(TopLine.p2().x()-1500,55);
    scene->addItem(describtion);

    circle->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
    circle->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;

}

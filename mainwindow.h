#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QTimer>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H

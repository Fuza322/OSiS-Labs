#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    scene1 = new QGraphicsScene(ui->graphicsView);
    scene2 = new QGraphicsScene(ui->graphicsView_2);
    scene3 = new QGraphicsScene(ui->graphicsView_3);
    scene4 = new QGraphicsScene(ui->graphicsView_4);

    ui->graphicsView->setScene(scene1);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView_3->setScene(scene3);
    ui->graphicsView_4->setScene(scene4);

    QThread *thread= new QThread;
    MyClass *my = new MyClass(scene1, 1000);
    QThread *thread2= new QThread;
    MyClass *my2 = new MyClass(scene2, 500);
    QThread *thread3= new QThread;
    MyClass *my3 = new MyClass(scene3, 700);
    QThread *thread4= new QThread;
    MyClass *my4 = new MyClass(scene4, 300);

    my->moveToThread(thread);
    my2->moveToThread(thread2);
    my3->moveToThread(thread3);
    my4->moveToThread(thread4);

    connect(thread, SIGNAL(started()), my, SLOT(doWork())); connect(my, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread2, SIGNAL(started()), my2, SLOT(doWork())); connect(my2, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread3, SIGNAL(started()), my3, SLOT(doWork())); connect(my3, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread4, SIGNAL(started()), my4, SLOT(doWork())); connect(my4, SIGNAL(send(int)), this, SLOT(update(int)));

    thread->start();
    thread2->start();
    thread3->start();
    thread4->start();

    ui->pushButton->setEnabled(false);
}


void MainWindow::update (int i)
{
    repaint();
    qDebug() << i;
}

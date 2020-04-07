#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>

static bool isDraw = true;
static QPoint snek[20];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->setInterval(20);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout(){
    QPoint pos = QWidget::mapFromGlobal(QCursor::pos()) - QPoint(16,16);
    for (int i = 19; i >= 1; i--){
        snek[i] = snek[i-1];
    }
    snek[0] = pos;

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    if(isDraw)
    {
        QPainter *paint = new QPainter(this);

        paint->setPen(QPen(Qt::black, 0));
        paint->setRenderHint(QPainter::Antialiasing, true);

        paint->setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));

        for ( int i =0; i < 20; i++){
            paint->drawEllipse(snek[i].x(), snek[i].y(), 30, 30);
        }
        paint->end();
    }
}

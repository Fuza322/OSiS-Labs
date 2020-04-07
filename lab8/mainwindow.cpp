#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>

static int j = 0;
static bool isDraw = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->setInterval(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout(){
    j = (j + 1) % 360;
    repaint();
}

void movePoints(QPointF *points, int count, QPointF qpoint){
    for(int i = 0; i < count; i++){
        points[i] = points[i] + qpoint;
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    if(isDraw)
    {
        QPainter *paint = new QPainter(this);

        // Lights
        paint->setPen(QPen(Qt::blue, 2));
        paint->setRenderHint(QPainter::Antialiasing, true);

        paint->setBrush(QBrush(QColor::fromHsv(j, 255, 255), Qt::SolidPattern));
        paint->drawEllipse(50, 50, 50, 50);
        paint->drawEllipse(170, 110, 50, 50);
        paint->drawEllipse(290, 50, 50, 50);
        paint->drawEllipse(410, 110, 50, 50);
        paint->drawEllipse(530, 50, 50, 50);

        paint->setPen(QPen(Qt::darkMagenta, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        paint->drawLine(100, 75, 170, 135);
        paint->drawLine(220, 135, 290, 75);
        paint->drawLine(340, 75, 410, 135);
        paint->drawLine(460, 135, 530, 75);

        // Tree
        paint->setPen(QPen(Qt::darkGreen, 2, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin));

        QPointF level1[5] = {
            QPointF(220, 320),
            QPointF(250, 320),
            QPointF(270, 370),
            QPointF(200, 370),
          QPointF(220, 320)
        };

        QPointF level2[5] = {
              QPointF(220, 370),
              QPointF(250, 370),
              QPointF(290, 420),
              QPointF(180, 420),
            QPointF(220, 370)
        };

        QPointF level3[5] = {
            QPointF(220, 420),
            QPointF(250, 420),
            QPointF(310, 470),
            QPointF(160, 470),
          QPointF(220, 420)
        };

        QPointF toplevel[4] = {
            QPointF(235, 270),
            QPointF(250, 320),
            QPointF(220, 320),
            QPointF(235, 270)
        };

        QPointF star[5] = {
            QPointF(235, 270),
            QPointF(250, 255),
            QPointF(235, 230),
            QPointF(220, 255),
            QPointF(235, 270)
        };

        movePoints(level1, 4, QPointF(60, 0));
        paint->setBrush(QBrush(Qt::green, Qt::CrossPattern));
        paint->drawPolygon(level1, 4);

        movePoints(level2, 4, QPointF(60, 0));
        paint->drawPolygon(level2, 4);

        movePoints(level3, 4, QPointF(60, 0));
        paint->drawPolygon(level3, 4);

        movePoints(toplevel, 3, QPointF(60, 0));
        paint->drawPolygon(toplevel, 3);

        paint->setPen(QPen(Qt::yellow, 2, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin));
        movePoints(star, 4, QPointF(60, 0));
        paint->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        paint->drawPolygon(star, 4);

        paint->setPen(QPen(QColor(42, 42, 42), 2, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
        paint->setBrush(QBrush(QColor(84, 42, 42), Qt::SolidPattern));
        paint->drawRect(280, 470, 30, 30);

        // Gifts
        paint->setBrush(QBrush(Qt::magenta, Qt::SolidPattern));
        paint->drawRect(410, 460, 40, 40);
        paint->drawRect(460, 460, 40, 40);
        paint->drawRect(435, 420, 40, 40);

        paint->drawLine(455, 420, 460, 410);
        paint->drawLine(455, 420, 450, 410);
        paint->end();
    }
}

void MainWindow::on_pushButton_clicked()
{
    isDraw = !isDraw;
    if(isDraw)
        timer->start();
    else
        timer->stop();
    repaint();
}

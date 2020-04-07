#include "mainwindow.h"
#include "ui_mainwindow.h"

static int figure=0;
static QColor color = Qt::white;
static bool isDraw = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sw = new SecondWindow();
    connect(this, &MainWindow::sendMessage, sw, &SecondWindow::GetMessage);
    sw->show();

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
    if(ui->diamondButton->isChecked())
        figure = 1;
    else if(ui->circleButton->isChecked())
        figure = 2;
    else if(ui->squareButton->isChecked())
        figure = 3;
    else if(ui->starButton->isChecked())
        figure = 4;

    if(ui->redButton->isChecked())
        color = Qt::red;
    else if(ui->greenButton->isChecked())
        color = Qt::green;
    else if(ui->blueButton->isChecked())
        color = Qt::blue;

    isDraw = ui->isDraw->isChecked();

    emit sendMessage(figure, &color, isDraw);
}

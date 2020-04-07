#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QListWidget>

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

void MainWindow::on_addButton_clicked()
{
    QListWidget *leftlist = ui->leftList;
    QString input = ui->textEdit->text();
    bool isUnique = true;
    for(int i = 0; i < leftlist->count(); ++i)
    {
        QListWidgetItem* item = leftlist->item(i);
        if (item->text() == input) {
            isUnique = false;
            break;
        }
    }
    if(isUnique) {
        leftlist->addItem(input);
        ui->textEdit->clear();
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->leftList->clear();
    ui->rightList->clear();
}

void MainWindow::on_toRightButton_clicked()
{
    if(ui->leftList->currentItem() != nullptr) {
        ui->rightList->addItem( ui->leftList->currentItem()->text() );
        ui->leftList->removeItemWidget(ui->leftList->currentItem());
        delete ui->leftList->currentItem();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if(ui->leftList->currentItem() != nullptr) {
        ui->leftList->removeItemWidget(ui->leftList->currentItem());
        delete ui->leftList->currentItem();
    }
    if(ui->rightList->currentItem() != nullptr) {
        ui->rightList->removeItemWidget(ui->rightList->currentItem());
        delete ui->rightList->currentItem();
    }
}

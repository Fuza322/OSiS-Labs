#include "myclass.h"
#include <QDebug>
#include <windows.h>

MyClass::MyClass(QGraphicsScene* s, int interval) : scene(s), interval(interval)
{
}

void MyClass::doWork()
{
    for(int i = 0; ; i = (i+20)%359)
    {
        scene->setBackgroundBrush(QBrush(QColor::fromHsv(i,255, 255)));
        //emit send(interval);
        qDebug() << interval;
        Sleep(interval);
    }
}

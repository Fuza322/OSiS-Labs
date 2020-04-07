#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QGraphicsScene>

class MyClass:public QObject
{
Q_OBJECT
public:
    MyClass(QGraphicsScene* scene, int interval);
    QGraphicsScene* scene;
    int interval;
public slots:
    void doWork();
signals:
    void send(int);
private:

};

#endif // MYCLASS_H

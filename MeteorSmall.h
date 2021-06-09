#ifndef METEORSMALL_H
#define METEORSMALL_H
#include <QObject>
#include <QGraphicsPixmapItem>


class MeteorSmall: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MeteorSmall(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // METEORSMALL_H

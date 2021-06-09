#ifndef METEORBIG_H
#define METEORBIG_H
#include <QObject>
#include <QGraphicsPixmapItem>

class MeteorBig: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MeteorBig(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // METEORBIG_H

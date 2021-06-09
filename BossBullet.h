#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>

class BossBullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BossBullet(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // BOSSBULLET_H

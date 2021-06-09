#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>


class EnemyBullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    EnemyBullet(QGraphicsItem * parent=0);
public slots:
    void move();
};



#endif // ENEMYBULLET_H

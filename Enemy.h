#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
    void Shoot();
private:
    QMediaPlayer * bulletsound;
};

#endif // ENEMY_H

#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawnEnemy();
    void spawnOvni();
    void spawnMeteorBig();
    void spawnMeteorSmall();
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H

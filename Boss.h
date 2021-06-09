#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Boss:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boss(QGraphicsItem * parent=0);
    void bossgothit();
    int getBosshp();
public slots:
    void move();
    void Shoot();
private:
    int boss_hp;
    QMediaPlayer * bulletsound;
};

#endif // BOSS_H


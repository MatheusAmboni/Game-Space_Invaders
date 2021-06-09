#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "Game.h"
#include "Boss.h"
#include "BossBullet.h"

extern Game * game;

BossBullet::BossBullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // desenhar a bala
    setPixmap(QPixmap(":/images/laserGreen.png"));

    // conectar
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void BossBullet::move(){
    //se a bala colidir com o player diminuir vida
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i]))== typeid(Player)){
            //diminuir vida
            game->health->decrease();
            if(game->health->getHealth() == 0)
            {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //mover a bala pra baixo
    setPos(x(),y()+10);
    if(pos().y() > 810){
        scene()->removeItem(this);
        delete this;
    }
}

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bullet.h"
#include "Enemy.h"
#include "Ovni.h"
#include "MeteorBig.h"
#include "MeteorSmall.h"
#include "Game.h"
#include "Boss.h"
#include "GameWin.h"

extern Game * game; //tem um objeto externo global chamado game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //desenhar a bala
    setPixmap(QPixmap(":/images/laserGreen.png"));

    //conectar
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    //se a bala colidir com o inimigo destruir os dois
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //aumentar o score
            game->score->increase();
            //remover os dois
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deletar de verdade
            delete colliding_items[i];
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Ovni)){
            //aumentar o score
            game->score->increaseOvni();
            //remover os dois
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deletar de verdade
            delete colliding_items[i];
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(MeteorBig)){
            //remover os dois
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deletar de verdade
            delete colliding_items[i];
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(MeteorSmall)){
            //remover os dois
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deletar de verdade
            delete colliding_items[i];
            delete this;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(Boss)){
            scene()->removeItem(this);
            delete this;
            game->boss->bossgothit();
            if(game->boss->getBosshp() == 0)
            {
                game->scene->removeItem(colliding_items[i]);
                delete colliding_items[i];
                game->close();
                GameWin gamewin;
                gamewin.setModal(true);
                gamewin.exec();
            }
            return;
        }
    }
    //mover a bala pra cima
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

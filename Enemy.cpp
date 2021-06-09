#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() -> um int super grande
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //escolher a musica pra atirar
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

    //setar a posicao (aleatoria)
    int random_number = rand() % 1190;
    setPos(random_number,0);

    //desenhar a navezinha
    setPixmap(QPixmap(":/images/enemyShip1.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    //conectar
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //comecar o timer
    timer->start(50);

    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(Shoot()));
    timer2->start(2000);
}

void Enemy::move(){
    //mover o inimigo pra baixo
    setPos(x(),y()+5);
    if (pos().y() > 720){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::Shoot()
{
    EnemyBullet * enemybullet = new EnemyBullet();
    enemybullet->setPos(x()+50,y()+100);
    scene()->addItem(enemybullet);

    if(bulletsound->state() == QMediaPlayer::PlayingState)
    {
        bulletsound->setPosition(0);
    }
    else if(bulletsound->state() == QMediaPlayer::StoppedState)
    {
        bulletsound->play();
    }
}

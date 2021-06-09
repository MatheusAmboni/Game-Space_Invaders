#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "Boss.h"
#include "Health.h"
#include "Game.h"
#include "BossBullet.h"

Boss::Boss(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
   //escolher a musica pra atirar
   bulletsound = new QMediaPlayer();
   bulletsound->setMedia(QUrl("qrc:/sounds/blast.mp3"));

   //setar a posicao
   setPos(640,65);

   //desenhar o chefe
   setPixmap(QPixmap(":/images/boss.png"));
   setTransformOriginPoint(50,50);
   setRotation(180);
   boss_hp = 100;


   //conectar
   QTimer * timer = new QTimer();
   connect(timer,SIGNAL(timeout()), this, SLOT(move()));

   //comecar o timer
   timer->start(300);

   QTimer * timer2 = new QTimer();
   connect(timer2,SIGNAL(timeout()),this,SLOT(Shoot()));
   timer2->start(2000);
}

void Boss::move(){
    int random_number = 0+rand()%200-100;
    if(pos().x() + 250 + random_number > 800){
        setPos(x()-random_number,y());
    }
    else if(pos().x() + random_number < 0){
        setPos(x()-random_number,y());
    }
    else{
        setPos(x()+random_number, y());
    }
}

void Boss::Shoot()
{
    BossBullet * bossbullet = new BossBullet();
    bossbullet->setPos(x(),y());
    scene()->addItem(bossbullet);

    if(bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if(bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
}

void Boss::bossgothit(){
    boss_hp--;
}

int Boss::getBosshp()
{
    return boss_hp;
}

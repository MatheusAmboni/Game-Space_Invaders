#include <QGraphicsScene>
#include <QKeyEvent>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Ovni.h"
#include "MeteorBig.h"
#include "MeteorSmall.h"
#include "Boss.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
  bulletsound = new QMediaPlayer();
  bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

  //setar graficamente
  setPixmap(QPixmap(":/images/clipart2908532.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left) {
        if (pos() .x() > 0)
        setPos(x() -100,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos() .x() + 100 < 1280)
        setPos(x() +100,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos() .y() > 0)
        setPos(x(), y()-100);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos() .y() + 100 < 720)
         setPos(x(), y()+100);
    }
    else if (event->key() == Qt::Key_Space){

        //criar bala esquerda
        Bullet * bulletEsquerda = new Bullet();
        bulletEsquerda->setPos(x(),y()+30);
        scene()->addItem(bulletEsquerda);

        //criar bala meio
        Bullet * bulletMeio = new Bullet();
        bulletMeio->setPos(x() + 32,y() - 28);
        scene()->addItem(bulletMeio);

        //criar bala direita
        Bullet * bulletDireita = new Bullet();
        bulletDireita->setPos(x() + 63,y() +30);
        scene()->addItem(bulletDireita);

        //tocar som da bala
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawnEnemy(){
    //criar um inimigo
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawnOvni(){
    //criar um ovni
    Ovni * ovni= new Ovni();
    scene()->addItem(ovni);
}

void Player::spawnMeteorBig(){
    //criar um meteoro grande
    MeteorBig * meteorbig= new MeteorBig();
    scene()->addItem(meteorbig);
}

void Player::spawnMeteorSmall(){
    //criar um meteoro pequeno
    MeteorSmall * meteorsmall= new MeteorSmall();
    scene()->addItem(meteorsmall);
}









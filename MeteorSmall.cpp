#include "MeteorSmall.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() -> um int super grande
#include "Game.h"

extern Game * game;

MeteorSmall::MeteorSmall(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //setar a posicao (aleatoria)
    int random_number = rand() % 1200;
    setPos(random_number,0);

    //desenhar o meteorozinho
    setPixmap(QPixmap(":/images/meteorSmall1.png"));
    //setTransformOriginPoint(50,50);
    //setRotation(180);

    //conectar
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //comecar o timer
    timer->start(1000);
}

void MeteorSmall::move(){
    //mover o meteoro pra baixo
    setPos(x(),y()+15);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

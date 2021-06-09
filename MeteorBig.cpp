#include "MeteorBig.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() -> um int super grande
#include "Game.h"

extern Game * game;

MeteorBig::MeteorBig(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //setar a posicao (aleatoria)
    int random_number = rand() % 1200;
    setPos(random_number,0);

    //desenhar o meteorozao
    setPixmap(QPixmap(":/images/pngegg (1).png"));
    //setTransformOriginPoint(50,50);
    //setRotation(180);

    //conectar
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //comecar o timer
    timer->start(1000);
}

void MeteorBig::move(){
    //mover o meteoro pra baixo
    setPos(x(),y()+10);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

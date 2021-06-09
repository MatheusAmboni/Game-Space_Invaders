#include "Ovni.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() -> um int super grande
#include "Game.h"

extern Game * game;

Ovni::Ovni(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //setar a posicao (aleatoria)
    int random_number = rand() % 1200;
    setPos(random_number,0);

    //desenhar o ovnizinho
    setPixmap(QPixmap(":/images/enemyUFO1.png"));
    //setTransformOriginPoint(50,50);
    //setRotation(180);

    //conectar
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //comecar o timer
    timer->start(100);
}

void Ovni::move(){
    //mover o inimigo pra baixo
    if (pos().y() > 720){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

    int random_number = 0+rand()%150-50;
    if(pos().x() + 250 + random_number > 1280){
        setPos(x()-random_number,y()+5);
    }
    else if(pos().x() + random_number < 0){
        setPos(x()-random_number,y()+5);
    }
    else{
        setPos(x()+random_number, y()+5);
    }
}

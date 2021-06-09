#include "Health.h"
#include "Game.h"
#include <QFont>
#include "gameover.h"

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the health to 0
    health = 10;

    //fazer o texto
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    if (health == 0){
        game->close();
        GameOver GameOver;
        GameOver.setModal(true);
        GameOver.exec();
    }
}

int Health::getHealth(){
    return health;
}

#include "Game.h"
#include "Ovni.h"
#include "MeteorBig.h"
#include "Enemy.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QFont>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include "GameWin.h"
#include "gameover.h"

Game::Game(QWidget *parent){
        //criando cena
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1280,720);
        setBackgroundBrush(QBrush(QImage(":/images/ab.png")));

        setScene(scene);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1280,720);

        player = new Player();
        player->setPos(600,600);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        //adicionar o player na cena
        scene->addItem(player);

        //criar o score e health
        score = new Score();
        scene->addItem(score);
        health = new Health();
        health->setPos(health->x(),health->y()+25);
        scene->addItem(health);

        //spawnar nave inimiga
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawnEnemy()));
        timer->start(2000);

        //spawnar ovni
        QTimer * timerOvni = new QTimer();
        QObject::connect(timerOvni,SIGNAL(timeout()),player,SLOT(spawnOvni()));
        timerOvni->start(20000);

        //spawnar meteoro grande
        QTimer * timerMeteorBig = new QTimer();
        QObject::connect(timerMeteorBig,SIGNAL(timeout()),player,SLOT(spawnMeteorBig()));
        timerMeteorBig->start(10000);

        //spawnar meteoro pequeno
        QTimer * timerMeteorSmall = new QTimer();
        QObject::connect(timerMeteorSmall,SIGNAL(timeout()),player,SLOT(spawnMeteorSmall()));
        timerMeteorSmall->start(9000);

        show();
}

#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // comecar com score de 0
    score = 0;

    //fazer o texto
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

    //tocar cyberpunk de fundo
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Max Brhon - Cyberpunk [NCS Release].mp3"));
    //fazer nao parar de tocar
    if(music->state() == QMediaPlayer::PlayingState){
        music->setPosition(0);
    }
    else if (music->state() == QMediaPlayer::StoppedState){
        music->play();
    }

}

void Score::increase(){
    score++;
    if(score == 40){
        music = new QMediaPlayer(this);
        music->setMedia(QUrl("qrc:/sounds/light.mp3"));
        music->play();
    }
    if(score == 50)
    {
        music = new QMediaPlayer(this);
        music->setMedia(QUrl("qrc:/sounds/light.mp3"));
        music->play();
        game->boss = new Boss();
        game->scene->addItem(game->boss);
    }
    setPlainText(QString("Score: ") + QString::number(score)); // Score: +1
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increaseOvni(){
    score = score + 5;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: +5
}

int Score::getScore(){
    return score;
}

void Score::increase(int a)
{
    score+=a;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

#include "GameWin.h"
#include "ui_GameWin.h"
#include "Game.h"

extern Game * game;

GameWin::GameWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWin)
{
    ui->setupUi(this);

    ui->qscore->setText(QString::number(game->score->getScore()));
}

GameWin::~GameWin()
{
    delete ui;
}

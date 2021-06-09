#include "gameover.h"
#include "ui_gameover.h"
#include "Game.h"

extern Game * game;

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}


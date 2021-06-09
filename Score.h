#ifndef SCORE_H
#define SCORE_H

#include <QMediaPlayer>
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    void increase(int a);
    void increaseOvni();
    int getScore();
private:
    int score;
    QMediaPlayer * music;
};

#endif // SCORE_H

#ifndef OVNI_H
#define OVNI_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Ovni: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ovni(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // OVNI_H

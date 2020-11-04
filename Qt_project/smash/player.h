#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Player: public QGraphicsEllipseItem {
public:
    Player(qreal x, qreal y, qreal w, qreal h)
        : QGraphicsEllipseItem(x, y, w, h) {
        setSpanAngle(5120);
        setStartAngle(320);
    }

    void keyPressEvent(QKeyEvent *event);
private:
    int speed = 20;
};

#endif // PLAYER_H

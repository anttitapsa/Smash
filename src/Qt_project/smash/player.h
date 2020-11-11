#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>
#include <QTimer>

class Player: public QObject, public QGraphicsEllipseItem { // public QObject,
    Q_OBJECT
public:
    Player(QTimer* timer);
    void jump();
    std::bitset<4> key;
public slots:
    void gravity();
    void move();
private:
    int speed = 20;
    int jumpSpeed = 50;
    int falltime = 0;
    bool isfalling = true;
    bool hasJumped = false;
    int fallSpeed = 0;
    int groundpos = 620;
    QTimer* timer_;
    //

};

#endif // PLAYER_H

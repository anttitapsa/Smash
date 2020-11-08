#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>

class Player: public QObject, public QGraphicsEllipseItem { // public QObject,
    Q_OBJECT
public:
    Player();
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


    //

};

#endif // PLAYER_H

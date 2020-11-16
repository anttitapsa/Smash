#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>
#include <QTimer>
#include "platform.h"
class Player: public QObject, public QGraphicsEllipseItem { // public QObject,
    Q_OBJECT
public:
    Player(QTimer* timer,std::vector<Platform*> platforms);
    void jump();
    std::bitset<4> key;
public slots:
    void gravity();
    void move();
private:
    int speed = 20;
    int jumpSpeed = 50;
    float falltime = 0;
    bool isfalling = true;
    bool hasJumped = false;
    int fallSpeed = 0;
    int groundpos = 620;
    QTimer* timer_;
    int player_hight_ = 100;
    int player_widght_ = 50; // currently player is circle and r= 50
    std::vector<Platform*> platforms_;

    //

};

#endif // PLAYER_H

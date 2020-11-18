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
    Player();
    void jump();
    std::bitset<4> key;
    int lives_ = 3;
public slots:
    void gravity(const std::vector<Platform*> &platforms);
    void move();
    void SetPosition(int x, int y);
private:
    int speed = 20;
    int jumpSpeed = 50;
    float falltime = 0;
    bool isfalling = true;
    bool hasJumped = false;
    int fallSpeed = 0;
    int player_hight_ = 100;
    int player_widght_ = 50; // currently player is circle and r= 50

    //

};

#endif // PLAYER_H

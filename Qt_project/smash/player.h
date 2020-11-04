#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>

class Player: public QObject, public QGraphicsEllipseItem { // public QObject,
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void jump();
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

    std::bitset<4> key;

};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>
#include <QTimer>
#include "platform.h"
class Player: public QObject, public QGraphicsEllipseItem { // public QObject
public:
    Player();
    void jump();
    std::bitset<4> key;
    int lives_ = 3;
    void gravity(const std::vector<Platform*> &platforms);
    void move();
    void SetPosition(int x, int y);
    QGraphicsRectItem* shove(Player* rival);
    void isShoved(bool toward_right);
    void initialize();
private:
    int speed = 20;
    int jumpSpeed = 50;
    float falltime = 0;
    bool isfalling = true;
    bool facing_right_ = true;
    bool hasJumped = false;
    int fallSpeed = 0;
    int player_hight_ = 100;
    int player_widght_ = 100; // currently player is circle and r= 50
    std::vector<int> shove_dispositions_{100,80,60,40,20};
    bool was_shoved_ = false;
    unsigned int shovetime = 0;
    bool shove_dir_ = true;

    //

};

#endif // PLAYER_H

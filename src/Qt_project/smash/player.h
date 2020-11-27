#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>
#include <QTimer>
//#include <QPainterPath>
#include "platform.h"
class Player: public QObject, public QGraphicsPixmapItem { // public QObject,
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
    int player_widght_ = 60;
    QPainterPath shape() const;
    void reset_speed();
    void animate();

private:
    int speed = 5;
    int maxspeed = 20;
    int acceleration = 5;
    int jumpSpeed = 50;
    float falltime = 0;
    bool isfalling = true;
    bool facing_right_ = true;
    bool hasJumped = false;
    int fallSpeed = 0;
    int player_hight_ = 100;
    std::vector<int> shove_dispositions_{100,80,60,40,20};
    bool was_shoved_ = false;
    unsigned int shovetime = 0;
    bool shove_dir_ = true;

    bool is_animated = false;
    unsigned int animationtime = 0;
    std::vector<std::tuple<std::string, int>> *current_animation_;
    std::vector<std::tuple<std::string, int>> shove_animation_{{":/images/tupsu_shove1.png", 0},
                                              {":/images/tupsu_shove2.png",20},
                                              {":/images/tupsu_shove3.png",120},
                                              {":/images/tupsu_shove3.png",120},
                                              {":/images/tupsu_shove2.png",20},
                                              {":/images/tupsu_shove1.png",0},
                                              {":/images/tupsu",0}};
    //

};

#endif // PLAYER_H

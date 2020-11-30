#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <bitset>
#include <vector>
#include <QTimer>
#include <QString>
#include <QVector>
//#include <QPainterPath>
#include "platform.h"
class Player: public QObject, public QGraphicsPixmapItem { // public QObject,
public:
    Player(QVector<QString> graphics);
    void jump();
    std::bitset<4> key;
    int lives_ = 3;
    void gravity(const std::vector<Platform*> &platforms);
    void move();
    void SetPosition(int x, int y);
    bool shove(Player *rival); // bool determines if a sound is made
    void shove_hit();
    void isShoved(bool toward_right);
    void initialize();
    QPainterPath shape() const;
    void reset_speed();
    void animate();
    void fallingcheck();

    const int player_width = 60;
    const int player_height = 100;

private:
    // related to moving
    int speed = 5;
    const int maxspeed = 20;
    const int acceleration = 5;
    bool facing_right = true;

    // related to jumping...
    const int jumpSpeed = 50;
    bool hasJumped = false;
    // ...and falling
    int falltime = 0;
    const float gravity_strength = 0.7;
    bool is_falling = true;
    int fallSpeed = 0;
    bool is_on_platform = false;
    Platform* standing_on;

    // related to shoving
    Player *rival_;
    std::vector<int> shove_dispositions_{100,80,60,40,20};
    bool was_shoved = false;
    unsigned int shovetime = 0;
    bool shove_dir;
    bool can_shove = true;

    // related to animation implementation
    bool is_animated = false;
    unsigned int animationtime = 0;
    QVector<QString> graphics_;
    std::vector<std::tuple<QString, int>> *current_animation_;
    std::vector<std::tuple<QString, int>> shove_animation_;

};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <bitset>
#include <QTimer>
#include "platform.h"
class Player: public QObject, public QGraphicsPixmapItem {
public:
    Player(QVector<QString> graphics);
    std::bitset<4> key;
    void jump();
    void move();
    void gravity(const std::vector<Platform*> &platforms);
    void fallingcheck();
    void SetPosition(int x, int y);//needed at the start of the game and allways after dead
    bool shove(Player *rival); // bool determines if a sound is made
    void shove_hit();
    void isShoved(bool toward_right);
    void initialize();
    void reset_speed();
    QPainterPath shape() const;
    void animate();

    int lives_;
    const int player_width = 60;
    const int player_height = 100;
    Platform* dead_platform = NULL;
    Platform* standing_on;

private:
    // related to moving
    int speed = 5;
    const int maxspeed = 20;
    const int acceleration = 5;
    bool facing_right = true;

    // related to jumping...
    bool hasJumped = false;
    const int jumpSpeed = 50;  
    // related to falling
    int falltime = 0;
    const float gravity_strength = 0.7;
    bool is_falling = true;
    int fallSpeed = 0;
    bool is_on_platform = false;
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

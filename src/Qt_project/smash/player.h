#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <bitset>
#include <QTimer>
#include "platform.h"
class Player: public QObject, public QGraphicsPixmapItem {
public:
    Player(int index);//index for telling what starting picture to use because
    std::bitset<4> key;      //graphics_ at the start has only all of the starting pictures
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
    bool is_falling = true;
    int fallSpeed = 0;
    int falltime = 0;
    bool hasJumped = false;
    bool is_on_platform = false;
protected:
    // related to moving
    int speed = 5;
    int maxspeed;//determined at lakki.h and totoro.h
    const int acceleration = 5;
    bool facing_right = true;

    // related to jumping...
    const int jumpSpeed = 50;  
    float gravity_strength;// related to falling, determined at lakki.h and totoro.h

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
    //at the start starting pictures of players; re-determined at lakki.h and totoro.h
    QVector<QString> graphics_ = {":/images/tupsu.png",":/images/tupsu_2.png",":/images/totoro.png",":/images/totoro_2.png"};
    std::vector<std::tuple<QString, int>> *current_animation_;
    std::vector<std::tuple<QString, int>> shove_animation_;

};

#endif // PLAYER_H

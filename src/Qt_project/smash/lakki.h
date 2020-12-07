#ifndef LAKKI_H
#define LAKKI_H
#include "player.h"

class Lakki : public Player{
public:
    Lakki(int player_index) : Player(player_index){ gravity_strength = 0.7;
                                                    maxspeed = 23;
                                                    graphics_.clear();
                                                    graphics_ = pictures_[player_index];
                                                    shove_animation_ = {{graphics_[1], 0},
                                                                     {graphics_[2],60},
                                                                     {graphics_[3],120},
                                                                     {graphics_[3],120},
                                                                     {graphics_[2],60},
                                                                     {graphics_[1],0},
                                                                     {graphics_[0],0}};
                                               };
private:
    QVector<QVector<const char*>> pictures_ = {{":/images/tupsu.png", ":/images/tupsu_shove1.png", ":/images/tupsu_shove2.png", ":/images/tupsu_shove3.png", ":/images/tupsuleft.png"},
                                           {":/images/tupsu_2.png", ":/images/tupsu_shove1_2.png", ":/images/tupsu_shove2_2.png", ":/images/tupsu_shove3_2.png", ":/images/tupsuleft_2.png"}};

};
#endif // LAKKI_H

#ifndef TOTORO_H
#define TOTORO_H
#include "player.h"

class Totoro : public Player{
public:
    Totoro(int player_index)
        : Player(player_index){ gravity_strength = 0.5;
                                maxspeed = 20;
                                graphics_.clear();
                                graphics_ = pictures_[player_index-2]; // -2 because player_index either 2 or 3
                                shove_animation_ = {{graphics_[1], 0}, //in pictutes indexs are 0 and 1
                                                    {graphics_[2],20},
                                                    {graphics_[3],120},
                                                    {graphics_[3],120},
                                                    {graphics_[2],20},
                                                    {graphics_[1],0},
                                                    {graphics_[0],0}};
                             };
private:
    QVector<QVector<QString>> pictures_ = {{":/images/totoro.png", ":/images/totoro2.png", ":/images/totoro3.png", ":/images/totoro4.png", ":/images/totoro_left.png"},
                                           {":/images/totoro_2.png", ":/images/totoro2_2.png", ":/images/totoro3_2.png", ":/images/totoro4_2.png", ":/images/totoro_left_2.png"}};

};
#endif // TOTORO_H

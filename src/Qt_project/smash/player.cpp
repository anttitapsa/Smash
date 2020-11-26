#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QBrush>
#include <iostream>

Player::Player() {

    // Set player to be a pixitem
    setPixmap(QPixmap(":/images/tupsu.png").scaledToHeight(player_hight_));

}

void Player::gravity(const std::vector<Platform*> &platforms) {
    isfalling = true;

    int drop;
    if (hasJumped) {
        drop = -jumpSpeed + falltime * falltime; }
    else { drop = falltime * falltime; }

    if (drop > 0){
        for (Platform* p : platforms){
            if (p->Get_start_x() <= x()+ player_widght_ && x()+ player_widght_ <= p->Get_end_x()){
                if(y()+drop >= p->Get_y()-player_hight_ && p->Get_y()-player_hight_ >= y()){
                    setPos(x(),p->Get_y()-player_hight_);
                    isfalling = false;
                    hasJumped = false;
                    falltime = 0;
                    break;
                }}
    }}
    if (isfalling){
        setPos(x(),y()+drop);
        falltime = falltime + 0.75;
    }

}

void Player::move() {
    // scheme: key[0-3] = W,A,S,D
    //if (key[0]) {
    //    jump();
    //}
    if (key[1]) {
        setPos(x()-speed, y());
        setPixmap(QPixmap(":/images/tupsuleft.png").scaledToHeight(player_hight_));
    }
    if (key[3]) {
        setPos(x()+speed, y());
        setPixmap(QPixmap(":/images/tupsu.png").scaledToHeight(player_hight_));
    }

}

void Player::jump() {
    isfalling = true;
    hasJumped = true;
}
void Player::SetPosition(int x, int y){
    setPos(x,y);
}

#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QBrush>
#include <iostream>

Player::Player() {

    // Draw the player as an ellipse
    setRect(0, 0, 100, 100);
    setBrush(QColor("#000000"));
    setSpanAngle(5120);
    setStartAngle(320);

    // connect the player to a timer
    //connect(timer, SIGNAL(timeout()), this, SLOT(gravity()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //timer->start(20);
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
        setStartAngle(3200);
        facing_right_ = false;
    }
    if (key[3]) {
        setPos(x()+speed, y());
        setStartAngle(320);
        facing_right_ = true;
    }
    if (was_shoved_) {
        if(shovetime == shove_dispositions_.size()) {
            was_shoved_ = false;
        } else {
            if(shove_dir_) {
                setPos(x()+shove_dispositions_[shovetime], y());
            } else {
                setPos(x()-shove_dispositions_[shovetime], y());
            }

            ++shovetime;
        }
    }
}

void Player::jump() {
    isfalling = true;
    hasJumped = true;
}
void Player::SetPosition(int x, int y){
    setPos(x,y);
}

QGraphicsRectItem* Player::shove(Player *rival){
    if(facing_right_){
        if (rival->contains(rival->mapFromScene(QPointF(x()+1.2*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+1.2*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+1.8*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+1.8*player_widght_, y()+0.2*player_hight_)))) {
            rival->isShoved(true);
        }
        return new QGraphicsRectItem(x()+1.2*player_widght_, y()+0.2*player_hight_,0.6*player_widght_,0.6*player_hight_);
    } else {
        if (rival->contains(rival->mapFromScene(QPointF(x()-0.2*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-0.2*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-0.8*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-0.8*player_widght_, y()+0.2*player_hight_)))) {
            rival->isShoved(false);
        }
        return new QGraphicsRectItem(x()-0.8*player_widght_, y()+0.2*player_hight_,0.6*player_widght_,0.6*player_hight_);
    }
}

void Player::isShoved(bool toward_right) {
    was_shoved_ = true;
    shovetime = 0;
    shove_dir_ = toward_right;
}

void Player::initialize(){
    falltime = 0;
}

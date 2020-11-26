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
            if (p->Get_start_x() <= x()+ player_widght_ / 2 && x()+ player_widght_ / 2 <= p->Get_end_x()){
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
        if (speed <= maxspeed + acceleration) {
            speed += acceleration;
        }
        setPos(x()-speed, y());
        setPixmap(QPixmap(":/images/tupsuleft.png").scaledToHeight(player_hight_));
        facing_right_ = false;

    }
    if (key[3]) {
        if (speed <= maxspeed + acceleration) {
            speed += acceleration;
        }
        setPos(x()+speed, y());
        setPixmap(QPixmap(":/images/tupsu.png").scaledToHeight(player_hight_));
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
    is_animated = true;
    animationtime = 0;
    current_animation_ = &shove_animation_;
    if(facing_right_){
        if (rival->contains(rival->mapFromScene(QPointF(x()+1.1*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+1.1*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+2.0*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+2.0*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+2.9*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()+2.9*player_widght_, y()+0.2*player_hight_)))) {
            rival->isShoved(true);
        }
        return new QGraphicsRectItem(x()+1.1*player_widght_, y()+0.2*player_hight_,1.8*player_widght_,0.6*player_hight_);
    } else {
        if (rival->contains(rival->mapFromScene(QPointF(x()-0.1*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-0.1*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-1.0*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-1.0*player_widght_, y()+0.2*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-1.9*player_widght_, y()+0.8*player_hight_))) ||
            rival->contains(rival->mapFromScene(QPointF(x()-1.9*player_widght_, y()+0.2*player_hight_)))) {
            rival->isShoved(false);
        }
        return new QGraphicsRectItem(x()-1.9*player_widght_, y()+0.2*player_hight_,1.8*player_widght_,0.6*player_hight_);
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

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Player::reset_speed()
{
    speed = 5;
}

void Player::animate()
{
    if (is_animated) {
        if(animationtime == current_animation_->size()) {
            is_animated = false;
        } else {
            const char *newpiclocation = std::get<0>((*current_animation_)[animationtime]).c_str();
            if (facing_right_) {
                setPixmap(QPixmap(newpiclocation).scaledToHeight(player_hight_));
            } else {
                qreal offset = std::get<1>((*current_animation_)[animationtime]);
                setOffset(-offset,0);
                QPixmap newpicture = QPixmap(newpiclocation);
                setPixmap(newpicture.scaledToHeight(player_hight_).transformed(QTransform().scale(-1,1)));
            }

            ++animationtime;
        }
    }
}


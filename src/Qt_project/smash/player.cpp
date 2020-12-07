#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QBrush>

#include <iostream>


Player::Player(int index){
    // Set player to be a pixitem
    setPixmap(QPixmap(graphics_[index]).scaledToHeight(player_height));
};

void Player::gravity(const std::vector<Platform*> &platforms) {

    if(dead_platform != NULL){
        dead_platform->time_ -=1;
        if(dead_platform->time_ == 0 || !is_on_platform){
            if(standing_on == dead_platform){
                is_falling = true;
                is_on_platform = false;
            }
            delete dead_platform;
            dead_platform = NULL;
        }
    }

    if (is_falling){
        int drop;
        if (hasJumped) {
            drop = -jumpSpeed + falltime * falltime * gravity_strength; }
        else { drop = falltime * falltime * gravity_strength; }

        if (drop > 0){
            for (Platform* p : platforms){
                if (p->Get_start_x() <= x()+ player_width / 2 && x()+ player_width / 2 <= p->Get_end_x()){
                    if(y()+player_height+drop >= p->Get_y() && p->Get_y() >= y()+player_height){
                        setPos(x(),p->Get_y()-player_height);
                        standing_on = p;
                        is_on_platform = true;
                        is_falling = false;
                        hasJumped = false;
                        falltime = 0;
                        return;
                    }
                }
            }
            if(dead_platform != NULL){
                if (dead_platform->Get_start_x() <= x()+ player_width / 2 && x()+ player_width / 2 <= dead_platform->Get_end_x()){
                    if(y()+player_height+drop >= dead_platform->Get_y() && dead_platform->Get_y() >= y()+player_height){
                        setPos(x(),dead_platform->Get_y()-player_height);
                        standing_on = dead_platform;
                        is_on_platform = true;
                        is_falling = false;
                        hasJumped = false;
                        falltime = 0;
                        return;
                    }
                }
            }
        }
        setPos(x(),y()+drop);
        falltime = falltime + 1;
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
        if (is_on_platform) {
            fallingcheck();
        }
        setPixmap(QPixmap(graphics_[4]).scaledToHeight(player_height));
        facing_right = false;

    }
    if (key[3]) {
        if (speed <= maxspeed + acceleration) {
            speed += acceleration;
        }
        setPos(x()+speed, y());
        if (is_on_platform) {
            fallingcheck();
        }
        setPixmap(QPixmap(graphics_[0]).scaledToHeight(player_height));
        facing_right = true;
    }
    if (was_shoved) {
        if(shovetime == shove_dispositions_.size()) {
            was_shoved = false;
        } else {
            if(shove_dir) {
                setPos(x()+shove_dispositions_[shovetime], y());
            } else {
                setPos(x()-shove_dispositions_[shovetime], y());
            }
            if (is_on_platform) {
                fallingcheck();
            }
            ++shovetime;
        }
    }
}

void Player::SetPosition(int x, int y){
    setPos(x,y);
}

bool Player::shove(Player *rival){
    if (can_shove) {
        can_shove = false; // can shove again after shove animation has ended
        is_animated = true;
        animationtime = 0;
        current_animation_ = &shove_animation_;
        rival_ = rival;
        return true;
    }
    return false;
}

void Player::shove_hit() {
    if(facing_right){
        if (rival_->contains(rival_->mapFromScene(QPointF(x()+1.1*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()+1.1*player_width, y()+0.2*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()+2.0*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()+2.0*player_width, y()+0.2*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()+2.9*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()+2.9*player_width, y()+0.2*player_height)))) {
            rival_->isShoved(true);
        }
        //return new QGraphicsRectItem(x()+1.1*player_width, y()+0.2*player_height,1.8*player_width,0.6*player_height);
    } else {
        if (rival_->contains(rival_->mapFromScene(QPointF(x()-0.1*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()-0.1*player_width, y()+0.2*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()-1.0*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()-1.0*player_width, y()+0.2*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()-1.9*player_width, y()+0.8*player_height))) ||
            rival_->contains(rival_->mapFromScene(QPointF(x()-1.9*player_width, y()+0.2*player_height)))) {
            rival_->isShoved(false);
        }
        //return new QGraphicsRectItem(x()-1.9*player_width, y()+0.2*player_height,1.8*player_width,0.6*player_height);
    }
}

void Player::isShoved(bool toward_right) {
    was_shoved = true;
    shovetime = 0;
    shove_dir = toward_right;
}

void Player::initialize(){
    falltime = 0;
    fallSpeed = 0;
    is_falling = false;
    is_on_platform = true;
    hasJumped = false;
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
            can_shove = true;  // for now this is ok, since there are no other animations
            is_animated = false;
        } else {
            if (animationtime == 2) {
                shove_hit();
            }

            const char *newpiclocation = std::get<0>((*current_animation_)[animationtime]);

            if (facing_right) {
                setPixmap(QPixmap(newpiclocation).scaledToHeight(player_height));
            } else {
                qreal offset = std::get<1>((*current_animation_)[animationtime]);
                setOffset(-offset,0);
                QPixmap newpicture = QPixmap(newpiclocation);
                setPixmap(newpicture.scaledToHeight(player_height).transformed(QTransform().scale(-1,1)));
            }

            ++animationtime;
        }
    }
}

void Player::fallingcheck()
{
    if (standing_on->Get_start_x() >= x()+ player_width / 2 || x()+ player_width / 2 >= standing_on->Get_end_x()){
        is_falling = true;
    }
}

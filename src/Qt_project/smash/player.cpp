#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QBrush>
#include <iostream>
Player::Player(QTimer* timer, std::vector<Platform*> platforms)
    : timer_(timer), platforms_(platforms){

    // Draw the player as an ellipse
    setRect(0, 0, 100, 100);
    setBrush(QColor("#000000"));
    setSpanAngle(5120);
    setStartAngle(320);

    // connect the player to a timer
    connect(timer, SIGNAL(timeout()), this, SLOT(gravity()));
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);
}

void Player::gravity() {
    isfalling = true;

    int drop;
    if (hasJumped) {
        drop = -jumpSpeed + falltime * falltime; }
    else { drop = falltime * falltime; }

    if (drop > 0){
        for (Platform* p : platforms_){
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
        gravity();
        setStartAngle(3200);
    }
    if (key[3]) {
        setPos(x()+speed, y());
        gravity();
        setStartAngle(320);
    }
}

void Player::jump() {
    isfalling = true;
    hasJumped = true;
}



#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QBrush>

Player::Player(QTimer* timer) : timer_(timer) {

    // Draw the player as an ellipse
    setRect(0, 0, 100, 100);
    setBrush(QColor("#000000"));
    setSpanAngle(5120);
    setStartAngle(320);

    // connect the player to a timer

    connect(timer_, SIGNAL(timeout()), this, SLOT(gravity()));
    connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
}

void Player::gravity() {
    if (isfalling) {
        int drop;
        if (hasJumped) { drop = -jumpSpeed + falltime * falltime; } else { drop = falltime * falltime; }
        if (y() + drop > groundpos) {
            setPos(x(), groundpos);
            isfalling = false;
            hasJumped = false;
            falltime = 0;
        } else {
            setPos(x(), y() + drop);
            falltime++;
        }
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
    }
    if (key[3]) {
        setPos(x()+speed, y());
        setStartAngle(320);
    }
}

void Player::jump() {
    isfalling = true;
    hasJumped = true;
}



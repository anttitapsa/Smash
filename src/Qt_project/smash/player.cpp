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

/*
void Player::keyPressEvent(QKeyEvent *event) {

    int k = event->key();

    if (k == keybinds[0]) {
        if (!event->isAutoRepeat()) {
            jump();
        }
        key[0] = 1;
    } else if (k == keybinds[1]){
        key[1] = 1;
    } else if (k == keybinds[2]) {
        key[2] = 1;
    } else if (k == keybinds[3]) {
        key[3] = 1;
    }

    switch ( event->key() )
        {
        case keybinds.at(0):
            jump();
            //key[0] = 1;
            break;
        case keybinds[0]:
            key[1] = 1;
            break;
        case keybinds[0]:
            key[2] = 1;
            break;
        case keybinds[0]:
            key[3] = 1;
            break;
        }


}

void Player::keyReleaseEvent(QKeyEvent *event) {

    int k = event->key();

    if (k == keybinds[0]) {
        key[0] = 0;
    } else if (k == keybinds[1]){
        key[1] = 0;
    } else if (k == keybinds[2]) {
        key[2] = 0;
    } else if (k == keybinds[3]) {
        key[3] = 0;
    }


    switch ( event->key() )
    {
    case Qt::Key_W:
        //key[0] = 0;
        //qDebug() << "released W";
        break;
    case Qt::Key_A:
        key[1] = 0;
        //qDebug() << "released A";
        break;
    case Qt::Key_S:
        key[2] = 0;
        //qDebug() << "released S";
        break;
    case Qt::Key_D:
        key[3] = 0;
        //qDebug() << "released D";
        break;
    }

}*/

    /*  OLD MOVEMENT SCHEME
    if (event->key() == Qt::Key_A) {
        setPos(x()-speed, y());
        setStartAngle(3200);
        //qDebug() << "you pressed key A";
    }
    else if (event->key() == Qt::Key_D){
        setPos(x()+speed, y());
        setStartAngle(320);
        //qDebug() << "you pressed key D";
    }
    else if (event->key() == Qt::Key_W){
        jump();
        setStartAngle(1760);
        //qDebug() << "you pressed key W";
    }
    else if (event->key() == Qt::Key_S){
        setPos(x(), y()+speed);
        setStartAngle(4640);
        //qDebug() << "you pressed key S";
    }
    */



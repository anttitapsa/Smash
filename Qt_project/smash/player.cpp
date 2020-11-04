#include "player.h"
#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        setPos(x()-speed, y());
        setStartAngle(3200);
        qDebug() << "you pressed key A";
    }
    else if (event->key() == Qt::Key_D){
        setPos(x()+speed, y());
        setStartAngle(320);
        qDebug() << "you pressed key D";
    }
    else if (event->key() == Qt::Key_W){
        setPos(x(), y()-speed);
        setStartAngle(1760);
        qDebug() << "you pressed key W";
    }
    else if (event->key() == Qt::Key_S){
        setPos(x(), y()+speed);
        setStartAngle(4640);
        qDebug() << "you pressed key S";
    }


}

#include "game.h"
#include <QTimer>
#include <QTransform>
#include <QPoint>
#include <iostream>

Game::Game(QGraphicsScene *scene, QTimer *timer, Player *p1, Player *p2)
    : QGraphicsView(scene), timer_(timer), p1_(p1), p2_(p2) {

    keybinds.push_back(Qt::Key_W);
    keybinds.push_back(Qt::Key_A);
    keybinds.push_back(Qt::Key_S);
    keybinds.push_back(Qt::Key_D);

    keybinds.push_back(Qt::Key_Up);
    keybinds.push_back(Qt::Key_Left);
    keybinds.push_back(Qt::Key_Down);
    keybinds.push_back(Qt::Key_Right);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280, 720);
    setFocus();
    connect(timer_, SIGNAL(timeout()), this, SLOT(moveView()));
};

void Game::keyPressEvent(QKeyEvent *event)
{
    int k = event->key();

    if (k == keybinds[0]) {
        if (!event->isAutoRepeat()) {
            p1_->jump();
        }
        p1_->key[0] = 1;
    } else if (k == keybinds[1]){
        p1_->key[1] = 1;
    } else if (k == keybinds[2]) {
        p1_->key[2] = 1;
    } else if (k == keybinds[3]) {
        p1_->key[3] = 1;
    } else if (k == keybinds[4]) {
        if (!event->isAutoRepeat()) {
            p2_->jump();
        }
        p2_->key[0] = 1;
    } else if (k == keybinds[5]){
        p2_->key[1] = 1;
    } else if (k == keybinds[6]) {
        p2_->key[2] = 1;
    } else if (k == keybinds[7]) {
        p2_->key[3] = 1;
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    int k = event->key();

    if (k == keybinds[0]) {
        p1_->key[0] = 0;
    } else if (k == keybinds[1]){
        p1_->key[1] = 0;
    } else if (k == keybinds[2]) {
        p1_->key[2] = 0;
    } else if (k == keybinds[3]) {
        p1_->key[3] = 0;
    } else if (k == keybinds[4]) {
        p2_->key[0] = 0;
    } else if (k == keybinds[5]){
        p2_->key[1] = 0;
    } else if (k == keybinds[6]) {
        p2_->key[2] = 0;
    } else if (k == keybinds[7]) {
        p2_->key[3] = 0;
    }
}

void Game::moveView() {
    //std::cout << "moveView attempt: " << viewportTransform().dx() <<std::endl;
    translate(-rollspeed,0);
}

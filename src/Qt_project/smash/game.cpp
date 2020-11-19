#include "game.h"
#include <QTimer>
#include <QTransform>
#include <QPoint>
#include <iostream>

Game::Game(QGraphicsScene *scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms)
    : QGraphicsView(scene), timer_(timer), p1_(p1), p2_(p2), scene_(scene), platforms_(platforms) {

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
    connect(timer_, SIGNAL(timeout()), this, SLOT(gameTick()));
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
        if (!event->isAutoRepeat()) {
            QGraphicsLineItem* line = p1_->shove(p2_);
            scene_->addItem(line);
        }
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
        if (!event->isAutoRepeat()) {
            QGraphicsLineItem* line = p2_->shove(p1_);
            scene_->addItem(line);
        }
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
    dead_wall += rollspeed;
}

void Game::check_dead(){
    if(p1_->x() < dead_wall || p1_->y() > dead_ground){
        p1_->lives_ -= 1;
        if(p1_->lives_ != 0){
            p1_->SetPosition(dead_wall + 1000, 0);}
        std::cout << "Player 1 lives <3: " << p1_->lives_ << std::endl;
    }
    if(p2_->x() < dead_wall || p2_->y() > dead_ground){
        p2_->lives_ -= 1;
        if(p2_->lives_ != 0){
        p2_->SetPosition(dead_wall +1000, 0);}
        std::cout << "Player 2 lives <3: " << p2_->lives_ << std::endl;
    }
    if(p1_->lives_ == 0 || p2_->lives_ == 0){
        timer_->stop();
    }
}

void Game::gameTick() {
    moveView();
    p1_->gravity(platforms_);
    p2_->gravity(platforms_);
    p1_->move();
    p2_->move();
    check_dead();
}

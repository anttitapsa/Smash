#include "game.h"
#include <QTimer>
#include <QTransform>
#include <QPoint>
#include <cmath>
#include <iostream>

Game::Game(QGraphicsScene *scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms, QStackedWidget* stack,std::vector<QGraphicsPixmapItem*> hearts, qreal rollspeed_)
    : QGraphicsView(scene), timer_(timer), p1_(p1), p2_(p2), platforms_(platforms), stack_(stack), hearts_(hearts), rollspeed(rollspeed_) {

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
        p1_->reset_speed();
    } else if (k == keybinds[2]) {
        if (!event->isAutoRepeat()) {
            //QGraphicsRectItem* hitbox =
            p1_->shove(p2_);
            //scene_->addItem(hitbox);
        }
    } else if (k == keybinds[3]) {
        p1_->key[3] = 1;
        p1_->reset_speed();
    } else if (k == keybinds[4]) {
        if (!event->isAutoRepeat()) {
            p2_->jump();
        }
        p2_->key[0] = 1;
    } else if (k == keybinds[5]){
        p2_->key[1] = 1;
        p2_->reset_speed();
    } else if (k == keybinds[6]) {
        if (!event->isAutoRepeat()) {
            //QGraphicsRectItem* hitbox =
            p2_->shove(p1_);
            //scene_->addItem(hitbox);
        }
    } else if (k == keybinds[7]) {
        p2_->key[3] = 1;
        p2_->reset_speed();
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    int k = event->key();

    if (k == keybinds[0]) {
        p1_->key[0] = 0;
    } else if (k == keybinds[1]){
        p1_->key[1] = 0;
        p1_->reset_speed();
    } else if (k == keybinds[2]) {
        p1_->key[2] = 0;
    } else if (k == keybinds[3]) {
        p1_->key[3] = 0;
        p1_->reset_speed();
    } else if (k == keybinds[4]) {
        p2_->key[0] = 0;
    } else if (k == keybinds[5]){
        p2_->key[1] = 0;
        p2_->reset_speed();
    } else if (k == keybinds[6]) {
        p2_->key[2] = 0;
    } else if (k == keybinds[7]) {
        p2_->key[3] = 0;
        p2_->reset_speed();
    }
}

void Game::moveView() {
    translate(-rollspeed,0);
    dead_wall += rollspeed;
}

void Game::check_dead(){
    if(p1_->x() < dead_wall || p1_->y() > dead_ground){
        p1_->lives_ -= 1;
        if(p1_->lives_ != 0){
            player_to_above_platform(p1_);}
    }
    if(p2_->x() < dead_wall || p2_->y() > dead_ground){
        p2_->lives_ -= 1;
        if(p2_->lives_ != 0){
            player_to_above_platform(p2_);}
    }

    //updating player hearts position
    for(auto i : hearts_){i->setPos(0,dead_ground+50);}
    for(int l = 0; l < p1_->lives_; l++){hearts_[l]->setPos(dead_wall+330+l*40,30);}
    for(int j = 0; j < p2_->lives_; j++){hearts_[j+p1_->lives_]->setPos(dead_wall+1510-j*40,30);}

    //if game ends
    if(p1_->lives_ == 0 || p2_->lives_ == 0){
        timer_->stop();

        // add buttons to post-game screen
        QPushButton* exit_btn = new QPushButton();
        exit_btn->setGeometry(QRect(400,400,300,70));
        exit_btn->setText("Exit to main menu");
        QObject::connect(exit_btn, SIGNAL(clicked()),this, SLOT(ExitToMenu()));
        QGraphicsProxyWidget* proxy = scene()->addWidget(exit_btn);
        proxy->setPos(dead_wall+700,400);
    }
}
void Game::player_to_above_platform(Player* p){
    int x = dead_wall + 1000+p->player_widght_;
    bool above_platform = false;
    int distance = 1000; //1000, because big number needed
    int dis;
    for(auto plat : platforms_){
        //if x already on platform
        if(plat->Get_start_x() < x && x < plat->Get_end_x()){
            p->SetPosition(x,0);
            above_platform = true;
            break;}
        // distance between x and platform
        else{
            //platform after x
            if(x < plat->Get_start_x()){
                dis = plat->Get_start_x() - x + 2*p->player_widght_;} //2*p->player_widght_ so not at the edge
            //platform before x
            else{
                dis = plat->Get_end_x() - x - 2*p->player_widght_;}
            //is smallest distance
            if(abs(distance) > abs(dis)){
                distance = dis;}
        }
    }
    if (!above_platform){
        p->SetPosition(x+distance,0);}
}

void Game::ExitToMenu(){
    // clear & delete the Game and return to menu
    //scene()->clear();
    stack_->setCurrentIndex(0);
    stack_->removeWidget(this);
}

void Game::gameTick() {
    if (rollspeed != 0){moveView();}
    p1_->gravity(platforms_);
    p2_->gravity(platforms_);
    p1_->move();
    p2_->move();
    p1_->animate();
    p2_->animate();
    check_dead();
}

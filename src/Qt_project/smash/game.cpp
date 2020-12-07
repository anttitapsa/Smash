#include "game.h"

Game::Game(QGraphicsScene *scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms, QStackedWidget* stack,std::vector<QGraphicsPixmapItem*> hearts, std::vector<QGraphicsPixmapItem*> spikes,qreal rollspeed_, QString music_url, std::vector<Gingerbread*> ginger_)
    : QGraphicsView(scene), timer_(timer), p1_(p1), p2_(p2), platforms_(platforms), stack_(stack), hearts_(hearts), spikes_(spikes), rollspeed(rollspeed_), msource(music_url), ginger(ginger_) {

    /*
    keybinds.push_back(Qt::Key_W);
    keybinds.push_back(Qt::Key_A);
    keybinds.push_back(Qt::Key_S);
    keybinds.push_back(Qt::Key_D);
    keybinds.push_back(Qt::Key_Up);
    keybinds.push_back(Qt::Key_Left);
    keybinds.push_back(Qt::Key_Down);
    keybinds.push_back(Qt::Key_Right);
    */

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280, 720);
    setFocus();
    connect(timer_, SIGNAL(timeout()), this, SLOT(gameTick()));

    // Mediaplayers
    sound_effects = new QMediaPlayer();

    bg_music = new QMediaPlayer();
    QMediaPlaylist *loop = new QMediaPlaylist();

    loop->addMedia(QUrl(music_url));
    loop->setPlaybackMode(QMediaPlaylist::Loop);

     QFile file("options.txt");
     if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        int volume = in.readLine().toInt();
        bg_music->setVolume(volume);
        volume = in.readLine().toInt();
        sound_effects->setVolume(volume);
        QString bind;
        while (in.readLineInto(&bind)) {
            keybinds.push_back(bind.toInt());
        }
      }
    //read from default if no modifications have been made
    else{
        QFile file(":/textfiles/default_options.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        int volume = in.readLine().toInt();
        bg_music->setVolume(volume);
        volume = in.readLine().toInt();
        sound_effects->setVolume(volume);
        QString bind;
        while (in.readLineInto(&bind)) {
            keybinds.push_back(bind.toInt());
        }
    }

    //bg_music->setVolume(music_volume);
    bg_music->setPlaylist(loop);
    bg_music->play();

};

void Game::keyPressEvent(QKeyEvent *event)
{
int k = event->key();

    if (k == keybinds[0]) {
        if (!event->isAutoRepeat()) {
            jump(p1_);
        }
        p1_->key[0] = 1;
    } else if (k == keybinds[1]){
        p1_->key[1] = 1;
        p1_->reset_speed();
    } else if (k == keybinds[2]) {
        if (!event->isAutoRepeat()) {
            //QGraphicsRectItem* hitbox =
            if (p1_->shove(p2_)) {
                sound_effects->setMedia(QUrl("qrc:/sounds/woosh1.wav"));
                sound_effects->play();
            }
            //scene_->addItem(hitbox);
        }
    } else if (k == keybinds[3]) {
        p1_->key[3] = 1;
        p1_->reset_speed();
    } else if (k == keybinds[4]) {
        if (!event->isAutoRepeat()) {
            jump(p2_);
        }
        p2_->key[0] = 1;
    } else if (k == keybinds[5]){
        p2_->key[1] = 1;
        p2_->reset_speed();
    } else if (k == keybinds[6]) {
        if (!event->isAutoRepeat()) {
            //QGraphicsRectItem* hitbox =
            if (p2_->shove(p1_)) {
                sound_effects->setMedia(QUrl("qrc:/sounds/woosh2.wav"));
                sound_effects->play();
            }
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
    if(dead_wall <5320){ dead_wall += rollspeed;}
    //spikes update position
    for_each(spikes_.begin(), spikes_.end(),
            [this](QGraphicsPixmapItem* i) {
                i->setPos(dead_wall-55,i->y());
            });
}

void Game::check_dead(){
    if(p1_->x() < dead_wall || p1_->y() > dead_ground){
        p1_->lives_ -= 1;
        if(p1_->lives_ != 0){
            dead_platform(p1_);}
    }
    if(p2_->x() < dead_wall || p2_->y() > dead_ground){
        p2_->lives_ -= 1;
        if(p2_->lives_ != 0){
            dead_platform(p2_);}
    }

    //updating player hearts position
    for_each(hearts_.begin(), hearts_.end(),
             [this](QGraphicsPixmapItem* i){
            i->setPos(0,dead_ground+50);});
    for(int l = 0; l < p1_->lives_; l++){
        if(rollspeed == 0){
            hearts_[l]->setPos(dead_wall+330+l*40,30);}
        else{hearts_[l]->setPos(dead_wall+20+l*40,30);}
    }
    for(int j = 0; j < p2_->lives_; j++){
        if(rollspeed == 0){
            hearts_[j+p1_->lives_]->setPos(dead_wall+1510-j*40,30);}
        else {hearts_[j+p1_->lives_]->setPos(dead_wall+1170-j*40,30);}
    }
    //if game ends
    if(p1_->lives_ == 0 || p2_->lives_ == 0){
        timer_->stop();

        // add buttons to post-game screen
        QPushButton* exit_btn = new QPushButton();
        //exit_btn->setGeometry(QRect(400,400,300,70));
        //exit_btn->setText("Exit to main menu");
        exit_btn->setAttribute(Qt::WA_TranslucentBackground);
        exit_btn->setStyleSheet("QPushButton {background:url(:/images/main_return_btn.png) no-repeat;"
                                     "background-position: 50% 50%;"
                                     "border: 2 px solid black;"
                                     "height: 70 px;"
                                     "width: 300 px;"
                                     "border-radius: 10px;}"
                                 "QPushButton:open {border: 2px solid red}");
        exit_btn->move(400, 400);
        QObject::connect(exit_btn, SIGNAL(clicked()),this, SLOT(ExitToMenu()));
        QGraphicsProxyWidget* proxy = scene()->addWidget(exit_btn);
        proxy->setPos(dead_wall+700,400);
    }
}
void Game::dead_platform(Player* p){
    if(rollspeed== 0){
        p->SetPosition(638,0);
        p->initialize();
    }
    else{
        int x = dead_wall + 1000-2*p->player_width;//left_x
        if(p->dead_platform){
            delete p->dead_platform;
        }
        p->dead_platform = new Platform(x,450,200,100);
        scene()->addItem(p->dead_platform);
        p->SetPosition(x,450-p->player_height);
        p->initialize();
        p->standing_on = p->dead_platform;
    }
}
void Game::ExitToMenu(){
    // clear & delete the Game and return to menu
    //scene()->clear();
    bg_music->stop();
    stack_->setCurrentIndex(0);
    stack_->removeWidget(this);
}

void Game::gameTick() {
    if (rollspeed != 0){moveView();}//candyland move view
    else{dead_wall = -300;} // Game created expected dead_wall to be candylands +30
    p1_->gravity(platforms_);
    p2_->gravity(platforms_);
    p1_->move();
    p2_->move();
    p1_->animate();
    p2_->animate();
    check_dead();
    Croud();
}


void Game::Croud(){
    for_each(ginger.begin(), ginger.end(),
        [this](Gingerbread* i) {
        i->gravity();
        int num = std::rand()%100;
        if(num == 45 && !(i->hasJumped)){
            i->Cheer();
            jump(i);}
        if( num < 10 && !(i->hasJumped)){
            i->Cheer();}
        if( num > 90 && !(i->hasJumped) ){
            i->StopCheer();}
    });
}


template <typename T>
void Game::jump(T creature){
    if (!creature->is_falling || creature->falltime < 1) {
        creature->is_falling = true;
        creature->hasJumped = true;
        if(creature->is_on_platform){
            creature->is_on_platform = false;

            if(creature->standing_on == creature->dead_platform){
                creature->dead_platform->time_ = 2;}
        }
    }
}

#include "levelselect.h"

LevelSelect::LevelSelect(QGraphicsScene* scene, QStackedWidget *stack, int Player1, int Player2)
    : stack_(stack)
{   //Adding playerinfo to selection
    players_.push_back(Player1);
    players_.push_back(Player2);

    view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();
    // add items into the scene
    QPushButton* candy_btn = new QPushButton();
    candy_btn->setAttribute(Qt::WA_TranslucentBackground);
    candy_btn->setStyleSheet("QPushButton {background:url(:/images/Candyland_button.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 200 px;"
                                 "width: 300 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    candy_btn->move(150, 300);
    QObject::connect(candy_btn, SIGNAL(clicked()),this, SLOT(Option1()));
    scene->addWidget(candy_btn);

    QPushButton* amfi_btn = new QPushButton();
    amfi_btn->setAttribute(Qt::WA_TranslucentBackground);
    amfi_btn->setStyleSheet("QPushButton {background:url(:/images/Amfi_button.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 200 px;"
                                 "width: 300 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    amfi_btn->move(800, 300);
    QObject::connect(amfi_btn, SIGNAL(clicked()),this, SLOT(Option2()));
    scene->addWidget(amfi_btn);

    QPushButton* return_btn = new QPushButton();
    return_btn->setAttribute(Qt::WA_TranslucentBackground);
    return_btn->setStyleSheet("QPushButton {background:url(:/images/main_return_btn.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 50 px;"
                                 "width: 200 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    return_btn->move(1000, 600);
    QObject::connect(return_btn, SIGNAL(clicked()),this, SLOT(ReturnToMain()));
    scene->addWidget(return_btn);

    QLabel* label = new QLabel();
    label->setText("Lives (1-10):");
    label->setFont(QFont("Arial",12));
    label->setStyleSheet("color : white");
    label->setGeometry(QRect(20,50,150,20));
    label->setAttribute(Qt::WA_TranslucentBackground);
    scene->addWidget(label);

    line_ = new QLineEdit();
    line_->setGeometry(155,50,45,25);
    line_->setText("3");
    line_->setFont(QFont("Arial",14));
    line_->setAttribute(Qt::WA_TranslucentBackground);
    scene->addWidget(line_);


    //bg to main menu
    QString bg_name = ":/images/main_menu_bg.png";
    scene->setBackgroundBrush(QBrush(QImage(bg_name)));

}

void LevelSelect::Option1(){
    StartGame(1);
}
void LevelSelect::Option2(){
    StartGame(2);
}
void LevelSelect::StartGame(int game_nbr){
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    // create a global timer
    timer_ = new QTimer();
    timer_->start(20);

    // if candyland add spikes and gingerbreads
    std::vector<QGraphicsPixmapItem*> spikes;
    std::vector<Gingerbread*>ginger;
    if(game_nbr == 1){
        ginger = MakeCroud();
        for_each(ginger.begin(), ginger.end(),
                [scene](Gingerbread* s) {
                    scene->addItem(s);;
                });
        for (int i = 0; i < 50; i++){
            spikes.push_back(scene->addPixmap(QPixmap(":/images/nekku.PNG")));
            spikes[i]->setPos(0,(i-1)*15);
        }
    }

    //read platforms from file and add to list platforms
    int i = 0;
    std::vector<Platform*> platforms;

    QString filename = files_[game_nbr];
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QString line;

    while(!file.atEnd()){
        line = file.readLine();
        QStringList list = line.split(',');

        platforms.push_back(new Platform(list[0].toInt(),list[1].toInt(),list[2].toInt()));
        scene->addItem(platforms[i]);
        i++;
    }

    // create players to put into the scene
    Player *player1;
    Player *player2;
    if(players_[0] < 2 ) { player1 =  new Lakki(players_[0]);}
    else  {player1 =  new Totoro(players_[0]);}
    if(players_[1] < 2) { player2 =  new Lakki(players_[1]);}
    else  {player2 =  new Totoro(players_[1]);}

    //players starting positions
    if(game_nbr == 1){
        player1->SetPosition(500,0);
        player2->SetPosition(500,0);}
    else{
        player1->SetPosition(60,0);
        player2->SetPosition(1160,0);}


    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    //read number of lives
    QString text = line_->text();
    int lives = text.toInt();
    if (lives <= 0 || lives > 10){
        lives = 3;
    }
    player1->lives_ = lives;
    player2->lives_ = lives;

    //players hearts to the scene
    std::vector<QGraphicsPixmapItem*> hearts;
    for (int i = 0; i < lives*2; i++){
        hearts.push_back(scene->addPixmap(QPixmap(":/images/bitheart.PNG")));
        if(i < lives){
           hearts[i]->setPos(30+i*40,30);
        }
        else{hearts[i]->setPos(1330-i*40,30);}
    }

    //scene picture and size
    QString backround_name;
    QString music_name;
    qreal speed;
    if (game_nbr == 1){
        backround_name = ":/images/candyland";
        music_name = "qrc:/sounds/Aim_Nobly.mp3";
        scene->setSceneRect(0, 0, 6560, 720);
        speed = 2;}
    else {backround_name = ":/images/amfi.PNG";
          music_name = "qrc:/sounds/teekkarifinal.mp3";
          scene->setSceneRect(0, 0, 1300, 720);
          speed = 0;}

    // add a view
    Game * game = new Game(scene, timer_, player1, player2, platforms, stack_, hearts,spikes, speed, music_name, ginger);
    game->setTransformationAnchor(QGraphicsView::NoAnchor);
    game->setAlignment(Qt::AlignRight);
    game->setDragMode(QGraphicsView::ScrollHandDrag);
    game->show();
    QImage bg = QImage(backround_name);
    bg = bg.scaled(QSize(scene->width(), scene->height()));//, Qt::KeepAspectRatioByExpanding);
    scene->setBackgroundBrush(QBrush(bg));

    stack_->addWidget(game);
    stack_->removeWidget(view_);
    stack_->setCurrentIndex(3);

}

void LevelSelect::ReturnToMain(){
    stack_->setCurrentIndex(0);
    stack_->removeWidget(view_);
}

QGraphicsView* LevelSelect::GetView(){
    return view_;
}
std::vector<Gingerbread*> LevelSelect::MakeCroud(){
    std::vector<Gingerbread*> ginger;
    for (int i = 0; i < 175; i++){//joki 4750
        int y, x;
        //village
        if(i < 100){ x = 1600 + rand() % 2700;
                     y = 700 + rand()% 30;}
        //forest after village
        else if(i < 120) { x = 4300 + rand() % 480;
                           y = 660 + rand()% 70;}
        //forest after river
        else{ x = 5195 + rand() % (6530-5195);//6550 end of scene, so 6530 that gingerbreads can still be seen
               y = 660 + rand()% 70;}
        ginger.push_back(new Gingerbread(x,y));
    }
    return ginger;
}

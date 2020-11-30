#include "mainmenu.h"
#include "background.h"
#include "levelselect.h"
#include <vector>
#include <list>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QFile>
#include <QFont>
#include <QIcon>

MainMenu::MainMenu(QGraphicsScene* scene, QStackedWidget *stack)
    : stack_(stack)
{   view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();

    // add items into the scene
    QPushButton* start_btn = new QPushButton();
    start_btn->setGeometry(QRect(300,300,480,100));
    start_btn->setText("Level Select");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(OpenLevelSelect()));
    scene->addWidget(start_btn);



    //bg to main menu
    QString bg_name = ":/images/main_menu_bg.png";
    scene->setBackgroundBrush(QBrush(QImage(bg_name)));

}
/*
<<<<<<< HEAD
=======
void MainMenu::Option1(){
    StartGame(1);
}
void MainMenu::Option2(){
    StartGame(2);
}
void MainMenu::StartGame(int game_nbr){
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    // create a global timer
    timer_ = new QTimer();
    timer_->start(20);

    //read platforms from file and add to listplatforms
    int i = 0;
    std::vector<Platform*> platforms;

    QString filename = files_[game_nbr];
    QFile file(filename);
    file.open(QIODevice::ReadOnly);


    QString music_source = file.readLine();

    QString line;
    while(!file.atEnd()){
        line = file.readLine();
        QStringList list = line.split(',');

        platforms.push_back(new Platform(list[0].toInt(),list[1].toInt(),list[2].toInt()));
        scene->addItem(platforms[i]);
        i++;
    }
>>>>>>> sound_design*/



//<<<<<<< HEAD
void MainMenu::OpenLevelSelect(){
    QGraphicsScene* scene = new QGraphicsScene();
    LevelSelect* lvl_select = new LevelSelect(scene, stack_);
    scene->setSceneRect(0,0,1280,720);
    stack_->addWidget(lvl_select->GetView());
/*=======
    //read number of lives
    QString text = line_->text();
    int lives = text.toInt();
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
    qreal speed;
    if (game_nbr == 1){
        backround_name = ":/images/test_landscape";
        scene->setSceneRect(0, 0, 2560, 720);
        speed = 2;}
    else {backround_name = ":/images/amfi.PNG";
          scene->setSceneRect(0, 0, 1300, 720);
          speed = 0;}

    // add a view
    Game * game = new Game(scene, timer_, player1, player2, platforms, stack_, hearts, speed, music_source);
    game->setTransformationAnchor(QGraphicsView::NoAnchor);
    game->setAlignment(Qt::AlignRight);
    game->setDragMode(QGraphicsView::ScrollHandDrag);
    game->show();

    Background * bg = new Background(scene, backround_name);
>>>>>>> sound_design */

    stack_->setCurrentIndex(1);
    stack_->show();
}


QGraphicsView* MainMenu::GetView(){
    return view_;
}

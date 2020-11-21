#include "mainmenu.h"
#include "background.h"
#include <vector>
#include <list>
#include <QPixmap>
#include <QGraphicsPixmapItem>
MainMenu::MainMenu(QGraphicsScene* scene, QStackedWidget *stack)
    : stack_(stack)
{   view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();

    // add items into the scene
    QPushButton* start_btn = new QPushButton();
    start_btn->setGeometry(QRect(300,400,480,100));
    start_btn->setText("Start Game");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(StartGame()));
    QGraphicsProxyWidget* proxy = scene->addWidget(start_btn);

}

void MainMenu::StartGame(){

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    // create a global timer
    timer_ = new QTimer();
    timer_->start(20);

    //add platforms
    std::vector<std::vector<int>> coords = {{50,500,300},{400,500,250},{500,650,350},{1000,550,1300}};
    std::vector<Platform*> platforms;
    for(double i = 0; i < coords.size(); i++){
        platforms.push_back(new Platform(coords[i][0],coords[i][1],coords[i][2]));
        scene->addItem(platforms[i]);
    }

    // create an item to put into the scene
    Player *player1 =  new Player();
    Player *player2 =  new Player();
    player2->setBrush(QColor("#ffc0cb"));

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    //players hearts to the scene
    std::vector<QGraphicsPixmapItem*> hearts;
    for (int i = 0; i < 6; i++){
        hearts.push_back(scene->addPixmap(QPixmap(":/images/bitheart.PNG")));
        if(i < 3){
           hearts[i]->setPos(30+i*40,30);
        }
        else{hearts[i]->setPos(1330-i*40,30);}
    }


    // add a view
    Game * game = new Game(scene, timer_, player1, player2, platforms, stack_, hearts);
    game->setTransformationAnchor(QGraphicsView::NoAnchor);
    game->setAlignment(Qt::AlignRight);
    game->setDragMode(QGraphicsView::ScrollHandDrag);
    game->show();

    scene->setSceneRect(0, 0, 2560, 720);
    Background * bg = new Background(scene);

    stack_->addWidget(game);
    stack_->setCurrentIndex(1);

}

QGraphicsView* MainMenu::GetView(){
    return view_;
}

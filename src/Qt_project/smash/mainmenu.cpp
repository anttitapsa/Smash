#include "mainmenu.h"
#include "background.h"
#include <vector>

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
    std::vector<Platform*> platforms;
    Platform *platform = new Platform(50,500,300);
    scene->addItem(platform);
    platforms.push_back(platform);
    Platform *platform1 = new Platform(400,500,250);
    scene->addItem(platform1);
    platforms.push_back(platform1);
    Platform *platform2 = new Platform(500,650,350);
    scene->addItem(platform2);
    platforms.push_back(platform2);

    // create an item to put into the scene
    Player *player1 =  new Player();
    Player *player2 =  new Player();
    player2->setBrush(QColor("#ffc0cb"));

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    // add a view
    Game * game = new Game(scene, timer_, player1, player2, platforms);
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

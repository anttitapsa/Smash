#include "mainmenu.h"
#include "background.h"
#include <vector>
#include <list>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QFile>
#include <QFont>

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
    start_btn->setText("Start Game");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(Option1()));
    scene->addWidget(start_btn);

    QPushButton* amfi_btn = new QPushButton();
    amfi_btn->setGeometry(QRect(300,500,480,100));
    amfi_btn->setText("Start Amfi");
    QObject::connect(amfi_btn, SIGNAL(clicked()),this, SLOT(Option2()));
    scene->addWidget(amfi_btn);

    QLabel* label = new QLabel();
    label->setText("Lives (1-10):");
    label->setFont(QFont("Calibry Light",12));
    label->setGeometry(QRect(20,50,150,20));
    scene->addWidget(label);

    line_ = new QLineEdit();
    line_->setGeometry(155,50,45,25);
    line_->setText("3");
    line_->setFont(QFont("Calibry Light",14));
    scene->addWidget(line_);

}

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
    QString line;

    while(!file.atEnd()){
        line = file.readLine();
        QStringList list = line.split(',');

        platforms.push_back(new Platform(list[0].toInt(),list[1].toInt(),list[2].toInt()));
        scene->addItem(platforms[i]);
        i++;
    }

    // create an item to put into the scene
    Player *player1 =  new Player();
    Player *player2 =  new Player();
    player2->setBrush(QColor("#ffc0cb"));

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

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
    Game * game = new Game(scene, timer_, player1, player2, platforms, stack_, hearts, speed);
    game->setTransformationAnchor(QGraphicsView::NoAnchor);
    game->setAlignment(Qt::AlignRight);
    game->setDragMode(QGraphicsView::ScrollHandDrag);
    game->show();

    Background * bg = new Background(scene, backround_name);

    stack_->addWidget(game);
    stack_->setCurrentIndex(1);

}

QGraphicsView* MainMenu::GetView(){
    return view_;
}

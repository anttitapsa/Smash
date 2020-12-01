#include "levelselect.h"
#include <QFile>
#include <QFont>
#include <QIcon>

LevelSelect::LevelSelect(QGraphicsScene* scene, QStackedWidget *stack, QVector<QString> Player1, QVector<QString> Player2)
    : stack_(stack)
{   //Adding playerinfo to selection
    players_[1] = Player1;
    players_[2] = Player2;

    view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();
    // add items into the scene
    QPushButton* start_btn = new QPushButton();
    start_btn->setGeometry(QRect(150,400,300,100));
    start_btn->setText("Template map");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(Option1()));
    scene->addWidget(start_btn);

    QPushButton* amfi_btn = new QPushButton();
    amfi_btn->setGeometry(QRect(800,400,300,100));
    amfi_btn->setText("Amfi");
    QObject::connect(amfi_btn, SIGNAL(clicked()),this, SLOT(Option2()));
    scene->addWidget(amfi_btn);

    QPushButton* return_btn = new QPushButton();
    return_btn->setGeometry(QRect(1000,600,200,50));
    return_btn->setText("Return to main menu");
    QObject::connect(return_btn, SIGNAL(clicked()),this, SLOT(ReturnToMain()));
    scene->addWidget(return_btn);

    QLabel* label = new QLabel();
    label->setText("Lives (1-10):");
    label->setFont(QFont("Calibry Light",12));
    label->setStyleSheet("color : white");
    label->setGeometry(QRect(20,50,150,20));
    label->setAttribute(Qt::WA_TranslucentBackground);
    scene->addWidget(label);

    line_ = new QLineEdit();
    line_->setGeometry(155,50,45,25);
    line_->setText("3");
    line_->setFont(QFont("Calibry Light",14));
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
    Player *player1 =  new Player(players_[1]);
    Player *player2 =  new Player(players_[2]);


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
    // if candyland add spikes
    std::vector<QGraphicsPixmapItem*> spikes;
    if(game_nbr == 1){
        for (int i = 0; i < 50; i++){
            spikes.push_back(scene->addPixmap(QPixmap(":/images/nekku.PNG")));
            spikes[i]->setPos(0,(i-1)*15);
        }
    }
    //scene picture and size
    QString backround_name;
    qreal speed;
    if (game_nbr == 1){
        backround_name = ":/images/candyland";
        scene->setSceneRect(0, 0, 6560, 720);
        speed = 2;}
    else {backround_name = ":/images/amfi.PNG";
          scene->setSceneRect(0, 0, 1300, 720);
          speed = 0;}

    // add a view
    Game * game = new Game(scene, timer_, player1, player2, platforms, stack_, hearts,spikes, speed);
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

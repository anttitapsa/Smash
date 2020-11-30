#include "characterselect.h"

CharacterSelect::CharacterSelect(QGraphicsScene* scene, QStackedWidget *stack)
    : stack_(stack){
    view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();

    // add items into the scene
    QPushButton* totoro_p1_btn = new QPushButton();
    totoro_p1_btn->setGeometry(QRect(150,400,300,100));
    totoro_p1_btn->setText("Player 1 Totoro");
    QObject::connect(totoro_p1_btn, SIGNAL(clicked()),this, SLOT(TotoroP1()));
    scene->addWidget(totoro_p1_btn);

    QPushButton* totoro_p2_btn = new QPushButton();
    totoro_p2_btn->setGeometry(QRect(800,400,300,100));
    totoro_p2_btn->setText("Player 2 Totoro");
    QObject::connect(totoro_p2_btn, SIGNAL(clicked()),this, SLOT(TotoroP2()));
    scene->addWidget(totoro_p2_btn);

    QPushButton* tupsu_p1_btn = new QPushButton();
    tupsu_p1_btn->setGeometry(QRect(150,300,300,100));
    tupsu_p1_btn->setText("Player 1 Tupsu");
    QObject::connect(tupsu_p1_btn, SIGNAL(clicked()),this, SLOT(TupsuP1()));
    scene->addWidget(tupsu_p1_btn);

    QPushButton* tupsu_p2_btn = new QPushButton();
    tupsu_p2_btn->setGeometry(QRect(800,300,300,100));
    tupsu_p2_btn->setText("Player 2 Tupsu");
    QObject::connect(tupsu_p2_btn, SIGNAL(clicked()),this, SLOT(TupsuP2()));
    scene->addWidget(tupsu_p2_btn);

    QPushButton* level_btn = new QPushButton();
    level_btn->setGeometry(QRect(450,100,350,100));
    level_btn->setText("Level select");
    QObject::connect(level_btn, SIGNAL(clicked()),this, SLOT(OpenLevelSelect()));
    scene->addWidget(level_btn);

    QPushButton* return_btn = new QPushButton();
    return_btn->setGeometry(QRect(1000,600,200,50));
    return_btn->setText("Return to main menu");
    QObject::connect(return_btn, SIGNAL(clicked()),this, SLOT(ReturnToMain()));
    scene->addWidget(return_btn);

    //bg to main menu
    QString bg_name = ":/images/main_menu_bg.png";
    scene->setBackgroundBrush(QBrush(QImage(bg_name)));
    }

QGraphicsView* CharacterSelect::GetView(){
    return view_;
}
void CharacterSelect::TotoroP1(){
    Player1_ = characters_[2];
}

void CharacterSelect::TotoroP2(){
    Player2_ = characters_[2];
}

void CharacterSelect::TupsuP1(){
    Player1_ = characters_[1];
}

void CharacterSelect::TupsuP2(){
    Player2_ = characters_[1];
}

void CharacterSelect::ReturnToMain(){
    stack_->setCurrentIndex(0);
    stack_->removeWidget(view_);
}

void CharacterSelect::OpenLevelSelect(){
    if (Player1_.isEmpty() != 1 && Player2_.isEmpty() != 1){
        QGraphicsScene* scene = new QGraphicsScene();
        LevelSelect* lvl_select = new LevelSelect(scene, stack_, Player1_, Player2_);
        scene->setSceneRect(0,0,1280,720);
        stack_->addWidget(lvl_select->GetView());
        stack_->setCurrentIndex(2);
        stack_->show();
    }
}




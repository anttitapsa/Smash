#include "mainmenu.h"
#include "levelselect.h"
#include "options.h"
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
    start_btn->setAttribute(Qt::WA_TranslucentBackground);
    start_btn->setStyleSheet("QPushButton {background:url(:/images/start_game_btn.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 100 px;"
                                 "width: 300 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    start_btn->move(450,400);
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(OpenCharacterSelect()));
    scene->addWidget(start_btn);

    start_btn->setGeometry(QRect(250,300,300,100));
    start_btn->setText("Start game");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(OpenCharacterSelect()));
    scene->addWidget(start_btn);

    QPushButton* options_btn = new QPushButton();
    options_btn->setGeometry(QRect(700,300,300,100));
    options_btn->setText("Options");
    QObject::connect(options_btn, SIGNAL(clicked()),this, SLOT(OpenOptions()));
    scene->addWidget(options_btn);

    //bg to main menu
    QString bg_name = ":/images/main_menu_bg.png";
    scene->setBackgroundBrush(QBrush(QImage(bg_name)));

}

void MainMenu::OpenCharacterSelect(){
    QGraphicsScene* scene = new QGraphicsScene();
    CharacterSelect* chr_select = new CharacterSelect(scene, stack_);
    scene->setSceneRect(0,0,1280,720);
    stack_->addWidget(chr_select->GetView());
    stack_->setCurrentIndex(1);
    stack_->show();
}

// Method to create and show options

void MainMenu::OpenOptions(){
    QGraphicsScene* scene = new QGraphicsScene();
    Options* options = new Options(scene, stack_);
    scene->setSceneRect(0,0,1280,720);
    stack_->addWidget(options->GetView());
    stack_->setCurrentIndex(1);
    stack_->show();
}


QGraphicsView* MainMenu::GetView(){
    return view_;
}

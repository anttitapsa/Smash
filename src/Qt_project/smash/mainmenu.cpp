#include "mainmenu.h"

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
    start_btn->setText("Start game");
    QObject::connect(start_btn, SIGNAL(clicked()),this, SLOT(OpenCharacterSelect()));
    scene->addWidget(start_btn);

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


QGraphicsView* MainMenu::GetView(){
    return view_;
}

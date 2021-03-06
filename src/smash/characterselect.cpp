#include "characterselect.h"

CharacterSelect::CharacterSelect(QGraphicsScene* scene, QStackedWidget *stack)
    : scene_(scene), stack_(stack){
    view_ = new QGraphicsView(scene_);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();
    if (Player1_ != -1){
        Player1_ = -1;
    }
    if (Player2_ != -1){
        Player2_ = -1;
    }
    Player1_text_->setPos(150, 500);
    Player1_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player1_text_->setDefaultTextColor(QColor(Qt::blue));
    Player2_text_->setPos(800, 500);
    Player2_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player2_text_->setDefaultTextColor(QColor(Qt::red));
    // add items into the scene
    QPushButton* totoro_p1_btn = new QPushButton();
    totoro_p1_btn->setAttribute(Qt::WA_TranslucentBackground);
    totoro_p1_btn->setStyleSheet("QPushButton {image:url(:/images/totoro.png) no-repeat;"
                                              "background:transparent;"
                                              "border: 2 px solid black;"
                                              "height: 200px;"
                                              "width: 130px;"
                                              "border-radius: 10px;}"
                                "QPushButton:pressed {border: 2px solid blue}");
    totoro_p1_btn->move(150,300);
    QObject::connect(totoro_p1_btn, SIGNAL(clicked()),this, SLOT(TotoroP1()));
    scene_->addWidget(totoro_p1_btn);

    QPushButton* tupsu_p1_btn = new QPushButton();
    tupsu_p1_btn->setAttribute(Qt::WA_TranslucentBackground);
    tupsu_p1_btn->setStyleSheet("QPushButton {image:url(:/images/tupsu_button.png) no-repeat;"
                                             "background:transparent;"
                                             "border: 2 px solid black;"
                                             "height: 200px;"
                                             "width: 130px;"
                                             "border-radius: 10px;}"
                                "QPushButton:open {border: 2px solid blue}");
    tupsu_p1_btn->move(280,300);
    QObject::connect(tupsu_p1_btn, SIGNAL(clicked()),this, SLOT(TupsuP1()));
    scene_->addWidget(tupsu_p1_btn);

    QPushButton* totoro_p2_btn = new QPushButton();
    totoro_p2_btn->setAttribute(Qt::WA_TranslucentBackground);
    totoro_p2_btn->setStyleSheet("QPushButton {image:url(:/images/totoro_2.png) no-repeat;"
                                              "background:transparent;"
                                              "border: 2 px solid black;"
                                              "height: 200px;"
                                              "width: 130px;"
                                              "border-radius: 10px;}"
                                 "QPushButton:open {border: 2px solid red}");
    totoro_p2_btn->move(800,300);
    QObject::connect(totoro_p2_btn, SIGNAL(clicked()),this, SLOT(TotoroP2()));
    scene_->addWidget(totoro_p2_btn);

    QPushButton* tupsu_p2_btn = new QPushButton();
    tupsu_p2_btn->setAttribute(Qt::WA_TranslucentBackground);
    tupsu_p2_btn->setStyleSheet("QPushButton {image:url(:/images/tupsu_2_button.png) no-repeat;"
                                             "background:transparent;"
                                             "border: 2 px solid black;"
                                             "height: 200px;"
                                             "width: 130px;"
                                             "border-radius: 10px;}"
                                "QPushButton:open {border: 2px solid red}");
    tupsu_p2_btn->move(930,300);
    QObject::connect(tupsu_p2_btn, SIGNAL(clicked()),this, SLOT(TupsuP2()));
    scene_->addWidget(tupsu_p2_btn);


    QPushButton* level_btn = new QPushButton();
    //set select button image by using CSS
    level_btn->setAttribute(Qt::WA_TranslucentBackground);
    level_btn->setStyleSheet("QPushButton {background:url(:/images/level_select_btn.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 100 px;"
                                 "width: 300 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    level_btn->move(450,100);
    QObject::connect(level_btn, SIGNAL(clicked()),this, SLOT(OpenLevelSelect()));
    scene_->addWidget(level_btn);

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
    scene_->addWidget(return_btn);

    //bg to main menu
    QString bg_name = ":/images/main_menu_bg.png";
    scene_->setBackgroundBrush(QBrush(QImage(bg_name)));
    }

QGraphicsView* CharacterSelect::GetView(){
    return view_;
}
void CharacterSelect::TotoroP1(){
    Player1_ = 2;
    scene_->removeItem(Player1_text_);
    Player1_text_ = scene_->addText(QString("Player 1: Totoro"));
    Player1_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player1_text_->setDefaultTextColor(QColor(Qt::blue));
    Player1_text_->setPos(150, 500);
}

void CharacterSelect::TotoroP2(){
    Player2_ = 3;
    scene_->removeItem(Player2_text_);
    Player2_text_ = scene_->addText(QString("Player 2: Totoro"));
    Player2_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player2_text_->setDefaultTextColor(QColor(Qt::red));
    Player2_text_->setPos(800, 500);
}

void CharacterSelect::TupsuP1(){
    Player1_ = 0;
    scene_->removeItem(Player1_text_);
    Player1_text_ = scene_->addText(QString("Player 1: Tupsu"));
    Player1_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player1_text_->setDefaultTextColor(QColor(Qt::blue));
    Player1_text_->setPos(150, 500);
}

void CharacterSelect::TupsuP2(){
    Player2_ = 1;
    scene_->removeItem(Player2_text_);
    Player2_text_ = scene_->addText(QString("Player 2: Tupsu"));
    Player2_text_->setFont(QFont("Arial", 18, QFont::Bold));
    Player2_text_->setDefaultTextColor(QColor(Qt::red));
    Player2_text_->setPos(800, 500);
}

void CharacterSelect::ReturnToMain(){
    stack_->setCurrentIndex(0);
    stack_->removeWidget(view_);
}

void CharacterSelect::OpenLevelSelect(){
    if (Player1_!= -1 && Player2_ != -1){
        QGraphicsScene* scene = new QGraphicsScene();
        LevelSelect* lvl_select = new LevelSelect(scene, stack_, Player1_, Player2_);
        scene->setSceneRect(0,0,1280,720);
        stack_->addWidget(lvl_select->GetView());
        stack_->setCurrentIndex(2);
        stack_->show();
        stack_->removeWidget(view_);
    }
}

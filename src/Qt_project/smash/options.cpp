#include "options.h"

Options::Options(QGraphicsScene* scene, QStackedWidget *stack)
    : stack_(stack)
{   view_ = new QGraphicsView(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();

    // add items into the scene

    QPushButton* return_btn = new QPushButton();
    return_btn->setGeometry(QRect(1000,600,200,50));
    return_btn->setText("Return to main menu");
    QObject::connect(return_btn, SIGNAL(clicked()),this, SLOT(ReturnToMain()));
    scene->addWidget(return_btn);

    QSlider* volume_slider = new QSlider();
    volume_slider->setOrientation(Qt::Horizontal);
    volume_slider->setMaximum(100);
    volume_slider->setMinimum(0);
    volume_slider->setTickInterval(1);
    volume_slider->setGeometry(QRect(300,200,300,50));
    volume_slider->setStyleSheet("background-color: transparent");
    scene->addWidget(volume_slider);

    // background
    QString bg_name = ":/images/main_menu_bg.png";
    scene->setBackgroundBrush(QBrush(QImage(bg_name)));
}

QGraphicsView* Options::GetView(){
    return view_;
}

void Options::ReturnToMain(){
    stack_->setCurrentIndex(0);
    stack_->removeWidget(view_);
}
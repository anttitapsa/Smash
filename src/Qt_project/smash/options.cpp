#include "options.h"
#include <QDebug>
#include <QFileInfo>

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

    QPushButton* save_btn = new QPushButton();
    save_btn->setGeometry(QRect(600,600,200,60));
    save_btn->setText("Save options");
    QObject::connect(save_btn, SIGNAL(clicked()),this, SLOT(SaveOptions()));
    scene->addWidget(save_btn);

    volume_slider_ = new QSlider();
    volume_slider_->setOrientation(Qt::Horizontal);
    volume_slider_->setMaximum(100);
    volume_slider_->setMinimum(0);
    volume_slider_->setTickInterval(1);

    // could move reading the file into its own method

    //could also make a separate default options.txt file from which the options are
    //loaded if no options.txt exists

    QFile file("options.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        int value = in.readLine().toInt();
        volume_slider_->setValue(value);
    }
    // read from default_options.txt if no modifications have been made
    else{
        QFile file(":/textfiles/default_options.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        int value = in.readLine().toInt();
        volume_slider_->setValue(value);
    }

    volume_slider_->setGeometry(QRect(300,200,300,50));
    volume_slider_->setStyleSheet("background-color: transparent");

    scene->addWidget(volume_slider_);

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

void Options::SaveOptions(){
    //this creates the file in the makefile/build directory... not optimal?

    QFile file("options.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);


    QTextStream out(&file);
    out << volume_slider_->value() << "\n";

}

#include "options.h"
#include <QDebug>
#include <QFileInfo>
#include <iostream>

Options::Options(QGraphicsScene* scene, QStackedWidget *stack)
    : stack_(stack), scene_(scene)
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

    QPushButton* keybinds_btn = new QPushButton();
    keybinds_btn->setGeometry(QRect(200,600,200,60));
    keybinds_btn->setText("Set keybinds");
    QObject::connect(keybinds_btn, SIGNAL(clicked()),this, SLOT(SetKeybinds()));
    scene->addWidget(keybinds_btn);

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

void Options::keyPressEvent(QKeyEvent *event)
{
    if (setting_keybinds) {
        keybinds_.push_back(event->key());
        ++at_key;
        SetKeybinds();
    }
    std::cout << event->key() << std::endl;
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

    for (int key : keybinds_) {
        out << key << "\n";
    }

}

void Options::SetKeybinds() {
    if (at_key < descriptors_.size()) {
        setting_keybinds = true;
        QGraphicsTextItem *desc = scene_->addText(descriptors_[at_key]);
        desc->setFont(QFont("Arial", 18, QFont::Bold));
        desc->setDefaultTextColor(QColor(Qt::red));
        desc->setPos(100 + 300 * at_key / 4, 300 + 30 * at_key % 80);
        keybind_texts.push_back(desc);
    } else {
        setting_keybinds = false;
    }
}

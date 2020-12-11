#include "options.h"

Options::Options(QGraphicsScene* scene, QStackedWidget *stack)
    : QGraphicsView(scene), stack_(stack), scene_(scene)
{   view_ = new Options_view(scene);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setFixedSize(1280, 720);
    view_->setFocus();

    // add items into the scene

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
    scene->addWidget(return_btn);

    QPushButton* save_btn = new QPushButton();
    save_btn->setAttribute(Qt::WA_TranslucentBackground);
    save_btn->setStyleSheet("QPushButton {background:url(:/images/save_settings_btn.png) no-repeat;"
                                 "background-position: 50% 50%;"
                                 "border: 2 px solid black;"
                                 "height: 60 px;"
                                 "width: 200 px;"
                                 "border-radius: 10px;}"
                             "QPushButton:open {border: 2px solid red}");
    save_btn->move(600, 600);
    QObject::connect(save_btn, SIGNAL(clicked()),this, SLOT(SaveOptions()));
    scene->addWidget(save_btn);

    volume_slider_ = new QSlider();
    volume_slider_->setOrientation(Qt::Horizontal);
    volume_slider_->setMaximum(100);
    volume_slider_->setMinimum(0);
    volume_slider_->setTickInterval(1);

    sfx_slider_ = new QSlider();
    sfx_slider_->setOrientation(Qt::Horizontal);
    sfx_slider_->setMaximum(100);
    sfx_slider_->setMinimum(0);
    sfx_slider_->setTickInterval(1);

    // could move reading the file into its own method

    //could also make a separate default options.txt file from which the options are
    //loaded if no options.txt exists

    QFile file("options.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        int value = in.readLine().toInt();
        volume_slider_->setValue(value);

        value = in.readLine().toInt();
        sfx_slider_->setValue(value);

        for(unsigned int i = 0; i < 8; i++){
            int value = in.readLine().toInt();
            keybinds_.push_back(value);
        }
    }
    // read from default_options.txt if no modifications have been made
    else{
        QFile file(":/textfiles/default_options.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        int value = in.readLine().toInt();
        volume_slider_->setValue(value);

        value = in.readLine().toInt();
        sfx_slider_->setValue(value);

        for(unsigned int i = 0; i < 8; i++){
            int value = in.readLine().toInt();
            keybinds_.push_back(value);
        }


    }

    volume_slider_->setGeometry(QRect(300,200,300,50));
    volume_slider_->setStyleSheet("background-color: transparent");
    QGraphicsTextItem* slider_desc = scene_->addText("Music volume");
    slider_desc->setFont(QFont("Arial", 12, QFont::Bold));
    slider_desc->setDefaultTextColor(QColor(Qt::white));
    slider_desc->setPos(325, 150);

    sfx_slider_->setGeometry(QRect(300,400,300,50));
    sfx_slider_->setStyleSheet("background-color: transparent");
    QGraphicsTextItem* sfx_desc = scene_->addText("SFX volume");
    sfx_desc->setFont(QFont("Arial", 12, QFont::Bold));
    sfx_desc->setDefaultTextColor(QColor(Qt::white));
    sfx_desc->setPos(325, 350);

    scene->addWidget(volume_slider_);
    scene->addWidget(sfx_slider_);

    Options::CreateButtons();

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
    out << sfx_slider_->value() << "\n";

    for (int key : keybinds_) {
        out << key << "\n";
    }

}


// new approach
void Options::SetKeybinds(){
    QTimer timer;
    QEventLoop loop;
    connect( this, &Options::QuitLoop, &loop, &QEventLoop::quit );
    connect(&timer, SIGNAL(timeout()), this, SLOT(SetKeyValue()));
    timer.start(50);
    loop.exec();

    QPushButton* sender_button = qobject_cast<QPushButton*>(sender());
    sender_button->setText(QString(key_));

    std::vector<QPushButton*>::iterator it = std::find (keybind_buttons_.begin(), keybind_buttons_.end(), sender_button);
        if (it != keybind_buttons_.end()){
            keybinds_[it-keybind_buttons_.begin()] = key_;
        }

}

void Options::SetKeyValue(){
    int value = view_->GetLatestInput();
    if(value != key_){
        key_ = value;
        emit QuitLoop();
    }
}

void Options::CreateButtons(){
    for(unsigned int i = 0; i < descriptors_.size() ; i++){
        QPushButton* keybinds_btn = new QPushButton();
        keybinds_btn->setGeometry(QRect(900,100+(50*i),100,45));

        //qDebug() << keybinds_[i];

        keybinds_btn->setText(QKeySequence(keybinds_[i]).toString());
        QObject::connect(keybinds_btn, SIGNAL(clicked()),this, SLOT(SetKeybinds()));
        scene_->addWidget(keybinds_btn);
        keybind_buttons_.push_back(keybinds_btn);

        QGraphicsTextItem *desc = scene_->addText(descriptors_[i]);
        desc->setFont(QFont("Arial", 14, QFont::Bold));
        desc->setDefaultTextColor(QColor(Qt::white));
        desc->setPos(1000, 100+(50*i));
    }
}








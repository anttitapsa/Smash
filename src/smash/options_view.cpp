#include "options_view.h"
#include <QDebug>
#include <QKeyEvent>


Options_view::Options_view(QGraphicsScene* scene) : QGraphicsView(scene)
{

}

void Options_view::keyPressEvent(QKeyEvent* event){
   last_pressed_ = event->key();
   last_pressed_str_ = event->text();


}

int Options_view::GetLatestInput(){
    return last_pressed_;
}


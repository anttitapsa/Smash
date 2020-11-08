#include "background.h"

Background::Background(QGraphicsScene* scene)
    :  scene_(scene) {
    QImage bg = QImage(":/images/test_landscape");
    bg = bg.scaled(QSize(scene->width(), scene->height()), Qt::KeepAspectRatioByExpanding);
    scene->setBackgroundBrush(QBrush(bg));
}

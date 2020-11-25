#include "background.h"

Background::Background(QGraphicsScene* scene, QString const name)
    :  scene_(scene) {
    QImage bg = QImage(name);
    bg = bg.scaled(QSize(scene->width(), scene->height()));//, Qt::KeepAspectRatioByExpanding);
    scene->setBackgroundBrush(QBrush(bg));
}

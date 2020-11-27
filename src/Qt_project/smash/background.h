#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>

class Background: public QGraphicsScene, public QGraphicsView {
public:
    Background(QGraphicsScene* scene, QString const name);
private:
    QGraphicsScene* scene_;
};

#endif // BACKGROUND_H

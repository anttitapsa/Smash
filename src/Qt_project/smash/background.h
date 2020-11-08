#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>

class Background: public QGraphicsScene, public QGraphicsView {
public:
    Background(QGraphicsScene* scene);
private:
    QGraphicsScene* scene_;
};

#endif // BACKGROUND_H

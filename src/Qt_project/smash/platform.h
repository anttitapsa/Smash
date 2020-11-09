#ifndef PLATFORM_H
#define PLATFORM_H
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QPointF>
#include <QObject>

class Platform: public QObject, public QGraphicsPolygonItem {
public:
    Platform(int x, int y, int lenght);

private:
    int x_ ;
    int y_ ;
    int lenght_;


};



#endif // PLATFORM_H

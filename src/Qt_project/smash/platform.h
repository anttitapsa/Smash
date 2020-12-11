#ifndef PLATFORM_H
#define PLATFORM_H
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QPointF>
#include <QObject>

class Platform: public QObject, public QGraphicsPolygonItem {
public:
    Platform(int x, int y, int lenght, int time = -1);
    int Get_start_x() {return x_;}
    int Get_y() {return y_;}
    int Get_end_x() {return x_+lenght_;}
    int time_; //if platform is dead_platform, time != -1 and platform is deleted when time is zero

private:
    int x_ ;
    int y_ ;
    int lenght_;

};



#endif // PLATFORM_H

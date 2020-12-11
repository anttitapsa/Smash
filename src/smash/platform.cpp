#include "platform.h"
#include <QPolygonF>
#include <QPointF>
#include <QBrush>
#include <QColor>
Platform::Platform(int x, int y, int lenght, int time)
    : time_(time), x_(x),y_(y),lenght_(lenght){

    int w;
    if(time == -1){ w = 10;}//time -1 if platform is stable, else time_ indicates how long time platform on scene
    else{ w = 5;}

    QPolygonF shape = QPolygonF();
    shape.append(QPointF(x_,y_));
    shape.append(QPointF(x_,y_+w));
    shape.append(QPointF(x_+lenght_,y_+w));
    shape.append(QPointF(x_+lenght_,y_));
    setPolygon(shape);

    if(time == -1){ //if stable; color is black,if dead_platform gray
        setBrush(QColor("black"));}
    else{ setBrush(QColor("lightgray"));}
}

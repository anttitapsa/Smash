#include "platform.h"
#include <QPolygonF>
#include <QPointF>
#include <QBrush>
#include <QColor>
Platform::Platform(int x, int y, int lenght, int time)
    : x_(x),y_(y), lenght_(lenght), time_(time){
    //widght of the platform
    int w;
    if(time == -1){
        w = 10;}
    else{ w = 5;}

    QPolygonF shape = QPolygonF();
    shape.append(QPointF(x_,y_));
    shape.append(QPointF(x_,y_+w));
    shape.append(QPointF(x_+lenght_,y_+w));
    shape.append(QPointF(x_+lenght_,y_));
    setPolygon(shape);
    if(time == -1){
        setBrush(QColor("black"));}

    else{ setBrush(QColor("lightgray"));}
}

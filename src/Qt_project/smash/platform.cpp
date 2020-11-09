#include "platform.h"
#include <QPolygonF>
#include <QPointF>
#include <QBrush>
#include <QColor>
Platform::Platform(int x, int y, int lenght)
    : x_(x),y_(y), lenght_(lenght){

    QPolygonF shape = QPolygonF();
    shape.append(QPointF(x_,y_));
    shape.append(QPointF(x_,y_+5));
    shape.append(QPointF(x_+lenght_,y_+5));
    shape.append(QPointF(x_+lenght_,y_));
    setPolygon(shape);
    setBrush(QColor("black"));
}

#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include "mainmenu.h"

//too unskilled to make qpushbuttons look nice enough, hence this class exists
class CustomButton: public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    CustomButton();

protected:
    void MousePressEvent(QGraphicsSceneMouseEvent* event);

private:

};


#endif // CUSTOMBUTTON_H

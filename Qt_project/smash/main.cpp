#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create an item to put into the scene
    Player *player =  new Player();

    //el->setSpanAngle(5120);
    //el->setStartAngle(320);

    // add the item to the scene
    scene->addItem(player);

    // make el focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(1280, 720);
    view->show();
    scene->setSceneRect(0, 0, 1280, 720);



    return a.exec();
}

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
    Player *player1 =  new Player();
    Player *player2 =  new Player();

    //el->setSpanAngle(5120);
    //el->setStartAngle(320);

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    // make el focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();
    player1->keybinds.push_back(Qt::Key_W);
    player1->keybinds.push_back(Qt::Key_A);
    player1->keybinds.push_back(Qt::Key_S);
    player1->keybinds.push_back(Qt::Key_D);

    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();
    player2->keybinds.push_back(Qt::Key_Up);
    player2->keybinds.push_back(Qt::Key_Left);
    player2->keybinds.push_back(Qt::Key_Down);
    player2->keybinds.push_back(Qt::Key_Right);

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(1280, 720);
    view->show();
    scene->setSceneRect(0, 0, 1280, 720);



    return a.exec();
}

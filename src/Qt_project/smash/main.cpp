#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsView>
#include "background.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create an item to put into the scene
    Player *player1 =  new Player();
    Player *player2 =  new Player();
    player2->setBrush(QColor("#ffc0cb"));

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);


    // add a view
    Game * game = new Game(scene, player1, player2);
    scene->setSceneRect(0, 0, 1280, 720);
    Background * bg = new Background(scene);

    game->show();

    return a.exec();
}

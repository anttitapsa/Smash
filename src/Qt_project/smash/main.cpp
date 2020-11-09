#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsView>
<<<<<<< HEAD:src/Qt_project/smash/main.cpp
#include "background.h"
=======
#include "mainmenu.h"
>>>>>>> Juho:Qt_project/smash/main.cpp

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //scene for Main menu:
    QGraphicsScene* scene = new QGraphicsScene();

    //stack to contain different views:
    QStackedWidget* stack = new QStackedWidget();

    MainMenu* menu = new MainMenu(scene, stack);
    menu->GetView()->show();
    scene->setSceneRect(0,0,1280,720);
    stack->addWidget(menu->GetView());
    stack->setCurrentIndex(0);
    stack->show();
    /*
     ***former version***

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

    */

    return a.exec();
}

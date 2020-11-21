#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsView>
#include "mainmenu.h"

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


    return a.exec();
}

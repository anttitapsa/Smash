#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsView>
#include <QObject>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "player.h"
#include "game.h"
#include "platform.h"
#include <QTimer>
#include <fstream>

class MainMenu: public QObject
{
     Q_OBJECT
public:
    MainMenu(QGraphicsScene* scene, QStackedWidget *stack );
    QGraphicsView* GetView();

public slots:
    void StartGame(int game_nbr);
    void Option1();
    void Option2();

private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
    QTimer* timer_;
    std::map<int,QString> files_ = { {1, ":/textfiles/game_1"}, {2,":/textfiles/game_2"} };
    QLineEdit* line_;
};

#endif // MAINMENU_H

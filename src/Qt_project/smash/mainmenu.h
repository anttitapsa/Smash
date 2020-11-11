#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsView>
#include <QObject>
#include <QStackedWidget>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include "player.h"
#include "game.h"
#include "platform.h"
#include <QTimer>

class MainMenu: public QObject
{
     Q_OBJECT
public:
    MainMenu(QGraphicsScene* scene, QStackedWidget *stack );

    QGraphicsView* GetView();

public slots:
    void StartGame();

private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
    QTimer* timer_;
};

#endif // MAINMENU_H

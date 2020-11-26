#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <vector>
#include <QTransform>
#include <QStackedWidget>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsPixmapItem>
#include "player.h"

class Game: public QGraphicsView {
    Q_OBJECT

public:
    Game(QGraphicsScene* scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms, QStackedWidget* stack, std::vector<QGraphicsPixmapItem*>hearts, qreal rollspeed_);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    std::vector<int> keybinds;
    QTimer *timer_;
    void moveView();
    void check_dead();
    void player_to_above_platform(Player* p);
public slots:
    void gameTick();
    void ExitToMenu();
private:
    Player *p1_;
    Player *p2_;
    int dead_wall = -300;
    int dead_ground = 620;
    QGraphicsScene* scene_;
    std::vector<Platform*> platforms_; // Maybe update this into struct mapinfo, if more than platforms are needed
    QStackedWidget* stack_ ; // Juho 19/11 : access to stack created in main()
    std::vector<QGraphicsPixmapItem*> hearts_; //to update the player hearts position
    qreal rollspeed;
};

#endif // GAME_H

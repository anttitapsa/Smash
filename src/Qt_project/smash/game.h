#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <vector>
#include <QTransform>
#include <QGraphicsItem>
#include "player.h"

class Game: public QGraphicsView {
    Q_OBJECT

public:
    Game(QGraphicsScene* scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    std::vector<int> keybinds;
    QTimer *timer_;
    void moveView();
    void check_dead();
public slots:
    void gameTick();
private:
    Player *p1_;
    Player *p2_;
    qreal rollspeed = 0;
    int dead_wall = -300;
    int dead_ground = 620;
    QGraphicsScene *scene_;
    std::vector<Platform*> platforms_; // Maybe update this into struct mapinfo, if more than platforms are needed
};

#endif // GAME_H

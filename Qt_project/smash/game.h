#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QObject>
//#include <bitset>
#include <vector>
#include "player.h"

class Game: public QGraphicsView {
    //Q_OBJECT

public:
    Game(QGraphicsScene* scene, Player *p1, Player *p2);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //std::bitset<8> key;
    std::vector<int> keybinds;
private:
    Player *p1_;
    Player *p2_;
};

#endif // GAME_H

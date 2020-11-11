#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <vector>
#include <QTransform>
#include "player.h"

class Game: public QGraphicsView {
    Q_OBJECT

public:
    Game(QGraphicsScene* scene, QTimer *timer, Player *p1, Player *p2);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //std::bitset<8> key;
    std::vector<int> keybinds;
    QTimer *timer_;
public slots:
    void moveView();
private:
    Player *p1_;
    Player *p2_;
    QTransform transform_;
};

#endif // GAME_H

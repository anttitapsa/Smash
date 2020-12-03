#ifndef GINGERBREAD_H
#define GINGERBREAD_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <bitset>
#include <QTimer>
#include "platform.h"
class Gingerbread: public QObject, public QGraphicsPixmapItem {
public:
    Gingerbread(int x);
    void gravity();
    void SetPosition(int x, int y);
    void Cheer();
    void StopCheer();
    bool is_falling = true;
    int fallSpeed = 0;
    int falltime = 0;
    bool is_on_platform = false;
    bool hasJumped = false;
    Platform* standing_on = NULL;
    Platform* dead_platform = NULL;
private:
    const int player_width = 50;
    const int player_height = 60;
    int ground_ = 710;
    int x_;
};

#endif // GINGERBREAD_H

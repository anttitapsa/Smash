#ifndef GINGERBREAD_H
#define GINGERBREAD_H
#include <QGraphicsPixmapItem>
#include "platform.h"
class Gingerbread: public QObject, public QGraphicsPixmapItem {
public:
    Gingerbread(int x, int y);
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
    int x_;
    int ground_;
private:
    const int player_width = 50;
    const int player_height = 60;
};

#endif // GINGERBREAD_H

#ifndef GINGERBREAD_H
#define GINGERBREAD_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <bitset>
#include <QTimer>
class Gingerbread: public QObject, public QGraphicsPixmapItem {
public:
    Gingerbread(int x);
    void jump();
    void gravity();
    void SetPosition(int x, int y);

    void Cheer();

private:
    const int player_width = 50;
    const int player_height = 60;
    int ground_ = 710;
    int x_;
};

#endif // GINGERBREAD_H

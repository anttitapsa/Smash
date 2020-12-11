#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QStackedWidget>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include "lakki.h"
#include "totoro.h"
#include "gingerbread.h"
class Game: public QGraphicsView { Q_OBJECT

public:
    Game(QGraphicsScene* scene, QTimer *timer, Player *p1, Player *p2, std::vector<Platform*> platforms,
         QStackedWidget* stack, std::vector<QGraphicsPixmapItem*>hearts, std::vector<QGraphicsPixmapItem*>spikes, qreal rollspeed_, QString music_url,std::vector<Gingerbread*> ginger);
                                                                                        // if game2 spikes and ginger are empty vectors
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    std::vector<int> keybinds;
    void moveView();//moves view, deadwall and spikes
    void check_dead(); //checks if players lose a life and if game has ended
    void dead_platform(Player* p); //creates dead_platform to player if game1
    QTimer *timer_;
    template <typename T>
    void jump (T creature); // used on players and gingerbreads
    void Croud(); // calls jump() randomly to gingerbreadcroud
public slots:
    void gameTick();
    void ExitToMenu();
private:
    int sfx_volume = 100; //  0 is silence, 100 is max
    int music_volume = 40;
    QMediaPlayer *sound_effects;
    QMediaPlayer *bg_music;
    Player *p1_;
    Player *p2_;
    int dead_wall = 50;//start of candyland, changed to -300 in amfi
    int dead_ground = 720; 
    std::vector<Platform*> platforms_;
    QStackedWidget* stack_ ; //access to stack created in main()
    std::vector<QGraphicsPixmapItem*> hearts_; //to update the player hearts position
    std::vector<QGraphicsPixmapItem*> spikes_;//candyland spikes, work as the hearts
    qreal rollspeed;//how fast view moves candyland = 2, amfi = 0
    QString msource;
    std::vector<Gingerbread*> ginger;
};

#endif // GAME_H

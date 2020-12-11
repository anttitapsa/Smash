#ifndef LEVELSELECT_H
#define LEVELSELECT_H
#include <QLineEdit>
#include <QLabel>
#include <fstream>
#include <QImage>
#include <QBrush>
#include <QFile>
#include <QFont>
#include <QIcon>
#include "game.h"

class LevelSelect : public QObject
{
    Q_OBJECT
public:
    LevelSelect(QGraphicsScene* scene, QStackedWidget *stack, int Player1, int Player2);
    QGraphicsView* GetView();
    std::vector<Gingerbread*> MakeCroud(); //if game1 makes gingerbreads randomly
public slots:
    void ReturnToMain();
    void StartGame(int game_nbr); //creates players, platforms, hearts and spikes, view and a game which it gives them
    void Option1();//calls StartGame(1), so game_nbr = 1
    void Option2();//calls StartGame(2), so game_nbr = 2
private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
    QVector<int> players_;
    std::map<int,QString> files_ = { {1, ":/textfiles/game_1"}, {2,":/textfiles/game_2"} };
    QLineEdit* line_;
    QTimer* timer_;

};

#endif // LEVELSELECT_H

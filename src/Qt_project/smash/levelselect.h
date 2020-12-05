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
    std::vector<Gingerbread*> MakeCroud();
public slots:
    void ReturnToMain();
    void StartGame(int game_nbr);
    void Option1();
    void Option2();

private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
    QVector<int> players_;
    std::map<int,QString> files_ = { {1, ":/textfiles/game_1"}, {2,":/textfiles/game_2"} };
    QLineEdit* line_;
    QTimer* timer_;
};

#endif // LEVELSELECT_H

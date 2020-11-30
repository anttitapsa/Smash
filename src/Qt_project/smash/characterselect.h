#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H

#include <QGraphicsView>
#include <QObject>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "player.h"
#include "game.h"
#include "platform.h"
#include "levelselect.h"
#include <QTimer>
#include <fstream>
#include <QImage>
#include <QBrush>
#include <QString>

#include <QVector>

class CharacterSelect : public QObject{
    Q_OBJECT
public:
    CharacterSelect(QGraphicsScene* scene, QStackedWidget *stack);
public slots:
    QGraphicsView* GetView();
    void ChoosePlayerCharacter(int player,int choose);
    void OpenLevelSelect();
private:
    QStackedWidget* stack_;
    QGraphicsView* view_;
    std::map<int, QVector<QString>> characters_ = {{1, {":/images/tupsu.png", ":/images/tupsu_shove1.png", ":/images/tupsu_shove2.png", ":/images/tupsu_shove3.png"}},
                                                   {2, {":/images/totoro.png", ":/images/totoro2.png", ":/images/totoro3.png", ":/images/totoro4.png"}}};
    QVector<QString> Player1_;
    QVector<QString> Player2_;
    QTimer* timer_;

};

#endif // CHARACTERSELECT_H

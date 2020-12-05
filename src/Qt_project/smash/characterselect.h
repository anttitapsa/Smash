#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H
#include <QGroupBox>
#include <QVBoxLayout>
#include "levelselect.h"

class CharacterSelect : public QObject{
Q_OBJECT
public:
    CharacterSelect(QGraphicsScene* scene, QStackedWidget *stack);
    QGraphicsView* GetView();
public slots:
    void TotoroP1();
    void TotoroP2();
    void TupsuP1();
    void TupsuP2();
    void OpenLevelSelect();
    void ReturnToMain();
private:
    QGraphicsScene* scene_;
    QStackedWidget* stack_;
    QGraphicsView* view_;
    //Players will be created later 0 = white_hat 1 = yellow hat 2 = totoro 3 = purple totoro
    int Player1_ = -1; //-1 meaning not choosed, values 0 or 2
    int Player2_ = -1;// after choosing value 1 or 3
    QGraphicsTextItem * Player1_text_ = scene_->addText(QString("Player 1"));
    QGraphicsTextItem * Player2_text_ = scene_->addText(QString("Player 2"));
    QTimer* timer_;

};

#endif // CHARACTERSELECT_H

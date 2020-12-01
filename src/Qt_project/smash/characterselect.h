#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H
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
    QStackedWidget* stack_;
    QGraphicsView* view_;
    std::map<int, QVector<QString>> characters_ = {{1, {":/images/tupsu.png", ":/images/tupsu_shove1.png", ":/images/tupsu_shove2.png", ":/images/tupsu_shove3.png", ":/images/tupsuleft.png"}},
                                                   {2, {":/images/totoro.png", ":/images/totoro2.png", ":/images/totoro3.png", ":/images/totoro4.png", ":/images/totoro_left.png"}},
                                                   {3, {":/images/tupsu_2.png", ":/images/tupsu_shove1_2.png", ":/images/tupsu_shove2_2.png", ":/images/tupsu_shove3_2.png", ":/images/tupsuleft_2.png"}},
                                                   {4, {":/images/totoro_2.png", ":/images/totoro2_2.png", ":/images/totoro3_2.png", ":/images/totoro4_2.png", ":/images/totoro_left_2.png"}}};
    QVector<QString> Player1_;
    QVector<QString> Player2_;
};

#endif // CHARACTERSELECT_H

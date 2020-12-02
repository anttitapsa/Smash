#ifndef MAINMENU_H
#define MAINMENU_H
#include "characterselect.h"

class MainMenu: public QObject
{
     Q_OBJECT
public:
    MainMenu(QGraphicsScene* scene, QStackedWidget *stack );
    QGraphicsView* GetView();

public slots:
    void OpenCharacterSelect();

private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
};

#endif // MAINMENU_H

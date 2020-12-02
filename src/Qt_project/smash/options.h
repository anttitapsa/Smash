#ifndef OPTIONS_H
#define OPTIONS_H

#include <QGraphicsView>
#include <QObject>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsProxyWidget>

class Options: public QObject
{
     Q_OBJECT
public:
    Options(QGraphicsScene* scene, QStackedWidget *stack );
    QGraphicsView* GetView();

public slots:
    void ReturnToMain();

private:
    QStackedWidget* stack_;
    QGraphicsView* view_ ;
};

#endif // OPTIONS_H

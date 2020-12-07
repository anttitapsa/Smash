#ifndef OPTIONS_VIEW_H
#define OPTIONS_VIEW_H

#include <QGraphicsView>
#include <QObject>

class Options_view : public QGraphicsView {
    Q_OBJECT
public:
    Options_view(QGraphicsScene* scene);

    void keyPressEvent(QKeyEvent* event);

    int GetLatestInput();

private:
    int last_pressed_ = 0;
    QString last_pressed_str_ ;

};

#endif // OPTIONS_VIEW_H

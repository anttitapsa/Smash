#ifndef OPTIONS_H
#define OPTIONS_H

#include <QGraphicsView>
#include <QObject>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QSlider>
#include <QIODevice>
#include <QTextStream>
class Options: public QObject
{
     Q_OBJECT
public:
    Options(QGraphicsScene* scene, QStackedWidget *stack );
    QGraphicsView* GetView();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void ReturnToMain();
    void SaveOptions();
    void SetKeybinds();

private:
    QStackedWidget* stack_;
    QGraphicsScene* scene_;
    QGraphicsView* view_ ;
    std::vector<int> keybinds_;
    const std::vector<QString> descriptors_ = {"P1 Jump", "P1 Move Left", "P1 Push Attack", "P1 Move Right",
                                         "P2 Jump", "P2 Move Left", "P2 Push Attack", "P2 Move Right"};
    QSlider* volume_slider_ ;
    bool setting_keybinds = false;
    unsigned int at_key = 0;
    std::vector<QGraphicsTextItem*> keybind_texts;

};

#endif // OPTIONS_H

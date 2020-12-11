#ifndef OPTIONS_H
#define OPTIONS_H

#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QSlider>
#include <QIODevice>
#include <QTextStream>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>
#include <QFileInfo>
#include "options_view.h"

class Options: public QGraphicsView
{
     Q_OBJECT
public:
    Options(QGraphicsScene* scene, QStackedWidget *stack );
    QGraphicsView* GetView();
    void CreateButtons();

signals:
    void QuitLoop();

public slots:
    void ReturnToMain();
    void SaveOptions();
    void SetKeybinds();
    void SetKeyValue();


private:
    QStackedWidget* stack_;
    QGraphicsScene* scene_;
    Options_view* view_ ;
    std::vector<int> keybinds_;
    const std::vector<QString> descriptors_ = {"P1 Jump", "P1 Move Left", "P1 Push Attack", "P1 Move Right",
                                         "P2 Jump", "P2 Move Left", "P2 Push Attack", "P2 Move Right"};
    QSlider* volume_slider_ ;
    QSlider* sfx_slider_ ;
    std::vector<QPushButton*> keybind_buttons_ ;
    int key_ = 0;
    std::vector<QGraphicsTextItem*> keybind_texts;

};

#endif // OPTIONS_H

#include "gingerbread.h"
#include <iostream>
Gingerbread::Gingerbread(int x,int y)
    : x_(x),ground_(y){
    setPixmap(QPixmap(":/images/ukko_a.PNG").scaledToHeight(player_height));
    setPos(x_,ground_- player_height);
}
void Gingerbread::gravity() {
    int drop =0;
    if(hasJumped){
        drop = -10 + falltime * falltime * 0.7;
        falltime++;}

    if(y()+drop > ground_-player_height){
            setPos(x(),ground_-player_height);
            hasJumped = false;
            falltime = 0;
            StopCheer();
        }
     else{setPos(x(),y()+drop);}
}
void Gingerbread::SetPosition(int x, int y){
    setPos(x,y);
}
void Gingerbread::Cheer(){
    QPixmap newpicture = QPixmap(":/images/ukko_b.PNG");
    setPixmap(newpicture.scaledToHeight(player_height+7));
    setPos(x(),y());
}
void Gingerbread::StopCheer(){
    QPixmap newpicture = QPixmap(":/images/ukko_a.PNG");
    setPixmap(newpicture.scaledToHeight(player_height));
    setPos(x(),y());
}

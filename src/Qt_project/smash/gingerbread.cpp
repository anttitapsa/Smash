#include "gingerbread.h"

Gingerbread::Gingerbread(int x)
    : x_(x) {
    setPixmap(QPixmap(":/images/ukko_a.PNG").scaledToHeight(player_height));
    setPos(x_,ground_- player_height);
}
void Gingerbread::gravity() {

    if(y() != ground_){
        setPos(x(),y()+1);
    }
}
void Gingerbread::SetPosition(int x, int y){
    setPos(x,y);
}
void Gingerbread::Cheer(){
    QPixmap newpicture = QPixmap(":/images/ukko_b.PNG");
    setPixmap(newpicture.scaledToHeight(player_height+7));
    setPos(x(),y());
}

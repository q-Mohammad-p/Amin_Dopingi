
#include "flag.h"

flag::flag(Position pos) : BodyObject(pos){
    QPixmap pixmap(":/images/RedFlag");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap);
    setPos(position.x, position.y);

    X = position.x;
    Y = position.y;

}

void flag::moveFlagRight() {
    setPos(x() - 5, y());
}

void flag::moveFlagLeft() {
    setPos(x() + 5, y());
}

void flag::changeFlag(int x, int y) {
    if (checkPoint) {
        return;
    }
    QPixmap pixmap(":/images/BlueFlag");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap);
    setPos(x,y);
    checkPoint = true;
}

void flag::restart() {
    setPos(800, Y);
}

void flag::Reset(){
    setPos(X,Y);
}


void flag::makeRed(){
    QPixmap pixmap(":/images/RedFlag");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap);
    setPos(X, Y);
}
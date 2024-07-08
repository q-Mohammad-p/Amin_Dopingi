#include "platForm.h"


PlatForm::PlatForm(Position pos) : BodyObject(pos){
    QPixmap pixmap(":/images/platform");
    setPixmap(pixmap);
    setPos(position.x, position.y);
    X = position.x;
    Y = position.y;

}

void PlatForm::movePlatRight() {
    setPos(x() - 5, y());
}

void PlatForm::movePlatLeft() {
    setPos(x() + 5, y());
}

void PlatForm::restart(int ax) {
    setPos(x()+ax, y());
}


void PlatForm::restart2(int ax) {
    setPos(x()-ax, y());
}

void PlatForm::Reset(){
    setPos(X,Y);
}
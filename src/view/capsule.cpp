#include "capsule.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>


capsule::capsule(int x, int y, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    current_x = 500;
    _width = x;
    _height = y;

    X = x;
    Y = y;

    setFlags(GraphicsItemFlag::ItemIsFocusable);

    QPixmap pixmap(":/images/capsule");
    pixmap = pixmap.scaled(80, 80, Qt::KeepAspectRatioByExpanding);
    scaledImage1 = new QPixmap(pixmap);
    pixmap = pixmap.copy(0, 0, pixmap.width(), pixmap.height());
    setPos(x, y);
    setPixmap(pixmap);
}

void capsule::moveRight() {

    setPos(x() - 5, y());

};


void capsule::moveLeft() {


    setPos(x() + 5, y());


}

void capsule::hide() {
    QGraphicsPixmapItem::hide();
}

void capsule::Reset(int x) {
    setPos(x, Y);
}
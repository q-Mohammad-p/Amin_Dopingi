#include "backGround.h"
#include <QGraphicsScene>
#include <iostream>

BackGround::BackGround(int sceneHeight, int sceneWidth, QGraphicsItem *parent) : QGraphicsPixmapItem(parent),
                                                                                 Decorator(sceneWidth, sceneHeight) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);


    QPixmap pixmap(":/images/background");
    pixmap = pixmap.scaled(pixmap.width(), sceneHeight, Qt::KeepAspectRatioByExpanding);
    scaledImage1 = new QPixmap(pixmap);
    pixmap = pixmap.copy(0, 0, pixmap.width(), pixmap.height());
    setPixmap(pixmap);
}

void BackGround::moveRight() {

    current_x = (current_x + 5) % (scaledImage1->width() - width - 1000);


    QPixmap cropped = scaledImage1->copy(current_x, 0, width, height);

    setPixmap(cropped);
};


void BackGround::moveLeft() {

    if (current_x > 0)
        current_x = (current_x - 5) % (scaledImage1->width() - width - 1000);

    if (current_x <= 0) {
        current_x = 11643 - width;
    }

    QPixmap cropped = scaledImage1->copy(current_x, 0, width, height);

    setPixmap(cropped);

}


BackGround::~BackGround() {
    delete scaledImage1;
}

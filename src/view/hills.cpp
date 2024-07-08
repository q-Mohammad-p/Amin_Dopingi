#include "hills.h"
#include <QTimer>


Hills::Hills(int sceneHeight, int sceneWidth, QGraphicsItem *parent) : QGraphicsPixmapItem(parent),
                                                                       Decorator(sceneWidth, sceneHeight) {
    current_x = 0;
    setFlags(GraphicsItemFlag::ItemIsFocusable);


    QPixmap pixmap(":/images/hills");
    pixmap = pixmap.scaled(pixmap.width(), sceneHeight, Qt::KeepAspectRatioByExpanding);
    scaledImage1 = new QPixmap(pixmap);
    pixmap = pixmap.copy(0, 0, pixmap.width(), pixmap.height());
    setPixmap(pixmap);


}

void Hills::moveRight() {

    current_x = (current_x + 5) % (scaledImage1->width() - width - 1000);


    QPixmap cropped = scaledImage1->copy(current_x, 0, width, height);
    setPixmap(cropped);
};


void Hills::moveLeft() {


    if (current_x > 0)
        current_x = (current_x - 5) % (scaledImage1->width() - width - 1000);

    QPixmap cropped = scaledImage1->copy(current_x, 0, width, height);

    setPixmap(cropped);

}

void Hills::restart(int x) {
    current_x = x;
    QPixmap cropped = scaledImage1->copy(current_x, 0, width, height);
    setPixmap(cropped);
}

Hills::~Hills() {
    delete scaledImage1;
}
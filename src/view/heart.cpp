

#include "heart.h"

heart::heart(int x, int y) {
    QPixmap pixmap(":/images/heart");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap);
    setPos(x, y);
}

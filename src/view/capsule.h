#ifndef CAPSULE_H
#define CAPSULE_H

#include <QGraphicsPixmapItem>

class capsule : public QObject, public QGraphicsPixmapItem {


public:
    capsule(int, int, QGraphicsItem *parent = nullptr);

    int X;
    int Y;
    int _width;
    int _height;
    int current_x{};
    QPixmap *scaledImage1;
    void Reset(int);

public slots:

    void moveRight();

    void moveLeft();

    void hide();

};

#endif


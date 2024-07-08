

#ifndef GIT_AMIN_BODYOBJECT_H
#define GIT_AMIN_BODYOBJECT_H


#include <QGraphicsPixmapItem>
#include "position.h"

class BodyObject {
public:
    BodyObject(int w, int h): width(w), height(h){}
    BodyObject(Position pos) : width(0), height(0), position(pos){}
    BodyObject(int w, int h, Position pos):width(w), height(h), position(pos){}

    int width;
    int height;
    Position position;
    QGraphicsPixmapItem image;
};


#endif

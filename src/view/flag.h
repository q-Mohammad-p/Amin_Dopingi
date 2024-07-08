#ifndef AMIN_DOPINGI_FLAG_H
#define AMIN_DOPINGI_FLAG_H


#include <QGraphicsPixmapItem>
#include "bodyObject.h"

class flag : public QObject, public QGraphicsPixmapItem, public BodyObject {
Q_OBJECT

    Q_PROPERTY(qreal place READ x WRITE setX)
public:
    flag(Position);

    void moveFlagRight();

    void moveFlagLeft();

    void changeFlag(int, int);

    bool checkPoint{false};

    void restart();

    void Reset();

    void makeRed();

    int X;

    int Y;
private:

};


#endif

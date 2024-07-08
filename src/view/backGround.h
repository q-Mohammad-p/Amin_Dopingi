#ifndef AMIN_DOPINGI_BACKGROUND_H
#define AMIN_DOPINGI_BACKGROUND_H

#include <QGraphicsPixmapItem>
#include "decorator.h"

class BackGround : public QObject, public QGraphicsPixmapItem, public Decorator {


public:
    BackGround(int, int, QGraphicsItem *parent = nullptr);

    ~BackGround();

    int current_x{0};

    QPixmap *scaledImage1;

public slots:

    virtual void moveRight();

    virtual void moveLeft();
};


#endif

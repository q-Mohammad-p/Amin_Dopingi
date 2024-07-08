#ifndef AMIN_DOPINGI_HILLS_H
#define AMIN_DOPINGI_HILLS_H

#include <QGraphicsPixmapItem>
#include "decorator.h"

class Hills : public QObject, public QGraphicsPixmapItem, public Decorator {


public:
    Hills(int, int, QGraphicsItem *parent = nullptr);

    ~Hills();

    int current_x{0};
    QPixmap *scaledImage1;

    void restart(int);

public slots:

    virtual void moveRight();

    virtual void moveLeft();

};

#endif

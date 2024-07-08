#include "hookihooki.h"
#include <QPixmap>
#include <QTimer>
#include <QPropertyAnimation>


hookihooki::hookihooki(int x, int y) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);

    QPixmap pixmap(":/images/hookihooki");
    pixmap = pixmap.scaled(60, 60, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap);
    setPos(x, y);

    X = x;
    Y = y;

    Right = new QTimer(this);
    Right->setInterval(100);
    connect(Right,&QTimer::timeout,this, &hookihooki::runRight);
    Right->start();


    Left = new QTimer(this);
    Left->setInterval(100);
    connect(Left,&QTimer::timeout,this, &hookihooki::runLeft);

}

void hookihooki::moveRight() {
    setPos(x() - 5, y());
}

void hookihooki::moveLeft() {
    setPos(x() + 5, y());
}

void hookihooki::runRight(){
    if(place == 500){
        Right->stop();
        Left->start();
    }
    else{
        place+=5;
        setPos(x() + 5, y());
    }
}

void hookihooki::runLeft(){
    if(place == 0){
        Right->start();
        Left->stop();
    }
    else{
        place-=5;
        setPos(x() - 5, y());
    }
}

void hookihooki::Reset(int x){
    place = 0;
    setPos(x, Y);

}
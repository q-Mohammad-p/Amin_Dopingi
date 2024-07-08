#ifndef ARMIN_DOPINGI_HOOKIHOOKI_H
#define ARMIN_DOPINGI_HOOKIHOOKI_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSequentialAnimationGroup>

class hookihooki : public QObject,public QGraphicsPixmapItem{
Q_OBJECT

    Q_PROPERTY(qreal place READ x WRITE setX)
public:

    int current_x{};
    hookihooki(int x, int y);
    QPixmap * h;
    void moveRight();
    void moveLeft();

    QTimer *Right;
    QTimer *Left;

    int place{0};

    int X;
    int Y;

    bool dead{false};

    void Reset(int);

public slots:
    void runRight();
    void runLeft();
private:
};



#endif

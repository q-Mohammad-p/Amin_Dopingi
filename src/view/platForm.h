
#ifndef GIT_AMIN_PLATFORM_H
#define GIT_AMIN_PLATFORM_H


#include <QGraphicsPixmapItem>
#include <QTimer>
#include "bodyObject.h"


class PlatForm : public QObject, public QGraphicsPixmapItem, public BodyObject {
    Q_OBJECT

    Q_PROPERTY(qreal place READ x WRITE setX)
public:
    PlatForm(Position);

    void movePlatRight();

    void movePlatLeft();

    void restart(int);

    void restart2(int);

    void Reset();

    int X;

    int Y;
private:

};


#endif

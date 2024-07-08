
#ifndef AMIN_DOPINGI_CONTROLLER_H
#define AMIN_DOPINGI_CONTROLLER_H


#include <QKeyEvent>
#include "Player.h"

class controller : public QObject,public QGraphicsPixmapItem{
Q_OBJECT

public:
    controller(Player *P);

protected:
    void keyReleaseEvent(QKeyEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    Player *p;
};


#endif

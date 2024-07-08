
#ifndef GIT_AMIN_GAME_H
#define GIT_AMIN_GAME_H

#include<QGraphicsView>
#include <QTimer>
#include <QPropertyAnimation>
#include <vector>
#include "backGround.h"
#include "flag.h"
#include "platForm.h"
#include "heart.h"
#include "capsule.h"
#include "hookihooki.h"


class Game : public QGraphicsView {

public:

    Game();

    ~Game();

    QGraphicsScene *gameScene;

    QGraphicsScene *playGroundScene;

    QGraphicsView *playGround;


    capsule *Caps;

};


#endif

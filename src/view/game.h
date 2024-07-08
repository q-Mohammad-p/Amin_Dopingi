
#ifndef GIT_AMIN_GAME_H
#define GIT_AMIN_GAME_H

#include<QGraphicsView>
#include <vector>
#include "backGround.h"


class Game : public QGraphicsView {

public:

    Game();

    ~Game();

    QGraphicsScene *gameScene;

    QGraphicsScene *playGroundScene;

    QGraphicsView *playGround;

};


#endif

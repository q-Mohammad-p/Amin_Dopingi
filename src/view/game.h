
#ifndef GIT_AMIN_GAME_H
#define GIT_AMIN_GAME_H

#include<QGraphicsView>
#include <vector>
#include "backGround.h"
#include "hills.h"
#include "capsule.h"
#include "hookihooki.h"
#include "platForm.h"

using namespace std;

class Game : public QGraphicsView {

public:

    Game();

    ~Game();

    QGraphicsScene *gameScene;

    QGraphicsScene *playGroundScene;

    QGraphicsView *playGround;

    vector<Decorator *> decorator;

    vector<PlatForm *>plfs;

    flag *f;

    hookihooki *Hooki;

    capsule *Caps;

};


#endif

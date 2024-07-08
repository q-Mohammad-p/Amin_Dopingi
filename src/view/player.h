
#ifndef GIT_AMIN_PLAYER_H
#define GIT_AMIN_PLAYER_H


#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QPropertyAnimation>
#include <vector>
#include "backGround.h"
#include "bodyObject.h"
#include "platForm.h"
#include"game.h"
#include "hills.h"
#include "flag.h"
#include "heart.h"
#include "bodyObject.h"
#include "capsule.h"
#include "hookihooki.h"

class Player : public QObject, public QGraphicsPixmapItem , public BodyObject {
Q_OBJECT


    Q_PROPERTY(qreal height READ y WRITE setY)
public:

    Player(Game *, vector<PlatForm *>, vector<Decorator *>, flag *, int , int ,
           vector<heart *>,int , int ,Position  ,hookihooki *, capsule *, QGraphicsItem *parent = nullptr);

};


#endif

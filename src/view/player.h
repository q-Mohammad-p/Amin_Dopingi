
#ifndef AMIN_DOPINGI_PLAYER_H
#define AMIN_DOPINGI_PLAYER_H


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
    ~Player();

    int end{100};
    Game *game;
    bool colliding{false};
    bool jumped{false};
    flag *Flag;
    vector<PlatForm *> plats;
    vector<heart *> Hearts;
    vector<Decorator *> decorators;
    bool over{false};

    int life{2};

    hookihooki * Hooki;
    capsule *cap;
    bool caps{false};

signals:

    void call();

    void call_Win();

    void call_Game_Over();


public slots:

    void Standing_Right();

    void Standing_Left();

    void Run_Right();

    void Run_Left();

    void Jump();

    void gravity();

    void checkHookihookiCollision();

    void checkCapsuleCollision();


private:
    QTimer *standRightTimer;
    QTimer *standLeftTimer;
    QTimer *moveRightTimer;
    QTimer *moveLeftTimer;
    QTimer *checkHookihookiTimer;
    QTimer *checkCapsuleTimer;
    int current_x = 0;
    int current_x2 = 0;
    int current_x3 = 0;
    int current_x4 = 0;
    QPixmap *scaledImage;
    QPixmap *scaledImage2;
    QPixmap *scaledImage3;
    QPixmap *scaledImage4;
    QPropertyAnimation *gravityAnimation;
    QPropertyAnimation *jumpAnimation;

    int place = 100;

    int height_;
};


#endif

#include "player.h"
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QDebug>


Player::Player(Game *g, vector<PlatForm *> vect, vector <Decorator *> deco, flag *flg, int sceneHaight,
               int sceneWidth, vector<heart *> Heart,int w, int h,Position  pos, hookihooki *hook, capsule *caps,
               QGraphicsItem *parent) : QGraphicsPixmapItem(parent), BodyObject(w, h, pos) {

    setFlags(GraphicsItemFlag::ItemIsFocusable);
    plats = vect;
    game = g;
    Flag = flg;
    Hearts = Heart;
    decorators = deco;
    Hooki = hook;
    cap = caps;

    QPixmap pixmap1(":/images/spriteStandRight");
    pixmap1 = pixmap1.scaled(4020, 150, Qt::KeepAspectRatioByExpanding);
    scaledImage = new QPixmap(pixmap1);
    pixmap1 = pixmap1.copy(0, 0, 60, 150);
    setPixmap(pixmap1);

    height_ = sceneHaight - pixmap1.height() - 125;

    setPos(place, height_);

    QPixmap pixmap4(":/images/spriteStandLeft");
    pixmap4 = pixmap4.scaled(4020, 150, Qt::KeepAspectRatioByExpanding);
    scaledImage4 = new QPixmap(pixmap4);

    QPixmap pixmap2(":/images/spriteRunRight");
    pixmap2 = pixmap2.scaled(3900, 150, Qt::KeepAspectRatioByExpanding);
    scaledImage2 = new QPixmap(pixmap2);

    QPixmap pixmap3(":/images/spriteRunLeft");
    pixmap3 = pixmap3.scaled(3900, 150, Qt::KeepAspectRatioByExpanding);
    scaledImage3 = new QPixmap(pixmap3);


    standRightTimer = new QTimer(this);
    standRightTimer->setInterval(10);
    connect(standRightTimer, &QTimer::timeout, this, &Player::Standing_Right);
    standRightTimer->start();

    moveRightTimer = new QTimer(this);
    moveRightTimer->setInterval(10);
    connect(moveRightTimer, &QTimer::timeout, this, &Player::Run_Right);

    standLeftTimer = new QTimer(this);
    standLeftTimer->setInterval(10);
    connect(standLeftTimer, &QTimer::timeout, this, &Player::Standing_Left);


    moveLeftTimer = new QTimer(this);
    moveLeftTimer->setInterval(10);
    connect(moveLeftTimer, &QTimer::timeout, this, &Player::Run_Left);

    pos.y = sceneHaight - pixmap1.height() - 125;


    gravityAnimation = new QPropertyAnimation(this, "height", this);
    gravityAnimation->setStartValue(pos.y);
    gravityAnimation->setEndValue(pos.y);
    gravityAnimation->setDuration(200);
    connect(gravityAnimation, &QPropertyAnimation::finished, this, &Player::gravity);

    jumpAnimation = new QPropertyAnimation(this, "height", this);

    checkHookihookiTimer = new QTimer(this);
    checkHookihookiTimer->setInterval(20);
    connect(checkHookihookiTimer, &QTimer::timeout, this, &Player::checkHookihookiCollision);
    checkHookihookiTimer->start();

    checkCapsuleTimer = new QTimer(this);
    checkCapsuleTimer->setInterval(20);
    connect(checkCapsuleTimer, &QTimer::timeout, this, &Player::checkCapsuleCollision);
    checkCapsuleTimer->start();


}
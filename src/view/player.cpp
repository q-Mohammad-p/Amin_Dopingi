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

void Player::Standing_Right() {
    if (over)
        return;
    moveRightTimer->stop();
    standRightTimer->start();
    current_x = (current_x + 67) % scaledImage->width();
    QPixmap cropped = scaledImage->copy(current_x, 0, 67, height);
    setPixmap(cropped);

}

void Player::Run_Right() {
    if (end == Flag->X) {
        Flag->changeFlag(Flag->x(), Flag->y());
    }
    if (end == 3800) {
        emit call_Win();
        return;
    }
    if (over)
        return;
    else {
        end += 5;
        standRightTimer->stop();
        moveRightTimer->start();
        standLeftTimer->stop();
        moveLeftTimer->stop();
        current_x2 = (current_x2 + 130) % scaledImage2->width();

        QPixmap cropped = scaledImage2->copy(current_x2, 0, width, height);
        setPixmap(cropped);
        if (place < 800) {
            place += 5;
            setPos(place, y());
        } else {
            cap->moveRight();
            Hooki->moveRight();
            for (int i = 0; i < 2; ++i) {
                decorators[i]->moveRight();
            }
            Flag->moveFlagRight();
            for (int i = 0; i < 7; i++) {
                plats[i]->movePlatRight();
            }
        }
    }
}

void Player::Run_Left() {
    if (over)
        return;
    if (end == 100) {
        standRightTimer->stop();
        return;
    } else {
        end -= 5;
        standLeftTimer->stop();
        moveLeftTimer->start();
        standRightTimer->stop();
        moveRightTimer->stop();
        current_x3 = (current_x3 + 130) % scaledImage3->width();

        QPixmap cropped = scaledImage3->copy(current_x3, 0, width, height);
        setPixmap(cropped);
        if (place > 100) {
            place -= 5;
            setPos(place, y());
        } else {
            for (int i = 0; i < 2; ++i) {
                decorators[i]->moveLeft();
            }
            cap->moveLeft();
            Hooki->moveLeft();
            Flag->moveFlagLeft();
            for (int i = 0; i < 7; i++) {
                plats[i]->movePlatLeft();
            }
        }
    }
}

void Player::Standing_Left() {
    if (over)
        return;

    moveLeftTimer->stop();
    standLeftTimer->start();

    current_x4 = (current_x4 + 67) % scaledImage4->width();

    QPixmap cropped = scaledImage4->copy(current_x4, 0, 67, height);
    setPixmap(cropped);
}
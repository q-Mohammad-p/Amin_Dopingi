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
}
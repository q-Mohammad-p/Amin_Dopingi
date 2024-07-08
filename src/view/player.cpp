#include "Player.h"
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QDebug>


Player::Player(Game *g, vector<PlatForm *> vect, vector <Decorator *> deco, flag *flg, int sceneHaight,
               int sceneWidth, vector<heart *> Heart,int w, int h,Position  pos, hookihooki *hook, capsule *caps,
               QGraphicsItem *parent) : QGraphicsPixmapItem(parent), BodyObject(w, h, pos) {
}
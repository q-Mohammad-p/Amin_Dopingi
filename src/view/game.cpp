#include "game.h"
#include "controller.h"
#include <QtWidgets>
#include <vector>
#include "ContinueWindow.h"

Game::Game() {

    showFullScreen();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    playGround = new QGraphicsView();
    playGround->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    playGround->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    playGroundScene = new QGraphicsScene(playGround);
    playGround->setScene(playGroundScene);

    gameScene = new QGraphicsScene(this);
    gameScene->setSceneRect(0, 0, width(), height());

    auto backGround = new BackGround(height(), width());
    playGroundScene->addItem(backGround);

    auto hills = new Hills(height(), width());
    playGroundScene->addItem(hills);

    Caps = new capsule(500, 650);
    playGroundScene->addItem(Caps);

    Hooki = new hookihooki(1800,680);
    playGroundScene->addItem(Hooki);








}
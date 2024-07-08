#include "game.h"
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
}
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

    decorator.push_back(backGround);
    decorator.push_back(hills);

    Position PosPlat1(0, gameScene->height() - 130);
    auto PlatForm1 = new PlatForm(PosPlat1);
    playGroundScene->addItem(PlatForm1);

    Position PosPlat2(578, gameScene->height() - 130);
    auto PlatForm2 = new PlatForm(PosPlat2);
    playGroundScene->addItem(PlatForm2);

    Position PosPlat3(1158, 400);
    auto PlatForm3 = new PlatForm(PosPlat3);
    playGroundScene->addItem(PlatForm3);

    Position PosPlat4(1637, gameScene->height() - 130);
    auto PlatForm4 = new PlatForm(PosPlat4);
    playGroundScene->addItem(PlatForm4);

    Position PosPlat5(2217, gameScene->height() - 130);
    auto PlatForm5 = new PlatForm(PosPlat5);
    playGroundScene->addItem(PlatForm5);

    Position PosPlat6(2797, 400);
    auto PlatForm6 = new PlatForm(PosPlat6);
    playGroundScene->addItem(PlatForm6);

    Position PosPlat7(3377, gameScene->height() - 130);
    auto PlatForm7 = new PlatForm(PosPlat7);
    playGroundScene->addItem(PlatForm7);

    Position flagPos(2500, gameScene->height() - 230);
    f = new flag(flagPos);

    playGroundScene->addItem(f);


    plfs.push_back(PlatForm1);
    plfs.push_back(PlatForm2);
    plfs.push_back(PlatForm3);
    plfs.push_back(PlatForm4);
    plfs.push_back(PlatForm5);
    plfs.push_back(PlatForm6);
    plfs.push_back(PlatForm7);

    auto Hart1 = new heart(20, 25);
    playGroundScene->addItem(Hart1);

    auto Hart2 = new heart(80, 25);
    playGroundScene->addItem(Hart2);

    auto Hart3 = new heart(140, 25);
    playGroundScene->addItem(Hart3);


    Hearts.push_back(Hart1);
    Hearts.push_back(Hart2);
    Hearts.push_back(Hart3);


    Caps = new capsule(500, 650);
    playGroundScene->addItem(Caps);

    Hooki = new hookihooki(1800,680);
    playGroundScene->addItem(Hooki);

    Position posPlayer;
    auto player = new Player(this, plfs, decorator, f, height(), width(), Hearts,130, 150,posPlayer,Hooki,Caps);
    playGroundScene->addItem(player);


    auto cont = new controller(player);

    playGroundScene->addItem(cont);








}
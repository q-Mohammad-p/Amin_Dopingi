#ifndef AMIN_DOPINGI_CONTINUEWINDOW_H
#define AMIN_DOPINGI_CONTINUEWINDOW_H


#include <QWidget>
#include <QMessageBox>
#include <QApplication>
#include "Player.h"

class ContinueWindow : public QWidget {
Q_OBJECT

public:
    explicit ContinueWindow(QWidget *parent = nullptr, Player * = nullptr);

public slots:

    void continueWindow();

    void winWindow();

    void gameOverWindow();

public:
    Player *player;
};


#endif

#include "continueWindow.h"

ContinueWindow::ContinueWindow(QWidget *parent, Player *play) : QWidget(parent), player(play) {
    connect(player, &Player::call, this, &ContinueWindow::continueWindow);

    connect(player, &Player::call_Win, this, &ContinueWindow::winWindow);

    connect(player, &Player::call_Game_Over, this, &ContinueWindow::gameOverWindow);
}

void ContinueWindow::continueWindow() {

    QMessageBox msgBox;
    QPixmap imagePixmap(":/images/youDied");
    msgBox.setIconPixmap(imagePixmap);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();

    if (result == QMessageBox::Yes) {
        player->ReStart();
    } else {
        exit(0);
    }

}


void ContinueWindow::winWindow() {

    QMessageBox msgBox;
    QPixmap imagePixmap(":/images/win");
    msgBox.setIconPixmap(imagePixmap);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();

    if (result == QMessageBox::Yes) {
        player->resetGame();
    } else {
        exit(0);
    }
}


void ContinueWindow::gameOverWindow() {

    QMessageBox msgBox;
    QPixmap imagePixmap(":/images/GameOver");
    imagePixmap = imagePixmap.scaled(500, 500, Qt::KeepAspectRatioByExpanding);
    msgBox.setIconPixmap(imagePixmap);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();

    if (result == QMessageBox::Yes) {
        player->resetGame();
    } else {
        exit(0);
    }
}
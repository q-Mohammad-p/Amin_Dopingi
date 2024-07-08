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


#include "controller.h"

controller::controller(Player *P) : p(P) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();
}

void controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
    if (event->key() == Qt::Key_D or event->key() == Qt::Key_Right) {
        p->Run_Right();
    } else if (event->key() == Qt::Key_A or event->key() == Qt::Key_Left) {
        p->Run_Left();
    } else if (event->key() == Qt::Key_W or event->key() == Qt::Key_Up) {
        p->Jump();
    }
    if (event->key() == Qt::Key_Escape)
        exit(0);
}

void controller::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsItem::keyReleaseEvent(event);

    if (event->key() == Qt::Key_D or event->key() == Qt::Key_Right) {
        p->Standing_Right();
    } else if (event->key() == Qt::Key_A or event->key() == Qt::Key_Left) {
        p->Standing_Left();
    } else if (event->key() == Qt::Key_W or event->key() == Qt::Key_Up) {
        p->gravity();
    }

    if (event->key() == Qt::Key_Escape) {
        exit(0);
    }
}
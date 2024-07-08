#ifndef GIT_AMIN_POSITION_H
#define GIT_AMIN_POSITION_H


class Position {
public:
    Position() : x(0), y(0) {}

    Position(int X, int Y) : x(X), y(Y) {}

    int x;
    int y;
};


#endif
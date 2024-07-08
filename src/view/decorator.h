

#ifndef GIT_AMIN_DECORATOR_H
#define GIT_AMIN_DECORATOR_H

#include "bodyObject.h"

class Decorator : public BodyObject{
public:
    Decorator(int w, int h): BodyObject(w, h){}
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    virtual void restart(int){}
};


#endif //GIT_AMIN_DECORATOR_H

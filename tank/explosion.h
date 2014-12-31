//
//  explosion.h
//  tank
//
//  Created by Kitchen on 12/31/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#ifndef __tank__explosion__
#define __tank__explosion__

#include <stdio.h>
#include "world.hpp"
#include "timer.h"
class Explosion : public DisplayObject
{
public:
    Explosion(int x, int y);
    virtual void tick();

private:
    SDL_Rect loc;
    double dx,dy,x,y;
    Timer t;
    int frame;
};




#endif /* defined(__tank__explosion__) */

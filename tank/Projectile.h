//
//  Projectile.h
//  tank
//
//  Created by Kitchen on 12/27/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#ifndef __tank__Projectile__
#define __tank__Projectile__

#include <stdio.h>
#include "world.hpp"
class Projectile : public WorldObject
{
public :
    Projectile(int init_x,int init_y);
    ~Projectile();

    const SDL_Rect* rect() const { return &loc; }
    void tick();
private :
    double x,y;
    double vx,vy;
    SDL_Texture* projectile;
    SDL_Rect loc;



};


#endif /* defined(__tank__Projectile__) */

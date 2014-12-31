//
//  Projectile.cpp
//  tank
//
//  Created by Kitchen on 12/27/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#include "Projectile.h"
#include "explosion.h"
Projectile::Projectile(int init_x, int init_y, bool shot_left)
{
    x = init_x;
    y = init_y;
    vx = 3;
    
    if (shot_left)
    {
        vx = -vx;
    }
    else
    {
        x += 30;
    }
    
    vy = -6;
    projectile = IMG_LoadTexture(renderer(), "assets/small_tank.png" );

    loc.w = 6;
    loc.h = 6;
};

Projectile::~Projectile()
{
    SDL_DestroyTexture(projectile);
}

void Projectile::tick()
{
    const double time = 1.0;
    const double g = 0.1;

    x += vx * time;
    y += vy * time;

    vy += g * time;

    loc.x = x;
    loc.y = y;

    SDL_RenderCopy(renderer(), projectile, 0, &loc);
}

void Projectile::collide(WorldObject& wo)
{
    wo.kill();
    kill();
    
    for (int i = 0; i < 75; ++i )
    {
        World::getWorld().addObject(new Explosion(x,y));
    }
}

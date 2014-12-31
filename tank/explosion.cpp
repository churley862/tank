//
//  explosion.cpp
//  tank
//
//  Created by Kitchen on 12/31/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#include "explosion.h"
#include "texture.h"
Explosion::Explosion(int _x,int _y)
{
    x = _x;
    y = _y;
    dx = (rand() % 20) * 0.25 + 1.5;
    if (rand() % 2 == 0) dx = dx * -1;
    
    dy = (rand() % 20) * 0.25 + 1.5;
    if (rand() % 2 == 0) dy = dy * -1;
    
    loc.w = 3; loc.h = 3;
    frame = 0;
}

void Explosion::tick()
{
    loc.x = x + dx * frame;
    loc.y = y + dy * frame;
    frame += 1;
    
    SDL_Texture* tex = Texture::getTexture("assets/small_tank.png");
    SDL_RenderCopy(renderer(), tex, 0, &loc);
    
    if (t.getTime() > 1500)
        kill();
}
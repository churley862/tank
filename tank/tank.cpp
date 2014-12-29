#include "tank.hpp"
#include "Projectile.h"
#include <iostream>
Tank::Tank(int x)
{
    tank = IMG_LoadTexture(renderer(), "assets/small_tank.png" );
    if (!tank)
    {
        throw "Unable to load tank asset";
    }

    loc.x = x;
    loc.y = 450;
    loc.h = 30;
    loc.w = 30;
}

Tank::~Tank()
{
    SDL_DestroyTexture(tank);
}

void Tank::tick()
{

    SDL_RenderCopy(renderer(), tank, 0, &loc);
}

void Player1Tank::tick()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_RIGHT])
    {
        loc.x+= 5;
    }
    if (state[SDL_SCANCODE_LEFT])
    {
        loc.x-= 5;
    }
    if (state[SDL_SCANCODE_SPACE] && reload.getTime() > 250)
    {
        reload.reset();
        world().addObject(new Projectile(loc.x, loc.y));
    }
   
    Tank::tick();
}

void Player2Tank::tick()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_D])
    {
        loc.x++;
    }
    if (state[SDL_SCANCODE_A])
    {
        loc.x--;
    }
    
    Tank::tick();
}



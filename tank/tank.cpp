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
    hit = false;
    loc.x = x;
    loc.y = 450;
    loc.h = 30;
    loc.w = 30;
    last_move = 0;
    moving_left = true;
}

Tank::~Tank()
{
    SDL_DestroyTexture(tank);
}

void Tank::respawn()
{
    hit = false;
}

void Tank::tick()
{
    // if hit, don't display
    if (!hit)
    {
        if (moving_left)
            SDL_RenderCopy(renderer(), tank, 0, &loc);
        else
            SDL_RenderCopyEx(renderer(), tank, 0, &loc, 0, 0, SDL_FLIP_HORIZONTAL);
    }
}

void Player1Tank::tick()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_RIGHT])
    {
        right();
    }
    if (state[SDL_SCANCODE_LEFT])
    {
        left();
    }
    if (state[SDL_SCANCODE_SPACE] && reload.getTime() > 250)
    {
        reload.reset();
        world().addObject(new Projectile(loc.x, loc.y, moving_left));
    }
    if (state[SDL_SCANCODE_RSHIFT] && hit)
    {
        respawn();
    }

    Tank::tick();
}

void Player2Tank::tick()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_D])
    {
        right();
    }
    if (state[SDL_SCANCODE_A])
    {
        left();
    }
    if (state[SDL_SCANCODE_S] && reload.getTime() > 250)
    {
        reload.reset();
        world().addObject(new Projectile(loc.x, loc.y, moving_left));
    }
    if (state[SDL_SCANCODE_R] && hit)
    {
        respawn();
    }

    Tank::tick();
}

void Tank::collide(DisplayObject& wo) {
    // check if tank or projectile
    switch (wo.id())
    {
    case projectile_id:
        // else projectile, I am dead :-(
        // hide and wait for respawn key
        hit_by_projectile();
        break;

    case tank_id:
        undo_move();
        break;

    case misc:
        // do nothing
        break;
    }
}


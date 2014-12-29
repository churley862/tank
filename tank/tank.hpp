#ifndef TANK_HPP__
#define TANK_HPP__

#include "SDL_image.h"
#include "world.hpp"
#include "timer.h"

class Tank : public WorldObject
{
public:
    Tank(int x=0);
    virtual ~Tank();

    virtual void tick();

protected:
    SDL_Texture* tank;
    SDL_Rect loc;
    Timer reload;
};

class Player1Tank : public Tank
{
public:
    Player1Tank() : Tank(100) {}
    
    virtual void tick();
};

class Player2Tank : public Tank
{
public:
    Player2Tank() : Tank(500) {}
    
    virtual void tick();
};


#endif
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
    virtual const SDL_Rect* rect() const
    {
        return &loc;
    }

    void collide(DisplayObject& wo);
    virtual IdType id() {
        return tank_id;
    }

    void hit_by_projectile()
    {
        hit = true;
    }

    // add hit_by_projectile method
    // add respawn method
    void respawn();

    const int speed = 3;
    void left() {
        last_move = -speed;
        loc.x += last_move;
        moving_left = true;
    }
    void right() {
        last_move = speed;
        loc.x += last_move;
        moving_left = false;
    }
    void undo_move() {
        loc.x -= last_move;
        last_move = 0;
    }

protected:
    int last_move;
    // add bool flag, when hit to prevent display
    bool hit;

    SDL_Texture* tank;
    SDL_Rect loc;
    Timer reload;
    bool moving_left;
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

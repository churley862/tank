#ifndef WORLD_HPP__
#define WORLD_HPP__

#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "timer.h"
class World;

class WorldObject
{
public:
    WorldObject() {}
    virtual ~WorldObject() {}
    virtual void tick() {}
    virtual bool is_dead() { return false; }

protected:
    SDL_Renderer* renderer();
    World& world();
};


class World
{
public:
    static World& getWorld()
    {
        static World world;
        return world;
    }

    virtual ~World();
    void run();
    void addObject(WorldObject* obj) { stuff.push_back(obj); }

    SDL_Texture* loadTexture(const char* fileName);
    SDL_Renderer* getRenderer() { return renderer; }

private:
    World();
    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer fpsTimer;

    std::list<WorldObject*> stuff;
};

inline SDL_Renderer* WorldObject::renderer()
{
    return world().getRenderer();
}

inline World& WorldObject::world()
{
    return World::getWorld();
}

class Background : public WorldObject
{
public:
    Background();
    virtual ~Background();
  //  bool gBackground = SDL_LoadBMP("assets/desert.bmp/");
    virtual void tick();


private:
    SDL_Texture* background;
};


#endif

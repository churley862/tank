#ifndef WORLD_HPP__
#define WORLD_HPP__

#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "timer.h"
class World;

class DisplayObject
{
public:
    DisplayObject() : dead(false) {}
    virtual ~DisplayObject() {}
    virtual void tick() {}
    virtual void kill() {
        dead = true;
    }
    virtual bool is_dead()
    {
        return dead;
    }

protected:
    SDL_Renderer* renderer();
    World& world();

    bool dead;
};

class WorldObject : public DisplayObject
{
public :
    virtual bool is_overlap(const WorldObject& wo)
    {
        return SDL_HasIntersection(rect(), wo.rect());
    }
    virtual void collide(WorldObject& wo) {}

    virtual const SDL_Rect* rect() const
    {
        return nullptr;
    }
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
    void addObject(DisplayObject* obj)
    {
        stuff.push_back(obj);
    }

    SDL_Texture* loadTexture(const char* fileName);
    SDL_Renderer* getRenderer()
    {
        return renderer;
    }

private:
    World();
    void checkCollisions();

    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer fpsTimer;

    std::list<DisplayObject*> stuff;
};

inline SDL_Renderer* DisplayObject::renderer()
{
    return world().getRenderer();
}

inline World& DisplayObject::world()
{
    return World::getWorld();
}

class Background : public DisplayObject
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

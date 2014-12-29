#include <iostream>

#include "world.hpp"

using namespace std;

World::World()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    //window = SDL_CreateWindow( "Tanks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN );
    window = SDL_CreateWindow( "Tanks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //screen =  SDL_SetVideoMode( 1024, 768, 32, SDL_SWSURFACE );
}

World::~World()
{
    SDL_Quit();
}

SDL_Texture* World::loadTexture(const char*fileName)
{
    return IMG_LoadTexture(renderer, fileName);
}

 Background :: Background()
{

    background = World::getWorld().loadTexture("assets/Desert.bmp");
    if (background == NULL)
    {
        cout << "Unable to load background image desert";
        cout << SDL_GetError() << endl;

    }

}

Background :: ~Background()
{
    SDL_DestroyTexture(background);
}

void World::run()
{
    
    SDL_Event e;
    bool running = true;

    while (running)
    {
        fpsTimer.reset();
        SDL_PollEvent(&e);

        if (e.type == SDL_QUIT)
          running = false;

        SDL_RenderClear(renderer);
        for (WorldObject* wo : stuff)
        {
           wo->tick();
        }
        SDL_RenderPresent(renderer);
        fpsTimer.waitFor(16);
    }
}

void Background::tick()
{
    SDL_RenderCopy(renderer(),background,0,0);
}
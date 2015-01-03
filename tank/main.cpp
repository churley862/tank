#include "world.hpp"
#include "tank.hpp"
int main (int argc, char* args[])
{

    World& world = World::getWorld();

    world.addObject(new Background());
    world.addObject(new Player1Tank);
    world.addObject(new Player2Tank);

    world.run();



    return 0;
}
//    const Uint8 *state = SDL_GetKeyboardState(NULL);
//    if (state[SDL_SCANCODE_R])
//        {
//            if(!T1alive)
//            {
//                world.addObject(new Player1Tank);
//            }
//        }
//    if (state[SDL_SCANCODE_LSHIFT])
//    {
//        if(!T2alive)
//        {
//            world.addObject(new Player2Tank);
//        }
//    }
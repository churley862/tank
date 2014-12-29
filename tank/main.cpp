#include "world.hpp"
#include "tank.hpp"
int main (int argc, char* args[])
{

    World& world = World::getWorld();

    world.addObject(new Background());
    world.addObject(new Player1Tank);
    world.addObject(new Player2Tank);

    world.run();
    // const uint8 *state = SDL_GetKeyboardState(NULL);


    return 0;
}
//string keyBoard_Event()
//{
//
//}

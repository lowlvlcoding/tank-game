#include "Game.h"
#include <time.h>

int main()
{
    std::srand(std::time(nullptr));


    //game object to run the game
    Game gameobj;

    gameobj.run();

    return 0;
}

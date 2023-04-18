#include "Game.h"


int main()
{
    //Initialize srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game gameobj;

    while (gameobj.getWindowIsOpen())
    {

        //Update
        gameobj.update();

        //Render
        gameobj.render();

    }
    return 0;
}

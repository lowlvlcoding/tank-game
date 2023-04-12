#include "Game.h"


float rectW = 20.0f;
float rectH = 120.0f;

int main()
{

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

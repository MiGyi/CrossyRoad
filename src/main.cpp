#include <iostream>

using namespace std;

#include "./COBJECT/Game.h"

int main() 
{
    Game *game = new Game();
    // Main game loop
    game->run();
    delete game;

    return 0;
}

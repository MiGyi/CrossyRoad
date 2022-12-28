#include <iostream>
#include "raylib.h"

using namespace std;

#include "Helper/Const.h"
#include "COBJECT/Player.h"
#include "COBJECT/Line.h"
#include "COBJECT/Vehicle.h"
#include "COBJECT/Animal.h"
#include "COBJECT/Map.h"
#include "COBJECT/Game.h"
#include "COBJECT/TextureHolder.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Init texture holder
    TextureHolder *textureHolder = new TextureHolder();
    Game *game = new Game(textureHolder);
    // cerr << "Test game constructor" << endl;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (!game->loop()) {
            delete game;
            game = nullptr;

            break;
        }
        
    }

    
    // De-Initialization
    if (game) delete game;
    delete textureHolder;
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

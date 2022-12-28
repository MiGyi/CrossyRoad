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
        float GFT = GetFrameTime(); 
        game->Update(GFT);

        if (game->Collision()) {
            // cerr << "Collision" << endl;
            delete game;
            game = nullptr;
            break;
        }

        // cerr << "Test game collision" << endl;

        BeginDrawing();
            ClearBackground(GRAY);
            game->Draw();
            // cerr << "Test game draw" << endl;
            DrawFPS(0, 0);
        EndDrawing();
        
    }

    
    // De-Initialization
    if (game) delete game;
    delete textureHolder;
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

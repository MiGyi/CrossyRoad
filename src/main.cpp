#include <iostream>
#include "raylib.h"

using namespace std;

#include "Helper/Const.h"
#include "COBJECT/CPeople.h"
#include "COBJECT/CLine.h"
#include "COBJECT/CVehicle.h"
#include "COBJECT/CAnimal.h"
#include "COBJECT/CMap.h"
#include "COBJECT/CGame.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Init player position
    CGame *game = new CGame();
    // cerr << "Test game constructor" << endl;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float GFT = GetFrameTime(); 
        game->Update(GFT);
        // cerr << "Test game update" << endl;

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
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

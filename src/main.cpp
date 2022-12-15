#include <iostream>
#include "raylib.h"

using namespace std;

#include "Const.h"
#include "COBJECT/CPeople.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Init player position
    CPeople *player = new CPeople();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float x = 0, y = 0;
        if (IsKeyDown(KEY_RIGHT)) x += GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_LEFT)) x -= GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_UP)) y -= GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_DOWN)) y += GetFrameTime() * 300.0f;
        player->Update(x, y);

        BeginDrawing();
            ClearBackground(BLACK);
            player->Draw();
            DrawFPS(0, 0);
        EndDrawing();
    }

    
    // De-Initialization
    delete player;
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

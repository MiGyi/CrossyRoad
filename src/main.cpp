#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "raylib.h"

using namespace std;

const int screenWidth = 1400;
const int screenHeight = 800;

void GetTexture(int x, int y, string filepath, Texture2D &Text)
{
    Image temp = LoadImage(filepath.c_str());
    ImageResize(&temp, x, y);
    Text = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    string filepath1 = "../resources/Pictures/Char_mo1.png";
    string filepath2 = "../resources/Pictures/Char_mo2.png";
    Texture2D Char_motion[2];
    GetTexture(100, 100, filepath1, Char_motion[0]);
    GetTexture(100, 100, filepath2, Char_motion[1]);

    // Init player position
    float Char_x = (screenWidth - 100) / 2, Char_y = (screenHeight - 100);
    float timer = 0.0f;
    int motion = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyDown(KEY_RIGHT)) Char_x += GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_LEFT)) Char_x -= GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_UP)) Char_y -= GetFrameTime() * 300.0f;
        if (IsKeyDown(KEY_DOWN)) Char_y += GetFrameTime() * 300.0f;

        Char_y = min(Char_y, (screenHeight - 100.0f));
        if (Char_y < 0) Char_y = screenHeight - 100;
        Char_x = min(Char_x, (screenWidth - 100.0f));
        Char_x = max(Char_x, 0.0f);

        BeginDrawing();
            ClearBackground(BLACK);

            timer += GetFrameTime();
            if (timer > 0.2f) motion = !motion, timer = 0.0f;
            
            DrawTexturePro(Char_motion[motion], { 0, 0, 100, 100 }, { Char_x, Char_y, 100, 100 }, { 0, 0 }, 0, WHITE);

            DrawFPS(0, 0);
        EndDrawing();
    }

    
    // De-Initialization
    for (int i = 0; i < 2; i++) UnloadTexture(Char_motion[i]);
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

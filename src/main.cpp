#include <string>
#include "raylib.h"

using namespace std;

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
    const int screenWidth = 1400;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    string filepath1 = "resources/Pictures/Char_mo1.png";
    string filepath2 = "resources/Pictures/Char_mo2.png";
    Texture2D Char_motion[2];
    GetTexture(100, 100, filepath1, Char_motion[0]);
    GetTexture(100, 100, filepath2, Char_motion[1]);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        

        EndDrawing();
    }

    for (int i = 0; i < 2; i++) UnloadTexture(Char_motion[i]);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

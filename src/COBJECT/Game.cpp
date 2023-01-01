#include "Game.h"

using namespace std;

Game::Game() {
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "CrossyRoad");

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Init texture holder
    TextureHolder::GetInstance();
    menu = new Menu();
}

Game::~Game() {
    if (room) delete room;
    if (menu) delete menu;

    delete TextureHolder::GetInstance();
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

void Game::run() {
    while (!WindowShouldClose()) {// Detect window close button or ESC key
        switch (state) {
            // Update and Draw Room
            case ScreenState::INGAME: {
                updateRoom();
                break;
            }
            // Update and Draw Menu
            case ScreenState::MENU: {
                updateMenu();
                break;
            }
            case ScreenState::NONE: {
            // Exit game
                return;
            }
            default:
                break;
        }
    }
}

void Game::updateRoom() {
    // Check for pause
    if (IsKeyPressed(KEY_SPACE)) {
        room->pauseToggle();
    }

    // Update and check for collision
    float GFT = GetFrameTime();
    if (!room->Update(GFT)) {
        // Delete room and return to menu
        delete room;
        room = nullptr;
        state = ScreenState::MENU;

        return;
    }

    // Draw
    BeginDrawing();
        ClearBackground(GRAY);
        room->Draw();
        DrawFPS(0, 0);
    EndDrawing();
}

void Game::updateMenu() {
    // Update and check for button press
    MenuOptions curPressed = menu->Update();
    if (curPressed == MenuOptions::NEWGAME) {
        // Create new room and start game
        room = new Room();
        state = ScreenState::INGAME;
    }
    else if (curPressed == MenuOptions::EXIT) {
        state = ScreenState::NONE; 
    }

    // } else if (curPressed == MenuOptions::LOADGAME) {
    //     loadGame();

    // Draw
    BeginDrawing();
        ClearBackground(GRAY);
        menu->Draw();
        DrawFPS(0, 0);
    EndDrawing();
}

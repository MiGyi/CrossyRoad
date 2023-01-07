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

    LoadBestScores();
}

Game::~Game() {
    SaveBestScores();

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
            case ScreenState::SCOREBOARD: {
                updateScoreboard();
                break;
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

    // test load and save
    if (IsKeyPressed(KEY_S)) {
        room->save();
    }

    if (IsKeyPressed(KEY_L)) {
        room->load();
    }

    // Update and check for collision
    float GFT = GetFrameTime();
    if (!room->Update(GFT)) {
        // Delete room and return to menu
        UpdateBestScores();

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
    else if (curPressed == MenuOptions::LOADGAME) {
         loadGame();
         state = ScreenState::INGAME;
    }
    else if (curPressed == MenuOptions::SCOREBOARD) {
        state = ScreenState::SCOREBOARD;
    }
    // Draw
    BeginDrawing();
        ClearBackground(GRAY);
        menu->Draw();
        DrawFPS(0, 0);
    EndDrawing();
}

void Game::updateScoreboard() {
    if (IsKeyPressed(KEY_ENTER)) {
        state = ScreenState::MENU;
    }

    BeginDrawing();
        ClearBackground(BLACK);
        int st = 0;
        for (auto it = BestScores.rbegin(); it != BestScores.rend(); ++it) {
            st++;
            DrawText((to_string(st) + ".  " + to_string(*it)).c_str(), 100, st * 70, 16, WHITE);
        }
        DrawText("Press Enter to go back to menu", screenWidth / 2 - MeasureText("Press Enter to go back to menu", 16) / 2, 800, 20, WHITE);
        DrawFPS(0, 0);
    EndDrawing();
}

void Game::saveGame() {
    room->save();
}

void Game::loadGame() {
    if (!room) room = new Room();
    room->load();
}

void Game::UpdateBestScores() {
    BestScores.insert(room->GetScore());
    if ((int)BestScores.size() > 10) BestScores.erase(BestScores.begin());
}

void Game::SaveBestScores() {
    ofstream fout("scores.txt");
    fout << BestScores.size() << '\n';
    for (int x : BestScores) fout << x << ' ';
    fout.close();
}

void Game::LoadBestScores() {
    ifstream fin("scores.txt");
    if (!fin.good()) return;
    int n;
    fin >> n;
    for (int i = 0, x; i < n; ++i) {
        fin >> x;
        BestScores.insert(x);
    }
    fin.close();
}

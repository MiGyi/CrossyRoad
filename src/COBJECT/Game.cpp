#include "Game.h"

using namespace std;

Game::Game() { //default constructor for testing purpose
    room = new Room();
    state = GameState::Running;
}

Game::~Game() {
    delete room;
}

bool Game::update() {
    // check if game is running
    if (state == GameState::Running) {
        float GFT = GetFrameTime(); 
        room->Update(GFT);

        if (room->Collision()) {
            // cerr << "Collision" << endl;
            delete room;
            room = nullptr;
            return false;
        }
    }

    BeginDrawing();
        ClearBackground(GRAY);
        room->Draw();
        // cerr << "Test game draw" << endl;
        DrawFPS(0, 0);
    EndDrawing();

    return true;
}

void Game::pauseToggle() {
    if (state == GameState::Running) {
        state = GameState::Paused;
    } else if (state == GameState::Paused) {
        state = GameState::Running;
    }
}


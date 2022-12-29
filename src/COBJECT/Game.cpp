#include "Game.h"

using namespace std;

Game::Game() { //default constructor for testing purpose
    room = new Room();
}

Game::~Game() {
    delete room;
}

bool Game::loop() {
    float GFT = GetFrameTime(); 
    room->Update(GFT);

    if (room->Collision()) {
        // cerr << "Collision" << endl;
        delete room;
        room = nullptr;
        return false;
    }

    // cerr << "Test game collision" << endl;

    BeginDrawing();
        ClearBackground(GRAY);
        room->Draw();
        // cerr << "Test game draw" << endl;
        DrawFPS(0, 0);
    EndDrawing();

    return true;
}


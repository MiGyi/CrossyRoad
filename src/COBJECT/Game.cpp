#include "Game.h"

using namespace std;

Game::Game() {
    player = new Player();
    map = new Map(this->speed, 9, 6, 6);
}

Game::~Game() {
    delete player;
    delete map;
}

bool Game::Collision() {
    return map->Collision(player->getBoundingBox());
}

void Game::Update(float GFT) {
    bool isOut = player->Update(GFT);
    cerr << isOut << endl;
    if (isOut) { //Player is out of map
        cerr << "Player is out of map" << endl;
        delete map;
        this->speed += 50.0f;
        map = new Map(this->speed, 9, 6, 6); // Create new map with higher speed
        cerr << "Create new map with speed: " << this->speed << endl;
    }
    map->Update(GFT);
}

void Game::Draw() {
    map->Draw();
    player->Draw();
}


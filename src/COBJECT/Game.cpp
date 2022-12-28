#include "Game.h"

using namespace std;

Game::Game() { //default constructor for testing purpose
    player = new Player();
    map = new Map(this->speed, 9, 6, 6);
}

Game::Game(TextureHolder *textureHolder) {
    int Character = 0;
    // Choose character function
    player = new Player(textureHolder, Character);
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
    if (isOut) { //Player is out of map
        delete map;
        this->speed += 50.0f;
        map = new Map(this->speed, 9, 6, 6); // Create new map with higher speed
    }
    map->Update(GFT);
}

void Game::Draw() {
    map->Draw();
    player->Draw();
}


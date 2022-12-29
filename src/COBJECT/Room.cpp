#include "Room.h"

using namespace std;

Room::Room() { //default constructor for testing purpose
    player = new Player();
    map = new Map(this->speed, 9, 6, 6);
}

Room::Room(TextureHolder *textureHolder) {
    int Character = 0;
    // Choose character function
    player = new Player(textureHolder, Character);
    map = new Map(textureHolder, this->speed, 9, 6, 6);
}

Room::~Room() {
    delete player;
    delete map;
}

bool Room::Collision() {
    return map->Collision(player->getBoundingBox());
}

void Room::Update(float GFT) {
    bool isOut = player->Update(GFT);
    if (isOut) { //Player is out of map
        this->speed += 50.0f;
        map->RegenMap(this->speed, 9, 6, 6);
    }
    map->Update(GFT);
}

void Room::Draw() {
    map->Draw();
    player->Draw();
}


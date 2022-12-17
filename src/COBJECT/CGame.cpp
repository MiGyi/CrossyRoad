#include "CGame.h"

using namespace std;

CGame::CGame() {
    player = new CPeople();
    map = new CMap();
}

CGame::~CGame() {
    delete player;
    delete map;
}

bool CGame::Collision() {
    return map->Collision(player->getBoundingBox());
}

void CGame::Update(float GFT) {
    player->Update(GFT);
    map->Update(GFT);
}

void CGame::Draw() {
    map->Draw();
    player->Draw();
}


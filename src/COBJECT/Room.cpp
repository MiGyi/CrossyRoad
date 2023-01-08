#include "Room.h"

using namespace std;

Room::Room() { //default constructor for testing purpose
    // int Character = 0;
    // Choose character function
    player = new Player(GetRandomValue(0, 2));
    map = new Map(this->speed, 9, 6, 6);
    score = new Score();
}

Room::~Room() {
    delete player;
    delete map;
}

bool Room::Collision() {
    return map->Collision(player->getBoundingBox());
}

bool Room::Update(float GFT) {
    if (state == RoomState::Paused) return true;

    bool isOut = player->Update(GFT);
    if (isOut) { //Player is out of map
        this->speed += 50.0f;
        map->RegenMap(this->speed, 9, 6, 6);
    }
    map->Update(GFT);

    score->increase(map->GetScore(player->getBoundingBox()));

    return !Collision();
}

void Room::Draw() {
    map->Draw();
    player->Draw();
    score->Draw();
}

void Room::pauseToggle() {
    if (state == RoomState::Running) {
        state = RoomState::Paused;
    } else if (state == RoomState::Paused) {
        state = RoomState::Running;
    }
}

void Room::save() {
    std::ofstream fout("save.txt");
    score->save(fout);
    fout << speed << '\n';
    player->save(fout);
    map->save(fout);
    fout.close();
}

void Room::load() {
    std::ifstream fin("save.txt");
    score->load(fin);
    fin >> speed;
    player->load(fin);
    map->load(fin);
    fin.close();
    state = RoomState::Paused;
}

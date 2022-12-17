#include "CMap.h"

using namespace std;
 
CMap::CMap() {
    int y = 0;
    int Rand[5] = { 1, 1, 0, 0, 0 }; // 1: safe, 0: unsafe
    shuffle(Rand, Rand + 5, default_random_engine(time(NULL)));
    for (int i = 0; i < 5; i++) {
        int getRand = GetRandomValue(0, 1);
        getRand += getRand;
        Lines.push_back(new CLine(y, Rand[i], 15.0f * (getRand - 1.0f), 5));
        y += LineHeight;
    }
    Lines.push_back(new CLine(y, true, 0, 0)); // safe line
}

bool CMap::Collision(Rectangle Player) {
    for (auto &i : Lines) {
        if (i->Collision(Player)) return true;
    }
    return false;
}

void CMap::Update(float DeltaTime) {

    // cerr << "Check upd map 1" << endl;

    for (auto &i : Lines) {
        i->Update(DeltaTime);
    }

}

void CMap::Draw() {
    for (auto &i : Lines) {
        i->Draw();
    }
}

CMap::~CMap() {
    while (!Lines.empty()) {
        delete Lines.back();
        Lines.pop_back();
    }
}
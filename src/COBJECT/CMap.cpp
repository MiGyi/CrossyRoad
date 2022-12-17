#include "CMap.h"

using namespace std;
 
CMap::CMap() {
    int y = 0;
    int RandLineSafety[NumberOfLine - 1]; // 1: safe, 0: unsafe
    for (int i = 0; i < NumberOfLine - 4; i++) RandLineSafety[i] = 0;
    for (int i = NumberOfLine - 4; i < NumberOfLine - 1; i++) RandLineSafety[i] = 1;
    shuffle(RandLineSafety, RandLineSafety + NumberOfLine - 1, default_random_engine(time(NULL)));
    for (int i = 0; i < NumberOfLine - 1; i++) {
        int getRand = GetRandomValue(0, 1); // 0: Vehicle from right to left, 1: Vehicle from left to right
        int getRandType = GetRandomValue(0, 1); //0: Forest, 1: Road
        getRand += getRand;
        if (getRandType) Lines.push_back(new CRoad(y, RandLineSafety[i], 50.0f * (getRand - 1.0f), 5));
            else Lines.push_back(new CForest(y, RandLineSafety[i], 50.0f * (getRand - 1.0f), 5));
        y += LineHeight;
    }
    Lines.push_back(new CForest(y, true, 0, 0)); // first line is always safe
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
#include "CRoad.h"

using namespace std;

CRoad::CRoad(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

void CRoad::GenerateObject() {
    if (Objects.size() >= MaxObject) return;
    if (speed > 0 && !Objects.empty() && Objects.back()->GetX() < 100) return;
    if (speed < 0 && !Objects.empty() && Objects.back()->GetX() > screenWidth - 200) return;
    int getRand = GetRandomValue(0, 100); 
    if (getRand == 6) Objects.push_back(new CVehicle(y, speed, speed > 0));
};

CRoad::~CRoad() {
    while (!Objects.empty()) {
        delete Objects.back();
        Objects.pop_back();
    }
}

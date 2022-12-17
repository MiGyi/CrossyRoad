#include "CLine.h"

using namespace std;

CLine::CLine(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

void CLine::Update(float DeltaTime) {
    if (isSafe) return;

    if (Objects.size() > 0) {
        if (this->speed > 0 && Objects.back()->GetX() > screenWidth) {
            delete Objects.front();
            Objects.erase(Objects.begin());
        }

        if (this->speed < 0 && Objects.front()->GetX() < -VehicleWidth * 2.0f) {
            delete Objects.front();
            Objects.erase(Objects.begin());
        }

    }

    if (Objects.size() < MaxObject) {
        if (Objects.empty() || (this->speed > 0 && Objects.back()->GetX() > 200.0f) || (this->speed < 0 && Objects.back()->GetX() < screenWidth - 200.0f)) {
            int Rand = GetRandomValue(0, 70);
            if (Rand == 1) {
                Objects.push_back(new CVehicle(y, speed, speed > 0));
            }
        }
    }

    for (auto &i : Objects) {
        i->Update(DeltaTime);
    }
}

void CLine::Draw() {
    DrawRectangleLines(0, y, screenWidth, LineHeight, GREEN);
    //DrawRectangleRec({ 0, y, screenWidth, LineHeight }, GREEN);
    for (auto &i : Objects) {
        i->Draw();
    }
}

bool CLine::Collision(Rectangle Player) {
    if (isSafe) return false;
    for (auto &i : Objects) {
        if (CheckCollisionRecs(Player, i->getBoundingBox())) return true;
    }
    return false;
}

CLine::~CLine() {
    while (!Objects.empty()) {
        delete Objects.back();
        Objects.pop_back();
    }
}
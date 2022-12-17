#include "CLine.h"

using namespace std;

void CLine::Update(float DeltaTime) {
    cerr << "Check upd line 1" << endl;

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

    GenerateObject();

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
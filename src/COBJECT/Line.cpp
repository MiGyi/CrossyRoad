#include "Line.h"

using namespace std;

void Line::Update(float DeltaTime) {

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

void Line::Draw() {
    DrawRectangleLines(0, y, screenWidth, LineHeight, GREEN);
    //DrawRectangleRec({ 0, y, screenWidth, LineHeight }, GREEN);
    for (auto &i : Objects) {
        i->Draw();
    }
}

bool Line::Collision(Rectangle Player) {
    if (isSafe) return false;
    for (auto &i : Objects) {
        if (CheckCollisionRecs(Player, i->getBoundingBox())) return true;
    }
    return false;
}
#include "Road.h"

using namespace std;

Road::Road(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
    this->Trafficlight = new TrafficLight(y);
}

Road::Road(Texture2D *texture, float y, bool isSafe, float speed, int MaxObject) {
    this->texture = texture;
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
    this->Trafficlight = new TrafficLight(y);
}

void Road::Draw() {
    if (texture != nullptr) DrawTexture(*texture, 0, y, WHITE);
        else DrawTexturePro(*texture, { 0, y, LaneWidth, LaneHeight }, {0, y, LaneWidth, LaneHeight}, { 0, 0 }, 0, WHITE);
    for (auto &object : Objects) object->Draw();
    Trafficlight->Draw();
}

void Road::GenerateObject() {
    if (Objects.size() >= MaxObject) return;
    if (speed > 0 && !Objects.empty() && Objects.back()->GetX() < 100) return;
    if (speed < 0 && !Objects.empty() && Objects.back()->GetX() > screenWidth - 200) return;
    int getRand = GetRandomValue(1, 150); 
    if (getRand == 6) {
        int randIndex = GetRandomValue(0, NumberOfVehicle - 1);
        Objects.push_back(new Vehicle(y, speed, speed > 0, randIndex));
    }
}

Road::~Road() {
    ClearObject();
    texture = nullptr;
    delete Trafficlight;
    Trafficlight = nullptr;
}

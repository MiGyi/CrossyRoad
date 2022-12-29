#include "Road.h"

using namespace std;

Road::Road(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

Road::Road(Texture2D *texture, float y, bool isSafe, float speed, int MaxObject) {
    this->texture = texture;
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

void Road::GenerateObject() {
    if (Objects.size() >= MaxObject) return;
    if (speed > 0 && !Objects.empty() && Objects.back()->GetX() < 100) return;
    if (speed < 0 && !Objects.empty() && Objects.back()->GetX() > screenWidth - 200) return;
    int getRand = GetRandomValue(1, 150); 
    if (getRand == 6) Objects.push_back(new Vehicle(y, speed, speed > 0));
    Objects.push_back(new TrafficLight(y));
};

Road::~Road() {
    ClearObject();
    texture = nullptr;
}

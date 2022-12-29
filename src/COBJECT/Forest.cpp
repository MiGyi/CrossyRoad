#include "Forest.h"

using namespace std;

Forest::Forest(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

Forest::Forest(Texture2D *texture, float y, bool isSafe, float speed, int MaxObject) {
    this->texture = texture;
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

void Forest::GenerateObject() {
    if (Objects.size() >= MaxObject) return;
    if (speed > 0 && !Objects.empty() && Objects.back()->GetX() < 100) return;
    if (speed < 0 && !Objects.empty() && Objects.back()->GetX() > screenWidth - 200) return;
    int getRand = GetRandomValue(1, 150); 
    if (getRand == 6) Objects.push_back(new Animal(y, speed, speed > 0));
};

Forest::~Forest() {
    ClearObject();
    texture = nullptr;
}
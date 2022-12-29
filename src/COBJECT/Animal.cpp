#include "Animal.h"

using namespace std;

Animal::Animal(float y, float speed, bool FromLeftToRight) {
    this->x = FromLeftToRight ? -AnimalWidth : screenWidth;
    this->y = y;
    this->speed = speed;
    if (!FromLeftToRight && speed > 0) speed = -speed;
}

void Animal::Update(float DeltaTime) {
    // this->motion_timer += DeltaTime;
    // if (this->motion_timer > 0.2f) this->motion_index++, this->motion_timer = 0.0f;
    // if (this->motion_index >= this->motion.size()) this->motion_index = 0;
    this->x += DeltaTime * this->speed;
}

void Animal::Draw() {
    //DrawTexturePro(motion[motion_index], { 0, 0, AnimalWidth, AnimalWidth }, { x, y, AnimalWidth, AnimalHeight }, { 0, 0 }, 0, WHITE);
    //DrawRectangleRec({ this->x, this->y, AnimalWidth, AnimalHeight }, RED);
    DrawRectangleLines(x, y, AnimalWidth, AnimalHeight, BLUE);
}

Rectangle Animal::getBoundingBox() {
    return { x, y, AnimalWidth, AnimalHeight };
}

Animal::~Animal() {
    motion.clear();
}



#include "CAnimal.h"

using namespace std;

CAnimal::CAnimal(float y, float speed, bool FromLeftToRight) {
    this->x = FromLeftToRight ? 0 : screenWidth;
    this->y = y;
    this->speed = speed;
    if (!FromLeftToRight && speed > 0) speed = -speed;
    move_by_vector(0, 0);
}

void CAnimal::Update(float DeltaTime) {
    this->motion_timer += DeltaTime;
    if (this->motion_timer > 0.2f) this->motion_index++, this->motion_timer = 0.0f;
    if (this->motion_index >= this->motion.size()) this->motion_index = 0;
    move_by_vector(this->speed, 0);
}

bool CAnimal::move_by_vector(float x, float y) {
    this->x += x;
    this->y += y;
    Bounding_box = { this->x, this->y, this->x + AnimalWidth, this->y + AnimalHeight };
}

void CAnimal::Draw() {
    //DrawTexturePro(motion[motion_index], { 0, 0, AnimalWidth, AnimalWidth }, { x, y, AnimalWidth, AnimalHeight }, { 0, 0 }, 0, WHITE);
    DrawRectangleRec(Bounding_box, RED);
}

CAnimal::~CAnimal() {
    while (!motion.empty()) {
        UnloadTexture(motion.back());
        motion.pop_back();
    }
}


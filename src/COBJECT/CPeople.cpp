#include "CPeople.h"

CPeople::CPeople()
{
    x = screenWidth / 2 - 50;
    y = screenHeight - 100;
    isAlive = true;
    std::string filepath1 = "../resources/Pictures/Char_mo1.png";
    std::string filepath2 = "../resources/Pictures/Char_mo2.png";
    GetTexture(100, 100, filepath1, motion[0]);
    GetTexture(100, 100, filepath2, motion[1]);
}

void CPeople::Update(float x, float y) {
    motion_timer += GetFrameTime();
    if (motion_timer > 0.2f) motion_index = !motion_index, motion_timer = 0.0f;
    move_by_vector(x, y);
}

bool CPeople::move_by_vector(float x, float y)
{
    this->x += x;
    this->y += y;
    return FixPosition();
}

bool CPeople::FixPosition() {
    if (x < 0) x = 0;
    if (x > screenWidth - 100) x = screenWidth - 100;
    if (y > screenHeight - 100) y = screenHeight - 100;
    if (y < -50) { y = screenHeight - 50; return 1; } //out of screen
    return 0;
}

void CPeople::Draw() {
    DrawTexturePro(motion[motion_index], { 0, 0, 100, 100 }, { x, y, 100, 100 }, { 0, 0 }, 0, WHITE);
}

CPeople::~CPeople() {
    for (int i = 0; i < 2; i++) UnloadTexture(motion[i]);
}
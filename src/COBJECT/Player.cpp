#include "Player.h"

using namespace std;

Player::Player()
{
    x = (screenWidth - PeopleWidth) / 2;
    y = screenHeight - PeopleHeight;
    isAlive = true;
    std::string filepath1 = "../resources/Pictures/Char_mo1.png";
    std::string filepath2 = "../resources/Pictures/Char_mo2.png";
    Texture2D temp;
    GetTexture(PeopleWidth, PeopleHeight, filepath1, temp);
    motion.push_back(temp);
    GetTexture(PeopleWidth, PeopleHeight, filepath2, temp);
    motion.push_back(temp);
    Bounding_box = { this->x, this->y, this->x + PeopleWidth, this->y + PeopleHeight };
}

bool Player::Update(float DeltaTime) {

    motion_timer += DeltaTime; cerr << "Test player update 0skdhfak1" << endl;
    if (motion_timer > 0.2f) motion_index++, motion_timer = 0.0f; 
    if (motion_index >= motion.size()) motion_index = 0; 

    if (IsKeyDown(KEY_RIGHT)) x += DeltaTime * 300.0f;
    if (IsKeyDown(KEY_LEFT)) x -= DeltaTime * 300.0f;
    if (IsKeyDown(KEY_UP)) y -= DeltaTime * 300.0f;
    if (IsKeyDown(KEY_DOWN)) y += DeltaTime * 300.0f;


    bool isOutOfMap = 0;

    if (x < 0) x = 0;
    if (x > screenWidth - PeopleWidth) x = screenWidth - PeopleWidth;
    if (y > screenHeight - PeopleHeight) y = screenHeight - PeopleHeight;
    if (y < -50) y = screenHeight - 50, isOutOfMap = 1; //out of screen

    Bounding_box = { this->x, this->y, this->x + PeopleWidth, this->y + PeopleHeight };

    return isOutOfMap;
}

Rectangle Player::getBoundingBox() {
    return { x - 20, y - 20, PeopleWidth + 40, PeopleHeight + 20};
}

void Player::Draw() {
    DrawTexturePro(motion[motion_index], { 0, 0, PeopleWidth, PeopleHeight }, { x - 20, y - 20, PeopleWidth + 40, PeopleHeight + 20}, { 0, 0 }, 0, WHITE);
    DrawRectangleLines(x, y, PeopleWidth, PeopleHeight, RED);
}

Player::~Player() {
    while (!motion.empty()) {
        UnloadTexture(motion.back());
        motion.pop_back();
    }
}
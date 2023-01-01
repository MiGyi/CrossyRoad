#include "Player.h"

using namespace std;

Player::Player()
{
    x = (screenWidth - PeopleWidth) / 2;
    y = screenHeight - PeopleHeight;
    isAlive = true;
    
    Bounding_box = { this->x, this->y, PeopleWidth, PeopleHeight };
}

// Player::Player(TextureHolder *TextureHD, int Character)
// {
//     x = (screenWidth - PeopleWidth) / 2;
//     y = screenHeight - PeopleHeight;
//     isAlive = true;
//     Textures = TextureHD->GetCharacter(Character);
//     Bounding_box = { this->x + 10, this->y, PeopleWidth - 20, PeopleHeight};
// }

Player::Player(int Character)
{
    x = (screenWidth - PeopleWidth) / 2;
    y = screenHeight - PeopleHeight;
    isAlive = true;
    Textures = TextureHolder::GetInstance()->GetCharacter(Character);
    Bounding_box = { this->x + 10, this->y, PeopleWidth - 10, PeopleHeight};
}

bool Player::Update(float DeltaTime) {
    
    int motion_direction = -1;
    if (IsKeyDown(KEY_RIGHT)) x += DeltaTime * 300.0f, motion_direction = 2;
    else if (IsKeyDown(KEY_LEFT)) x -= DeltaTime * 300.0f, motion_direction = 1;
    else if (IsKeyDown(KEY_UP)) y -= DeltaTime * 300.0f, motion_direction = 3;
    else if (IsKeyDown(KEY_DOWN)) y += DeltaTime * 300.0f, motion_direction = 0;

    if (motion_direction != -1) {
        motion_timer += DeltaTime;
        if (motion_timer > 0.2f) motion_index++, motion_timer = 0.0f; 
        if (motion_index / 4 != (motion_index - 1) / 4) motion_index -= 4; 
        if (motion_index / 4 != motion_direction) motion_index = motion_direction * 4; //change motion direction (0: down, 1: left, 2: right, 3: up)
    }

    bool isOutOfMap = 0;

    if (x < 0) x = 0;
    if (x > screenWidth - PeopleWidth) x = screenWidth - PeopleWidth;
    if (y > screenHeight - PeopleHeight) y = screenHeight - PeopleHeight;
    if (y < -50) y = screenHeight - 50, isOutOfMap = 1; //out of screen

    Bounding_box = { this->x + 10, this->y, PeopleWidth - 10, PeopleHeight};

    return isOutOfMap;
}

Rectangle Player::getBoundingBox() {
    return Bounding_box;
}

void Player::Draw() {
    DrawTexturePro(*Textures[motion_index], { 0, 0, PeopleWidth, PeopleHeight }, { x - 20, y - 20, PeopleWidth + 40, PeopleHeight + 20}, { 0, 0 }, 0, WHITE);
    DrawRectangleLines(this->x + 10, this->y, PeopleWidth - 20, PeopleHeight, RED);
}

Player::~Player() {
    Textures.clear();
}
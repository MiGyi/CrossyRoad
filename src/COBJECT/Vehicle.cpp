#include "Vehicle.h"

#include <iostream>
using namespace std;

Vehicle::Vehicle(float y, float speed, bool FromLeftToRight) {
    this->x = FromLeftToRight ? -VehicleWidth : screenWidth;
    this->y = y;
    this->speed = speed;
    if (!FromLeftToRight && speed > 0) speed = -speed;
}

void Vehicle::Update(float DeltaTime) {
    // this->motion_timer += DeltaTime;
    // if (this->motion_timer > 0.2f) this->motion_index++, this->motion_timer = 0.0f;
    // if (this->motion_index >= this->motion.size()) this->motion_index = 0;
    this->x += DeltaTime * this->speed;
}

void Vehicle::Draw() {
    //DrawTexturePro(motion[motion_index], { 0, 0, VehicleWidth, VehicleWidth }, { x, y, VehicleWidth, VehicleHeight }, { 0, 0 }, 0, WHITE);
    //DrawRectangleRec({ this->x, this->y, VehicleWidth, VehicleHeight }, RED);
    DrawRectangleLines(x, y, VehicleWidth, VehicleHeight, RED);
}

Rectangle Vehicle::getBoundingBox() {
    return { x, y, VehicleWidth, VehicleHeight };
}

Vehicle::~Vehicle() {
    while (!motion.empty()) {
        UnloadTexture(motion.back());
        motion.pop_back();
    }
}


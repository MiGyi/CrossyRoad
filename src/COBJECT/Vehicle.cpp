#include "Vehicle.h"

#include <iostream>
using namespace std;

Vehicle::Vehicle(float y, float speed, bool FromLeftToRight, int index) {
    this->x = FromLeftToRight ? -VehicleWidth : screenWidth;
    this->y = y;
    this->speed = speed;
    this->direction = FromLeftToRight ? -1 : 1;
    this->index = index;
    if (!FromLeftToRight && speed > 0) speed = -speed;
    this->motion = TextureHolder::GetInstance()->GetVehicle();
}

void Vehicle::Update(float DeltaTime) {
    // this->motion_timer += DeltaTime;
    // if (this->motion_timer > 0.2f) this->motion_index++, this->motion_timer = 0.0f;
    // if (this->motion_index >= this->motion.size()) this->motion_index = 0;
    this->x += DeltaTime * this->speed;
}

void Vehicle::Draw() {
    // DrawTexturePro(*motion[0], { 0, 0, VehicleWidth, VehicleWidth }, { x, y, VehicleWidth, VehicleHeight }, { 0, 0 }, 0, WHITE);
    // DrawTextureV(*motion[2], {x, y}, WHITE);
    DrawTextureRec(*motion[index], {0, 0, VehicleWidth * float(direction), VehicleHeight }, {x, y}, WHITE);
    DrawRectangleLines(x, y, VehicleWidth, VehicleHeight, RED);
}

Rectangle Vehicle::getBoundingBox() {
    return { x, y, VehicleWidth, VehicleHeight };
}

Vehicle::~Vehicle() {
    motion.clear();
}

void Vehicle::save(std::ofstream& fout) {
    fout << "1\n";
    fout << direction << '\n';
    fout << index << '\n';
    Object::save(fout);
}

void Vehicle::load(std::ifstream& fin) {
    fin >> direction;
    fin >> index;
    motion = TextureHolder::GetVehicle();
    Object::load(fin);
}

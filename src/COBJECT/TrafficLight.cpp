#include "TrafficLight.h"

#include <iostream>
using namespace std;

TrafficLight::TrafficLight(TextureHolder *TextureHD, float y) {
    this->x = 0;
    this->y = y;
    this->speed = 0;
    this->motion = TextureHD->GetTrafficLight();
}

void TrafficLight::Update(float DeltaTime) {
    timeCounter++;
    if (timeCounter == GetFPS()) {
        timeCounter = 0;
        // call UpdateTexture() every second
        UpdateTexture();
    }
}

void TrafficLight::UpdateTexture() {
    time++;
    if (time == timeToChange[(int)state]) {
        time = 0;
        state = (TrafficLightState)(((int)state + 1) % 3);
    }
}

void TrafficLight::Draw() {
    DrawTexturePro(*motion[0], { 0, 0, TrafficLightWidth, TrafficLightHeight }, { x, y, TrafficLightWidth, TrafficLightHeight }, { 0, 0 }, 0, WHITE);
    DrawRectangleLines(x, y, TrafficLightWidth, TrafficLightHeight, RED);
}

Rectangle TrafficLight::getBoundingBox() {
    return { x, y, TrafficLightWidth, TrafficLightHeight };
}

TrafficLight::~TrafficLight() {
    motion.clear();
}


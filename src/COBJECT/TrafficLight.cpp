#include "TrafficLight.h"

#include <iostream>
using namespace std;

TrafficLight::TrafficLight(float y) {
    this->x = 0;
    this->y = y;
    this->speed = 0;
    this->motion = TextureHolder::GetInstance()->GetTrafficLight();
}

void TrafficLight::Update(float DeltaTime) {
    deltaTimeCounter += DeltaTime;
    if (deltaTimeCounter >= 1.0f) {
        deltaTimeCounter = 0.0f;
        // call UpdateTexture() every second
        UpdateTexture();
    }
}

void TrafficLight::UpdateTexture() {
    curTime++;
    if (curTime == timeToChange[(int)state]) {
        curTime = 0;
        state = (TrafficLightState)(((int)state + 1) % 3);
    }
}

void TrafficLight::Draw() {
    DrawTexturePro(*motion[(int)state], { 0, 0, TrafficLightWidth, TrafficLightHeight }, { x, y, TrafficLightWidth, TrafficLightHeight }, { 0, 0 }, 0, WHITE);
    DrawRectangleLines(x, y, TrafficLightWidth, TrafficLightHeight, RED);
}

Rectangle TrafficLight::getBoundingBox() {
    return { x, y, TrafficLightWidth, TrafficLightHeight };
}

TrafficLightState TrafficLight::GetState() {
    return state;
}

TrafficLight::~TrafficLight() {
    motion.clear();
}

    
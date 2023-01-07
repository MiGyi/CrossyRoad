#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "TextureHolder.h"
#include "Object.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

enum class TrafficLightState {
    Green,
    Yellow,
    Red
};

class TrafficLight: public Object {
    private:
        const int timeToChange[3] = { 5, 1, 3 };
        TrafficLightState state = TrafficLightState::Green;
        int curTime = 0;
        float deltaTimeCounter = 0.0f;
    public:
        TrafficLight(float y);
        void Update(float DeltaTime);
        void UpdateTexture();
        void Draw();
        Rectangle getBoundingBox();
        TrafficLightState GetState();
        ~TrafficLight();

        void save(std::ofstream& fout);
        void load(std::ifstream& fin);
};

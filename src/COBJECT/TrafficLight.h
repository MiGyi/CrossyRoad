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

enum class TrafficLightState {
    Green,
    Red,
    Yellow
};

class TrafficLight: public Object {
    private:
        const int timeToChange[3] = { 5, 3, 2 };
        TrafficLightState state = TrafficLightState::Green;
        float time = 0;

        int timeCounter = 0;
    public:
        TrafficLight(TextureHolder *TextureHD, float y); 
        void Update(float DeltaTime);
        void UpdateTexture();
        void Draw();
        Rectangle getBoundingBox();
        ~TrafficLight();
};
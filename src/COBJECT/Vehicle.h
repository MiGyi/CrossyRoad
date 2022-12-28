#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "Object.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

class Vehicle: public Object {
    private:

    public:
        Vehicle(float y, float speed, bool FromLeftToRight); 
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~Vehicle();
};
#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "Object.h"
#include "Vehicle.h"
#include "Animal.h"


#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class Line {
    protected:
        float x, y;
        float speed;
        std::vector <Object *> Objects;
        bool isSafe = false;
        int MaxObject;

    public: 
        void Update(float DeltaTime);
        void Draw();
        virtual void GenerateObject() = 0;
        bool Collision(Rectangle Player);
};


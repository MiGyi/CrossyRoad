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
        Texture2D *texture = nullptr;
        float x, y;
        float speed;
        std::vector <Object *> Objects;
        bool isSafe = false;
        int MaxObject;

    public: 
        virtual ~Line() {}
        virtual void Update(float DeltaTime);
        virtual void Draw();
        virtual void GenerateObject() = 0;
        bool Collision(Rectangle Player);
        void ClearObject();
};


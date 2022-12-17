#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "CObject.h"
#include "CVehicle.h"
#include "CAnimal.h"


#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class CLine {
    protected:
        float x, y;
        float speed;
        std::vector <CObject *> Objects;
        bool isSafe = false;
        int MaxObject;

    public: 
        void Update(float DeltaTime);
        void Draw();
        virtual void GenerateObject() = 0;
        bool Collision(Rectangle Player);
};


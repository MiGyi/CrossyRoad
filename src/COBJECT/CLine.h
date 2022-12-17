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
    private:
        float x, y;
        float speed;
        std::vector <CObject *> Objects;
        bool isSafe = false;
        int MaxObject;

    public:
        CLine(float y, bool isSafe, float speed, int MaxObject); 
        void Update(float DeltaTime);
        void Draw();
        bool Collision(Rectangle Player);
        ~CLine();
};
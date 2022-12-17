#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "CObject.h"
#include "CVehicle.h"
#include "CAnimal.h"
#include "CLine.h"
#include "CRoad.h"
#include "CForest.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class CMap {
    private:
        std::vector <CLine *> Lines;
    public:
        CMap();
        bool Collision(Rectangle Player);
        void Update(float DeltaTime);
        void Draw();
        ~CMap();
};
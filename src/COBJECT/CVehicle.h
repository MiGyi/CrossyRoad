#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "CObject.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

class CVehicle: public CObject {
    private:

    public:
        CVehicle(float y, float speed, bool FromLeftToRight); 
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~CVehicle();
};
#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

class CPeople {
    private:
        float x, y;
        bool isAlive;
        std::vector <Texture2D> motion;
        float motion_timer = 0.0f;
        int motion_index = 0;
        Rectangle Bounding_box;
    public:
        CPeople();
        void Update(float DeltaTime);
        bool move_by_vector(float x, float y);
        bool FixPosition();
        Rectangle getBoundingBox();
        void Draw();
        ~CPeople();
};  
#pragma once

#include "raylib.h"
#include "../Const.h"
#include "../TextureHepler.h"

#include <algorithm>
#include <math.h>
#include <string>

class CPeople {
    private:
        float x, y;
        bool isAlive;
        Texture2D motion[2];
        float motion_timer = 0.0f;
        int motion_index = 0;
    public:
        CPeople();
        void Update(float x, float y);
        bool move_by_vector(float x, float y);
        bool FixPosition();
        void Draw();
        ~CPeople();
};  
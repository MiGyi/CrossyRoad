#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "TextureHolder.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

#include <iostream>

class Player {
    private:
        float x, y;
        bool isAlive;
        std::vector <Texture2D *> Textures;
        float motion_timer = 0.0f;
        int motion_index = 0;
        Rectangle Bounding_box;
    public:
        Player();
        Player(int Character);
        // Player(TextureHolder *TextureHD, int Character);
        bool Update(float DeltaTime);
        Rectangle getBoundingBox();
        void Draw();
        ~Player();
};  
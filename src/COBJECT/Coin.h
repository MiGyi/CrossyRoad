#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "TextureHolder.h"
#include "Object.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>


class Coin: public Object {
    public:
        Coin(float x, float y);
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~Coin();

        void save(std::ofstream& fout);
        void load(std::ifstream& fin);
};

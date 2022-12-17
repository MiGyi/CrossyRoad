#pragma once

#include "raylib.h"
#include "CObject.h"
#include "CMap.h"
#include "CPeople.h"

#include <iostream>
#include <vector>

class CGame {
    private:
        CPeople *player;
        CMap *map;

    public:
        CGame();
        ~CGame();
        bool Collision();
        void Update(float GFT);
        void Draw();
};
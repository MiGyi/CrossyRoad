#pragma once

#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"

#include <iostream>
#include <vector>

class Game {
    private:
        Player *player = nullptr;
        Map *map = nullptr;
        int score = 0;
        float speed = 100.0f;

    public:
        Game();
        Game(TextureHolder *textureHolder);
        ~Game();
        bool Collision();
        void Update(float GFT);
        void Draw();
};
#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "SoundHolder.h"
#include "Object.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Coin.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Line {
    protected:
        Texture2D *texture = nullptr;
        float x = 0, y;
        float speed;
        std::vector <Object *> Objects;
        bool isSafe = false;
        int MaxObject;
        std::vector <Coin *> Coins;

    public:
        virtual ~Line() {}
        virtual void Update(float DeltaTime);
        virtual void Draw();
        virtual void GenerateObject() = 0;
        bool Collision(Rectangle Player);
        void ClearObject();

        void GenerateCoin();
        void ClearCoin();
        int GetScore(Rectangle Player);

        virtual void save(std::ofstream& fout);
        virtual void load(std::ifstream& fin);
};


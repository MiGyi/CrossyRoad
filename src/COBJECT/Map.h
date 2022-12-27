#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "Object.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Line.h"
#include "Road.h"
#include "Forest.h"

#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class Map {
    private:
        std::vector <Line *> Lines;
    public:
        Map();
        Map(float Speed, int NumOfLines, int NumOfVehicles, int NumOfAnimals);
        bool Collision(Rectangle Player);
        void Update(float DeltaTime);
        void Draw();
        ~Map();
};
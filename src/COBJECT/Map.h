#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "Object.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Line.h"
#include "Road.h"
#include "Forest.h"
#include "TextureHolder.h"

#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Map {
    private:
        std::vector <Line *> Lines;
        std::vector <Texture2D *> LaneTexture[2];
        int NumOfLanes;
        int NumOfVehicles;
        int NumOfAnimals;
        float speed;
    public:
        Map();
        Map(float speed, int NumOfLanes, int NumOfVehicles, int NumOfAnimals);
        void GenLane();
        bool Collision(Rectangle Player);
        int GetScore(Rectangle Player);
        void Update(float DeltaTime);
        void Draw();
        void RegenMap(float Speed, int NumOfLines, int NumOfVehicles, int NumOfAnimals);
        ~Map();

        void save(std::ofstream& fout);
        void load(std::ifstream& fin);
};

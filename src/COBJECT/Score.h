#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

class Score {
private:
    int score = 0;
public:
    void increase(int x = 1);

    void Draw();

    void save(std::ofstream& fout);

    void load(std::ifstream& fin);

    int GetScore();
};

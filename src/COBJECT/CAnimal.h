#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "CObject.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>



class CAnimal: public CObject {
    private:
        
    public:
        CAnimal(float y, float speed, bool FromLeftToRight); 
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~CAnimal();
};

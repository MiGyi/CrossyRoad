#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHepler.h"
#include "Object.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>



class Animal: public Object {
    private:
        
    public:
        Animal(float y, float speed, bool FromLeftToRight); 
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~Animal();
};

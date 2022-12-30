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



class Animal: public Object {
    private:
        int direction;
        int index;
    public:
        Animal(float y, float speed, bool FromLeftToRight, int index); 
        void Update(float DeltaTime);
        void Draw();
        Rectangle getBoundingBox();
        ~Animal();
};

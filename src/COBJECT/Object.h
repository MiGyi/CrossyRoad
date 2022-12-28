#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

class Object {
    protected:
        float x, y;
        std::vector <Texture2D> motion;
        float motion_timer = 0.0f;
        int motion_index = 0;
        Rectangle Bounding_box;
        float speed;
    public:
        virtual void Update(float DeltaTime) = 0;
        Rectangle GetBoundingBox() { return Bounding_box; }
        virtual void Draw() = 0;
        virtual ~Object() {}
        float GetX() { return x; }
        virtual Rectangle getBoundingBox() = 0;
        bool Collision(Rectangle Player) {
            return CheckCollisionRecs(Player, getBoundingBox());
        }
};
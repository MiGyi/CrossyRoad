#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

class Object {
    protected:
        float x, y;
        std::vector <Texture2D *> motion;
        float motion_timer = 0.0f;
        int motion_index = 0;
        Rectangle Bounding_box;
        float speed = 0;
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

        virtual void save(std::ofstream& fout) {
            fout << x << ' ' << y << '\n';
            fout << motion_timer << '\n';
            fout << motion_index << '\n';
            fout << Bounding_box.x << ' ' << Bounding_box.y << ' ' << Bounding_box.width << ' ' << Bounding_box.height << '\n';
            fout << speed << '\n';
        }

        virtual void load(std::ifstream& fin) {
            fin >> x >> y;
            fin >> motion_timer;
            fin >> motion_index;
            float X, Y, Width, Height;
            fin >> X >> Y >> Width >> Height;
            Bounding_box = {X, Y, Width, Height};
            fin >> speed;
        }
};
